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
const int N=2e5+9;
const ll mod=998244353;
vi g[N],nt[N];
vector<pii> nod,fn;
int fa[N][20],dfn[N],in,t[N],p[N],s[N],sz[N],dep[N],id[N],top,stk[N];
pii dp[N];
void dfs(int u){
	dfn[u]=++in;
	sz[u]=1;
	for(auto v:g[u]){
		if(v==fa[u][0])continue;
		fa[v][0]=u;
		dep[v]=dep[u]+1;
		dfs(v);
		sz[u]+=sz[v];
	}
}
int LCA(int u,int v){
	if(dep[u]<dep[v])swap(u,v);
	int d=dep[u]-dep[v];
	per(i,0,20)if(d&(1<<i))u=fa[u][i];
	if(u==v)return u;
	per(i,0,20)if(fa[u][i]!=fa[v][i])u=fa[u][i],v=fa[v][i];
	return fa[u][0];
}
bool chk(int u,int v){
//	cout<<u<<' '<<v<<"???\n";
	return dfn[u]+sz[u]-1>=dfn[v];
}
int dis(int u,int v){
	return dep[u]+dep[v]-2*dep[LCA(u,v)];
}
pii cal(int u,int x){
	int d=dis(u,t[x]);
//	cout<<x<<' '<<s[x]<<"        s\n";
	int cu=d/s[x];
	if(d%s[x])++cu;
	return {cu,x};
}
void work(int u){
	if(!id[u])dp[u]={1e9,0};
	else dp[u]={0,id[u]};
//	cout<<u<<' '<<id[u]<<"      check\n";
	for(auto v:nt[u]){
	//	if(v==10)cout<<u<<"son\n";
		work(v);
	//	cout<<v<<' '<<dp[v].fi<<' '<<dp[v].se<<"               v\n";
		if(dp[v].se)dp[u]=min(dp[u],cal(u,dp[v].se));
	}	
} 
void work2(int u){
	for(auto v:nt[u]){
		dp[v]=min(dp[v],cal(v,dp[u].se));
		work2(v);
	}
}
int main(){
	int n;
	scanf("%d",&n);
	rep(i,1,n){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].pb(v);g[v].pb(u);
	}
	dfs(1);
	LCAFA;
	int q;
	scanf("%d",&q);
	while(q--){
		nod.clear();
		int k,m;
		scanf("%d%d",&k,&m);
		rep(i,1,k+1)scanf("%d%d",&t[i],&s[i]),nod.pb({dfn[t[i]],t[i]}),id[t[i]]=i;
		rep(i,1,m+1)scanf("%d",&p[i]),nod.pb({dfn[p[i]],p[i]});
		sort(all(nod));
		fn=nod;
		rep(i,0,nod.size()-1){
			int lca=LCA(nod[i].se,nod[i+1].se);
			fn.pb({dfn[lca],lca});
		}
		fn.pb({1,1});
		sort(all(fn));
		top=0;
		stk[top++]=fn[0].se;
	//	cout<<(int)fn.size()<<"fnsize\n";
		rep(i,1,fn.size()){
			if(fn[i].se==fn[i-1].se)continue;
			while(!chk(stk[top-1],fn[i].se))--top;
		//	cout<<fn[i].se<<' '<<stk[top-1]<<' '<<top<<' '<<stk[0]<<"what\n";
			nt[stk[top-1]].pb(fn[i].se);
			stk[top++]=fn[i].se;
		}
		work(1);
		work2(1);
		rep(i,1,k+1)id[t[i]]=0;
		rep(i,0,fn.size())nt[fn[i].se].clear();
		rep(i,1,m+1)printf("%d ",dp[p[i]].se);
		printf("\n");
	}
}
/*
10
2 4
7 8
6 3
9 2
6 8
7 1
9 8
9 10
5 4

1

4 7
4 2
9 2
2 2
3 3
2 9 10 7 5 6 3

1 8
8 1
10 2 3 4 1 9 8 5

8 1
9 2
3 1
10 4
8 5
5 3
6 2
4 2
2 4
9

8 5
7 1
9 2
5 1
2 5
10 3
4 4
6 1
1 1
2 8 6 4 10

4 2
6 5
4 3
1 2
3 1
8 1

8 2
7 5
8 3
6 2
5 3
3 5
9 3
10 1
4 1
6 1

3 4
1 2
7 3
8 1
7 1 8 6

2 7
5 5
4 4
7 3 9 8 6 4 2

4 7
4 2
9 2
2 2
3 3
2 9 10 7 5 6 3

6 9
4 4
5 4
9 1
2 3
7 5
10 2
6 3 9 10 4 8 2 5 7

4 8
4 4
6 1
3 3
2 5
3 4 10 8 6 1 9 7
*/