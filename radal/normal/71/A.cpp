#include <iostream>
#include <algorithm>
using namespace std;
string add(int a){
	string s="";
	while (a!=0){
		s+=char(a%10+int('0'));
		a/=10;
	}
	reverse(s.begin(),s.end());
	return s;
}
int main(){
	int t;
	//cout<<add(12);
	cin>>t;
	string j[t];
	for (int i=0; i<t; i++){
		string s;
		cin>>s;
		if (s.size()<=10){
			j[i]=s;
		}
		else{
			j[i]=s[0]+add(s.size()-2)+s[s.size()-1];
		}
	}
	for (int i=0; i<t; i++){
		cout<<j[i]<<endl;
	}
}