#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(ll n,ll p){
	ll t=1;
	while(t<n)t=(t<<1);
	ll s=0;
	while(n!=0){
		if(n>=t){
			s++;n-=t;
		}
		t=(t>>1);
	}
	return (p>=s);
}
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=30;i++){
		n-=m;
		if(i>n)break;
		if(check(n,i)){
			cout<<i;return 0;
		}
	}
	cout<<-1;
	return 0;
}