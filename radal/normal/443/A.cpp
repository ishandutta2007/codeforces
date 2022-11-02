#include <iostream>

using namespace std;
 
bool in(char c,string s){
	for (int i=0; i<s.size(); i++){
		if (s[i]==c){
			return 1;
		}
	}
	return 0;
}

int main(){
	string s="";
	char d;
	while (d!='}'){
		cin>>d;
		if (d!='{' and d!='}' and d!=',' and not(in(d,s))){
			s+=d;
		}
	}
	cout<<s.size();
}