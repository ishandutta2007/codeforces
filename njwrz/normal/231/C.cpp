#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
	ll a[100005],n,m,maxi=0,maxt=0;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1); 
	ll l=1,s=0,t=1;
	maxi=a[1];maxt=1;
	for(ll i=2;i<=n;i++){
		s=s+t*(a[i]-a[i-1]);t++;
		while(s>m){
			t--;s=s-a[i]+a[l];
			l++;
		}
		if(t>maxt){
			maxt=t;
			maxi=a[i];
		}
	}
	cout<<maxt<<' '<<maxi;
	return 0;
}