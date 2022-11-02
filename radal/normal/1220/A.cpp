#include <iostream>
using namespace std;
int count(char a,string b){
	int t=0;
	for (int i=0; i<b.size(); i++){
		if (b[i]==a){
			t+=1;
		}
	}
	return t;
}
int main(){
	int n,t0,t1;
	string a;
	cin>>n>>a;
	t1=count('n',a);
	t0=n-t1*3;
	t0/=4;
	for (int i=0; i<t1; i++){
		cout<<1<<' ';
	}
	for (int i=0; i<t0; i++){
		cout<<0<<' ';
	}
}