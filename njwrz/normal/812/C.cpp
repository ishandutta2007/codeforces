#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n,s,a[100005];
ll check(ll p){
	priority_queue <ll
	,vector<ll>,greater<ll> > q;
	for(ll i=1;i<=n;i++){
		q.push(i*p+a[i]);
	}
	ll re=0;
	for(ll i=1;i<=p;i++){
		re+=q.top();
		q.pop();
	}
	return re;
}
int main(){
	cin>>n>>s;
	for(ll i=1;i<=n;i++)cin>>a[i];
	ll l=0,r=n,mid;
	while(r-l>5){
		mid=(r+l)>>1;
		if(check(mid)<=s){
			l=mid;
		}else r=mid;
	}
	for(ll i=r;i>=l;i--){
		if(check(i)<=s){
			cout<<i<<' '<<check(i);
			return 0;
		}
	}
	return 0;
}