#pragma GCC optimize(2)
#include <bits/stdc++.h>
#define ll long long
using namespace std;
struct node{
	ll z,y,d;
}a[3002005];
bool cmp(node x,node y){
	return x.d<y.d;
} 
ll n,m;
vector<ll> ans1;
vector<pair<ll,ll> > ans2;
ll fa[2005];
bool check(ll p){
	ll t1=a[p].z;
	ll t2=a[p].y;
	while(fa[t1])t1=fa[t1];
	while(fa[t2])t2=fa[t2];
	return (t1!=t2);
}
void solve(){
	ll t=1;ll ans=0;
	for(ll k=0;k<n;k++){
		while(!check(t))t++;
		ans+=a[t].d;
		ll t1=a[t].z;
		ll t2=a[t].y;
		while(fa[t1])t1=fa[t1];
		while(fa[t2])t2=fa[t2];
		fa[t1]=t2;
		if(a[t].z==0){
			ans1.push_back(a[t].y);
		} else{
			ans2.push_back(make_pair(a[t].z,a[t].y));
		}
	}
	cout<<ans<<'\n';
}
int main(){
	cin>>n;
	ll l[2005],r[2005],dc[2005];
	for(ll i=1;i<=n;i++)cin>>l[i]>>r[i];
	for(ll i=1;i<=n;i++){
		cin>>a[++m].d;
		a[m].z=0;
		a[m].y=i;
	}
	for(ll i=1;i<=n;i++)cin>>dc[i];
	for(ll i=1;i<=n;i++){
		for(ll j=i+1;j<=n;j++){
			a[++m].d=(abs(l[i]-l[j])+abs(r[i]-r[j]))*(dc[i]+dc[j]);
			a[m].z=i;
			a[m].y=j;
		}
	}
	sort(a+1,a+m+1,cmp);
	solve();
	cout<<ans1.size()<<'\n';
	for(ll i=0;i<ans1.size();i++)cout<<ans1[i]<<' ';
	cout<<'\n'<<ans2.size()<<'\n';
	for(ll i=0;i<ans2.size();i++)cout<<ans2[i].first<<' '<<ans2[i].second<<'\n';
	return 0;
}