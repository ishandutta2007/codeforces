#include <bits/stdc++.h>
using namespace std;
int main(){
	int la;
	string a;
	int s=0;
	cin>>la>>a;
	if(a[0]==')'||a[la-1]=='('){
		cout<<":(";return 0;
	}
	for(int i=0;i<la;i++){
		if(a[i]==')')s--;else s++;
	}
	for(int i=la-1;i>=0;i--){
		if(s>1&&a[i]=='?'){
			s-=2;a[i]=')';
		}
	}
	if(s!=0){
		cout<<":(";return 0;
	}
	s=0;
	for(int i=0;i<la;i++){
		if(a[i]=='?')a[i]='(';
		if(a[i]=='(')s++;else s--;
		if(s==0&&i!=la-1){
			cout<<":(";return 0;
		}
	}
	cout<<a;
	return 0;
}