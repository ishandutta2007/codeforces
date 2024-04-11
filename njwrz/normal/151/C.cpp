#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll a,t,s=0;
	cin>>a;t=a;
	for(ll i=2;i*i<=t;i++){
		while(a%i==0&&s<2){
			a/=i;s++;
		}
	}
	if(s==0||s==2){
		if(s==0){
			cout<<"1\n0";
		}else if(a!=1){
			cout<<"1\n"<<t/a;
		}else cout<<2;
	}else{
		cout<<2;
	}
	return 0;
}