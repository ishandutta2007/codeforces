#include<iostream>
using namespace std;
int main(){
	string a;
	cin>>a;
	while(a[a.size()-1]=='/'&&a.size()>0)a=a.substr(0,a.size()-1);
	if(a.size()==0){
		cout<<'/';return 0;
	}
	for(int i=0;i<a.length();i++){
		if(a[i]=='/'){
			cout<<'/';
			while(a[i]=='/')i++;
			i--;
		}else cout<<a[i];
	}
	return 0;
}