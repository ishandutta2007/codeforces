#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define ll long long
#define lb(x) ((x)&-(x))
#define pii pair<int,int>
#define vi vector<int>
#define pb push_back
#define fi first
#define se second
#define de(x) cout<<#x<<" x"<<endl
#define LCAFA rep(i,1,20)rep(j,1,n+1)fa[j][i]=fa[fa[j][i-1]][i-1]
#define all(x) x.begin(),x.end()
#define ls(x) x<<1
#define rs(x) x<<1|1
#define pr(x) {for(auto v:x)cout<<v<<' ';cout<<#x<<endl;}
using namespace std;
const int N=1e6+9;
const ll mod=998244353;
const ll Inf=1e18;
vi g[N],e[N],G2[N];
vector<pii> G[N];
int a[N],color[N],ok,color2[N];
bool vis[N];
vi q;
void dfs(int u,int f,int c){
	color[u]=c;
	for(auto v:e[u]){
		if(color[v]){
			if(color[u]==color[v])ok=1;
			continue;		
		}
		dfs(v,u,c^1);
	}
}
void dfs2(int u,int f,int c){
	color2[u]=c;
	for(auto v:G2[u]){
		if(color2[v]){
			if(color2[u]==color2[v])ok=1;
			continue;		
		}
		dfs2(v,u,c^1);
	}
}
map<pii,int> id;
int cnt;
int main(){
	int n,m,k;
	scanf("%d%d%d",&n,&m,&k);
	rep(i,1,n+1)scanf("%d",&a[i]);
	rep(i,0,m){
		int u,v;
		scanf("%d%d",&u,&v);
		if(a[u]==a[v]){
			e[u].pb(v);e[v].pb(u);
		}
		else{
			g[u].pb(v),g[v].pb(u);
			if(a[u]>a[v])swap(u,v);
			if(!id.count({a[u],a[v]}))id[{a[u],a[v]}]=++cnt;
			int _=id[{a[u],a[v]}];
			G[_].pb({u,v});
		}
	}
	ll sum=0,ans=0;
	int cc=0;
	rep(i,1,n+1){
		if(color[i])continue;
		cc+=2;
		ok=0;
		dfs(i,0,cc);
	//	cout<<ok<<' '<<i<<' '<<a[i]<<"check\n";
		if(ok)vis[a[i]]=1,++sum;
	}
	ans=(k-sum-1)*(k-sum)/2;
//	cout<<ans<<"ans\n";
	for(auto w:id){
		int cu=w.fi.fi,cv=w.fi.se,tp=w.se;
		if(vis[cu]||vis[cv])continue;
	//	cout<<cu<<' '<<cv<<"check\n";
		for(auto x:G[tp]){
			int u=color[x.fi],v=color[x.se];
		//	cout<<x.fi<<' '<<x.se<<' '<<u<<' '<<v<<"??\n";
			q.pb(u);q.pb(v);q.pb(u^1);q.pb(v^1);
			G2[u].pb(v);G2[v].pb(u);
			G2[u].pb(u^1),G2[u^1].pb(u);
			G2[v].pb(v^1),G2[v^1].pb(v);
		}
		ok=0;
		for(auto u:q)if(!color2[u])dfs2(u,0,2);
	//	cout<<ok<<' '<<"      check\n";
		if(ok)--ans;
		for(auto u:q){
			G2[u].clear();
			color2[u]=0;
		}
		q.clear();
	}
	printf("%lld\n",ans);
}