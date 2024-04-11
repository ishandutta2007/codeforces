#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll mod=1,n,m;
	cin>>n>>m;
	while(1){
		ll t=n%mod,s;
		s=(t+1)%mod;
		if(s>m||mod>n){
			mod/=10;
			break;
		}
		if(n/mod<10)break;
		mod*=10;
	}
	ll t=n%mod,s;
	s=(t+1)%mod;
	cout<<n-s;
	return 0;
}