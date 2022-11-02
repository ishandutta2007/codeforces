#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(ll i=a;i<=b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
ll l[100005];
vector<pair<ll,ll> > p;
ll n;
int main(){
	scanf("%lld",&n);ll x;
	FOR(i,1,n){
		scanf("%lld",&l[i]);
		ll maxi=0,mini=2147483647,last;bool f=1;
		FOR(j,1,l[i]){
			scanf("%lld",&x);
			maxi=max(maxi,x);mini=min(mini,x);
			if(j!=1&&x>last){
				f=0;
			}
			last=x;
		}
		if(f){
			p.PB(MP(maxi,0));p.PB(MP(mini,1));
		}
	}
	sort(ALL(p));
	ll t=0,ans=0;
	for(ll i=0;i<p.size();i++){
		if(p[i].S==0){
			t++;
		}else ans+=t;
	}
	cout<<1ll*n*n-ans;
	RE 0;
}