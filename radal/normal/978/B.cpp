#include <iostream>
#include <cmath>
using namespace std;
bool aval(int n){
	int t=1;
	for (int i=2; i<n; i++){
		if (n%i==0){
			return 0;
		}
	}
	return 1;
}
int main(){
	string s;
	int l,t=0,bt=0;
	cin>>l>>s;
	for (int i=0; i<l; i++){
		if (t>2){
			bt+=1;
		}
		if (s[i]=='x'){
			t+=1;
		}
		else{
			t=0;
		}
	}
	if (t>2){
		bt+=1;
	}
	cout<<bt;
}