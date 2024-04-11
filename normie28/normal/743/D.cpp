#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
const int mod=1e9+7;
vector<int>g[maxn];
ll sum[maxn];
int l[maxn],r[maxn],b[maxn],nTime=0;
int N;
int a[maxn];
ll f[maxn];
void dfs (int u=1,int p=-1){
	l[u]=++nTime;
	b[nTime]=u;
	sum[u]=a[u];
	for (int v:g[u]){
		if (v!=p){
			dfs (v,u);
			sum[u]+=sum[v];
		}
	}
	r[u]=nTime;
}
signed main(void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	
	cin >>N;
	for (int i=1;i<=N;++i) cin >>a[i];
	for (int i=1,u,v;i<N;++i){
		cin >>u>>v;
		g[u].pb(v), g[v].pb(u);
	}
	dfs();
	ll ans=-1e15;
	ll res=-1e15;
	for (int i=N;i>=1;--i){
		res=max(res,sum[b[i]]);
		f[i]=res;
	}
	for (int i=1;i<=N;++i){
		if (r[b[i]]<N) ans=max(ans,sum[b[i]]+f[r[b[i]]+1]);
	}
	if (ans==-1e15){
		cout <<"Impossible";
	}
	else cout<<ans;
}