#include <iostream>
using namespace std;
int main(){
	string s,f="NO";
	
	cin>>s;
	for (int i=0; i<s.size(); i++){
		if (s[i]=='H' or s[i]=='Q' or s[i]=='9'){
			f="YES";
		}
	}
	cout<<f;
}