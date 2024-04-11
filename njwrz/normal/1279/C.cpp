#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[100005],p[100005];
void solve(){
	ll n,k;
	scanf("%lld%lld",&n,&k);
	ll x;
	for(ll i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		p[a[i]]=i;
	}
	ll maxi=0,ans=0;
	for(ll i=1;i<=k;i++){
		scanf("%lld",&x);
		if(p[x]>maxi){
			ans=ans+2*(p[x]-i)+1;
			maxi=p[x];
		}else ans++;
	}
	printf("%lld\n",ans);
}
int main(){
	ll t;
	scanf("%lld",&t);
	while(t--)solve();
	return 0;
}