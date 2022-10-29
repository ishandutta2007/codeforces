#include<bits/stdc++.h>
using namespace std;
#define FOR(i,s,t) for(int i=(s),_t=(t); i<=_t; ++i)
#define DOR(i,s,t) for(int i=(s),_t=(t); i>=_t; --i)
typedef double db;
typedef long long ll;
typedef pair<int,int> pii;
#define fi first
#define se second
const int N=3e5+50;
const int Mod=1e9+7;
ll x[N],w[N];
int S[N];
ll mn[N];
int n,q;
ll qry(int x) {
	ll t=4e18;
	for(; x; x^=x&-x) t=min(t,mn[x]);
	return t;
}
void upd(int x,ll v) {
	for(; x<=n; x+=x&-x) mn[x]=min(mn[x],v);
}
vector<pii> Q[N];
ll ans[N];
int main() {
	scanf("%d%d",&n,&q);
	FOR(i,1,n) scanf("%lld%lld",&x[i],&w[i]);
	FOR(i,1,n) mn[i]=4e18;
	FOR(i,1,q) {
		int l,r;
		scanf("%d%d",&l,&r);
		Q[r].push_back(make_pair(l,i));
	}
	int K=0;
	FOR(i,1,n) {
		while(K && w[i]<=w[S[K]]) {
			upd(n-S[K]+1,(x[i]-x[S[K]])*(w[i]+w[S[K]]));
			--K;
		}
		if(K) upd(n-S[K]+1,(x[i]-x[S[K]])*(w[i]+w[S[K]]));
		S[++K]=i;
		for(auto e: Q[i]) ans[e.se]=qry(n-e.fi+1);
	}
	FOR(i,1,q) printf("%lld\n",ans[i]);
	return 0;
}