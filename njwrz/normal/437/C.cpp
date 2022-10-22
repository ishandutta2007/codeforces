#include <bits/stdc++.h>
#define ll long long
#define f first
#define s second
using namespace std;
vector <ll> a[1005];
pair<int,int> t[1005];
bool v[1005];
ll ss[1005];
int main(){
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		t[i].s=i;
		cin>>t[i].f;ss[i]=t[i].f;
	}
	sort(t+1,t+n+1);
	ll l,r;
	for(ll i=0;i<m;i++){
		cin>>l>>r;
		a[l].push_back(r);
		a[r].push_back(l);
	}
	ll ans=0;
	ll di;
	for(ll i=n;i>=1;i--){
		di=t[i].s;
		for(ll j=0;j<a[di].size();j++){
			if(v[a[di][j]]==0)ans+=ss[a[di][j]];
		}
		v[di]=1;
	}
	cout<<ans;
	return 0;
}