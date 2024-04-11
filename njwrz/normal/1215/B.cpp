#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll a[200005];
ll x,y,ans;
int main(){
	ll t,n;
	cin>>n;
	for(ll i=1;i<=n;i++){
		cin>>t;
		if(t<0)a[i]=-1;else a[i]=1;
	}
	ll p=1;
	x=1;
	for(ll i=1;i<=n;i++){
		p*=a[i];
		if(p>0){
			ans=ans+x;x++;
		}else ans=ans+y,y++;
	}
	cout<<n*(n+1)/2-ans<<' '<<ans;
	return 0;
}