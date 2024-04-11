#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,a[10000];
void dfs(ll p){
	if(p)a[++n]=p;
	if(p>1000000000)return ;
	dfs(p*10+4);dfs(p*10+7);
}
int main(){
	ll l,r;
	cin>>l>>r;
	dfs(0);
	sort(a+1,a+n+1);
	ll t=1,w=1;
	while(a[t]<l)t++;
	while(a[w]<r)w++;
	if(t==w){
		cout<<(r-l+1)*a[w];return 0;
	}
	ll ans=0;
	for(ll i=t+1;i<w;i++){
		ans=ans+(a[i]-a[i-1])*a[i];
	}
	ans=ans+(a[t]-l+1)*a[t]+(r-a[w-1])*a[w];
	cout<<ans;
	return 0;
}