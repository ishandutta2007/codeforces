#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define vi vector<int>
#define pb push_back
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=3e3+5;
vi g[N];
int fa[N][N],sz[N][N];
ll d[N][N];
vector<pair<int,pii>> v;
void dfs(int u,int f,int rt){
	d[rt][u]=d[rt][f]+1;
	sz[rt][u]=1;
	fa[rt][u]=f;
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u,rt);
		sz[rt][u]+=sz[rt][v];
	}
}
int main()
{
	int n;
	ll ans=0;
	scanf("%d",&n);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);
		g[v].pb(u);
	}
	rep(i,1,n+1)dfs(i,0,i);
	rep(i,1,n+1)rep(j,i+1,n+1)v.pb({d[i][j],{i,j}});
	sort(v.begin(),v.end());
	rep(i,1,n+1)d[i][i]=0;
	rep(i,0,v.size()){
		int u=v[i].se.fi,w=v[i].se.se;
	//	cout<<u<<' '<<v;
		d[w][u]=d[u][w]=max(d[u][fa[u][w]],d[w][fa[w][u]])+sz[w][u]*sz[u][w];
		ans=max(ans,d[u][w]); 
	}
	printf("%lld",ans);
}