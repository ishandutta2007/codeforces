#include<iostream>
#include<string>
using namespace std;
int main(){
	string s;
	int i,d;
	cin>>s;
	for(i=0,d=0;i<s.size();i++){
		if(s[i+1]=='/')d-=2;
		cout<<string(d,' ');
		if(s[i+1]!='/')d+=2;
		for(;;i++){
			cout<<s[i];
			if(s[i]=='>')break;
		}
		cout<<endl;
	}
	return 0;
}