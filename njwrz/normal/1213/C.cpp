#include <bits/stdc++.h> 
#define ll long long
using namespace std;
void voi(){
	ll n,m;
	cin>>n>>m;
	ll t=n/m;
	m=m%10;
	ll ans=0,p=0;
	for(int i=1;i<=9;i++){
		p=p+(i*m%10);
	}
	ans=(t/10)*p;
	for(int i=1;i<=t%10;i++){
		ans=ans+(i*m%10);
	}
	cout<<ans<<'\n';
}
int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)voi();
	return 0;
}