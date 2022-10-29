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
using namespace std;
const int N=3e5+9;
const ll mod=998244353;
const int inf=1e9;
int dfn[N],in,U[N],V[N],fa[N][20],dep[N],pos[N],s[N],top,vis[N],ans,dp[N];
vi g[N];
vi VT[N];
bool cmp(int a,int b){
	return dfn[a]<dfn[b];
}
void dfs(int u,int f){
	dfn[u]=++in;
	fa[u][0]=f;
	dep[u]=dep[f]+1; 
	for(auto v:g[u]){
		if(v==f)continue;
		dfs(v,u);
	}
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	per(i,0,20)if(d>>i&1)u=fa[u][i];
	if(u==v)return u;
	per(i,0,20)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
void insert(int u){
	if(top<1){
		s[++top]=u;
		return;
	}
	int lca=LCA(u,s[top]);
	if(lca==s[top]){
		s[++top]=u;
		return;
	}
	while(top>1&&dfn[lca]<=dfn[s[top-1]]){
		VT[s[top-1]].pb(s[top]);
		--top;
	}
	if(lca!=s[top]){
		VT[lca].pb(s[top]);
		s[top]=lca;
	}
	s[++top]=u;
}
void dfs2(int u,int f){
	int cnt=0;
	for(auto v:VT[u]){
		if(v==f)continue;
		dfs2(v,u);
		if(dp[v])++cnt;
		dp[v]=0;
	}
//	cout<<u<<' '<<f<<' '<<cnt<<"cnt\n";
	if(vis[u])ans+=cnt,dp[u]=1;
	else{
		if(cnt==1){
			dp[u]=1;
		}
		else if(cnt>1){
			++ans;
		}
	}
	VT[u].clear();
}
int main(){
	int n,m;
	scanf("%d",&n);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v),g[v].pb(u);
	}
	dfs(1,0);
	rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1];
	scanf("%d",&m);
	while(m--){
		int tot;
		scanf("%d",&tot);
		rep(i,0,tot)scanf("%d",&pos[i]),vis[pos[i]]=1;
		sort(pos,pos+tot,cmp);
		int flag=0;
		rep(i,0,tot){
			if(vis[fa[pos[i]][0]]){
				flag=1;
				break;
			}
		}
		if(flag){
			rep(i,0,tot)vis[pos[i]]=0;
			printf("-1\n");
			continue;
		}
		top=0;
		rep(i,0,tot){
			insert(pos[i]);
			//cout<<pos[i]<<' '<<s[0]<<"check\n";
		}
		while(top>1){
			VT[s[top-1]].pb(s[top]);
			--top;
		}
		ans=0;
		dfs2(s[1],0);
		printf("%d\n",ans);
		rep(i,0,tot)vis[pos[i]]=0;
		dp[s[1]]=0;
	};
}