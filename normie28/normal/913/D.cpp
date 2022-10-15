#include<bits/stdc++.h>
#define data dat
using namespace std;
typedef long long ll;
typedef struct data{
	ll x,y,id;
};
data a[200005];
bool cmp(data a,data b){
	return (a.y<b.y);
}
ll n,k;
ll res[200005];
int check(ll mid){
	ll m = k;
	vector<ll> v;
	for(ll i = 1;i<=n;i++){
		if(a[i].x>=mid&&m>=a[i].y){
			m-=a[i].y;
			v.push_back(a[i].id);
		}
	}
	if(v.size()>=mid){
		for(ll i = 0;i<v.size();i++){
			res[i] = v[i];
		}
		return 1;
	}
	return 0;
}
int main(){
	cin>>n>>k;
	for(ll i = 1;i<=n;i++){
		cin>>a[i].x>>a[i].y;
		a[i].id = i;
	}
	sort(a+1,a+1+n,cmp);
	ll l = 0,r = n;
	ll ans = 0;
	while(l<=r){
		ll mid = (l+r)/2;
		if(check(mid)){
			l = mid+1;
			ans = mid;
		}
		else r = mid-1;
	}
	cout<<ans<<endl<<ans<<endl;
	for (ll i = 0;i<ans;i++) cout<<res[i]<<" ";
}