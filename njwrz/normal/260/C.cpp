#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll n,m;
	cin>>n>>m;
	ll a[n+10],mini=1000000000,t=-1;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]<mini){
			mini=a[i];
		}
	}
	t=m;
	while(a[t]!=mini){
		t--;
		if(t==0)t=n;
	}
	for(ll i=1;i<=n;i++)a[i]-=mini;
	if(t<=m){
		for(ll i=t+1;i<=m;i++)a[i]--,a[t]++;
	}else{
		for(ll i=t+1;i<=n;i++)a[i]--,a[t]++;
		for(ll i=1;i<=m;i++)a[i]--,a[t]++;
	}
	a[t]=a[t]+mini*n;
	for(ll i=1;i<=n;i++)cout<<a[i]<<' ';
	return 0;
}