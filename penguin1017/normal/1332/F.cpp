#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&(-x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
using namespace std;
const int N=3e5+9;
const ll mod=998244353;
vi e[N];
ll f[N],g[N],h[N];
void dfs(int u,int fa){
	f[u]=1,g[u]=1,h[u]=1;
	for(auto v:e[u]){
		if(v==fa)continue;
		dfs(v,u);
		f[u]=f[u]*(f[v]+g[v]-h[v]+f[v]+g[v])%mod;
		g[u]=g[u]*(f[v]+f[v]+g[v]-h[v])%mod;
		h[u]=h[u]*(f[v]+g[v]-h[v])%mod;
	}
	//cout<<u<<' '<<f[u]<<' '<<g[u]<<' '<<h[u]<<"check\n";
} 
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].pb(v);
		e[v].pb(u);
	}
	dfs(1,0);
	printf("%lld",(f[1]+g[1]-h[1]-1+4*mod)%mod);
}