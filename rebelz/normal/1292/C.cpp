#include<bits/stdc++.h>

#define pb push_back
#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n,ncnt;
int dfn[3005],siz[3005],f[3005],lca[3005][3005],dep[3005],to[3005][3005],rnk[3005];
ll d[3005][3005];
vector<int> adj[3005];

void dfs(int u,int fa){
	dfn[u]=++ncnt,rnk[ncnt]=u,siz[u]=1;
	for(auto v:adj[u]){
		if(v==fa) continue;
		dep[v]=dep[u]+1,f[v]=u;
		dfs(v,u);
		siz[u]+=siz[v];
	}
}

void dfs2(int u,int fa,int x,int t){
	to[t][u]=x;
	for(auto v:adj[u]){
		if(v==fa) continue;
		if(u==t) dfs2(v,u,v,t);
		else dfs2(v,u,x,t);
	}
}

int dist(int x,int y){return dep[x]+dep[y]-2*dep[lca[x][y]];}

ll dp(int x,int y){
	if(adj[x].size()==1&&adj[y].size()==1&&x!=y) return 0;
	if(d[x][y]) return d[x][y];
	if(d[y][x]) return d[y][x];
	for(auto v:adj[x]){
		if(dist(v,y)<dist(x,y)) continue;
		if(v==f[x]) chkmax(d[x][y],dp(v,y)+siz[y]*(n-siz[x]));
		else if(lca[x][y]==y) chkmax(d[x][y],dp(v,y)+siz[v]*(n-siz[to[y][v]]));
		else chkmax(d[x][y],dp(v,y)+siz[v]*siz[y]);
	}
	for(auto v:adj[y]){
		if(dist(v,x)<dist(x,y)) continue;
		if(v==f[y]) chkmax(d[x][y],dp(v,x)+siz[x]*(n-siz[y]));
		else if(lca[x][y]==x) chkmax(d[x][y],dp(v,x)+siz[v]*(n-siz[to[x][v]]));
		else chkmax(d[x][y],dp(v,x)+siz[v]*siz[x]);
	}
	return d[x][y];
}

int main(){
	n=readint();
	int x,y;
	for(int i=1;i<n;i++){
		x=readint(); y=readint();
		adj[x].push_back(y),adj[y].push_back(x);
	}
	dep[1]=1; dfs(1,-1);
	for(int i=1;i<=n;i++) dfs2(i,-1,i,i);
	for(int i=1;i<=n;i++){
		lca[i][i]=i;
		for(auto v:adj[i]){
			if(dfn[v]<dfn[i]) continue;
			for(int j=dfn[i];j<dfn[v];j++) for(int k=dfn[v];k<=dfn[v]+siz[v]-1;k++) lca[rnk[j]][rnk[k]]=lca[rnk[k]][rnk[j]]=i;
		}
	}
	ll ans=0;
	for(int i=1;i<=n;i++) chkmax(ans,dp(i,i));
	printf("%lld\n",ans);
	return 0;
}