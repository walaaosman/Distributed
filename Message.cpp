#include "Message.h"
#include <iostream>
#include <string>
#include <cstring>



Message::Message(int operation,MessageType type, string p_message, size_t p_message_size,int p_rpc_id){
	this->message_type = type;
	this->rpc_id = p_rpc_id;
	this->operation = operation;
	this->message_size = p_message_size;
	this->message = p_message;
}


Message::Message(string serialized){
		stringstream ss (serialized);
		string t;
		ss >> t;
		message_type = MessageType(stoi(t));
		ss >> t;
		rpc_id = stoi(t);
		ss >> t;
		operation = stoi(t);
		ss >> t;
		message_size = stoi(t);
		message = "";
		char temp;
		for (int i = -1; i<message_size; i++){
			ss.get(temp);
			if(i != -1) message+=temp;
		}
}

string Message::marshal (){
	string serialized = "";
	serialized+= (to_string(int(message_type)) + ' ');
	serialized+= (to_string(rpc_id) + ' ');
	serialized+= (to_string(operation) + ' ');
	serialized+= (to_string(message_size) + ' ');
	string data = "";
	for (int i = 0; i < message_size; i++){
		data+=message[i];
	}
	serialized+= data;
	return serialized;
}

int Message::getOperation (){

	return operation;
}

int Message::getRPCId(){

	return rpc_id;
}

string Message::getMessage(){

	return message;
}
size_t Message::getMessageSize(){

	return message_size;
}
MessageType Message::getMessageType(){

	return message_type;
}
void Message::setOperation (int _operation){

	this->operation = _operation;
}
void Meassage::setMessage (string message, size_t message_size){

	this->message = message;
	this->message_size = message_size;
}
void Message::setMessageType (MessageType message_type){

	this->message_type = message_type;
}
Message::~Message();
