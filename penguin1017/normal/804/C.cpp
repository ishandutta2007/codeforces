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
using namespace std;
const int N=2e6+9;
const ll mod=998244353;
vi g[N],ice[N];
int color[N],vis[N],s[N];
void dfs(int u,int fa){
	int sz=ice[u].size();
	rep(i,1,sz+1)vis[i]=0;
	for(auto v:ice[u])vis[color[v]]=1;
	int id=1;
	for(auto v:ice[u]){
		if(!color[v]){
			while(vis[id])++id;
			color[v]=id;
			vis[id]=1;
		}
	}
	for(auto v:g[u]){
		if(v==fa)continue;
		dfs(v,u);
	}
}
int main(){
	int n,m,ans=1;
	scanf("%d%d",&n,&m);
	rep(i,1,n+1){
		scanf("%d",&s[i]);
		ans=max(ans,s[i]);
		while(s[i]--){
			int x;
			scanf("%d",&x);
			ice[i].pb(x);
		}
	}
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1,-1);
	printf("%d\n",ans);
	rep(i,1,m+1)if(!color[i])color[i]=1;
	rep(i,1,m+1)printf("%d ",color[i]);
}