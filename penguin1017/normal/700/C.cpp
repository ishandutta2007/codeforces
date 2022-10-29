#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<(b);++i)
#define per(i,a,b) for(int i=(b)-1;i>=(a);--i)
#define pb push_back
#define pii pair<int,int>
#define vi vector<int>
#define fi first
#define se second 
#define ll long long 
using namespace std;
const int N=1e3+9;
const int M=3e4+9;
const ll Inf=1e18;
vector<pii> g[N];
int u[M],v[M],w[M],fa[N],id[N],cnt[N];
bool vis[N];
void dfs(int u,int f){
	vis[u]=1;
	fa[u]=f;
	for(auto w:g[u]){
		int v=w.fi,p=w.se;
		if(v==f||vis[v])continue;
		id[v]=p;
		dfs(v,u);
	}
} 
int fa2[N],id2[N],dep[N];
void dfs2(int u,int f){
	vis[u]=1;
	fa2[u]=f;
	dep[u]=dep[f]+1;
	for(auto w:g[u]){
		int v=w.fi,p=w.se;
		if(v==f||vis[v])continue;
		dfs2(v,u);
		id2[v]=p;
		cnt[u]+=cnt[v];
	}
	for(auto w:g[u]){
		if(dep[w.fi]>dep[u])--cnt[u];
		else ++cnt[u];
	}
}
int main(){
	int n,m;
	scanf("%d%d",&n,&m);
	int s,t;
	scanf("%d%d",&s,&t);
	rep(i,1,m+1){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		g[u[i]].pb({v[i],i});
		g[v[i]].pb({u[i],i});
	}
	dfs(s,0);
	if(!vis[t]){
		puts("0\n0");
		return 0;
	}
	int p=t;
	vi ans;
	ll mini=Inf;
	while(p!=s){
		rep(i,1,n+1)g[i].clear(),vis[i]=0,cnt[i]=0;
		ll sum=w[id[p]];
		vi vec;
		vec.pb(id[p]);
		rep(i,1,m+1){
			if(i==id[p]||u[i]==v[i])continue;
			g[u[i]].pb({v[i],i});
			g[v[i]].pb({u[i],i});
		}
		dfs2(s,0);
		if(!vis[t]){
			if(sum<mini){
				mini=sum;
				ans=vec;
			}
		}
		else{
			int pp=t;
			ll val=Inf,x=0;
			while(pp!=s){
				if(cnt[pp]==1&&w[id2[pp]]<val){
					val=w[id2[pp]];
					x=id2[pp];
				}
				pp=fa2[pp];
			}
			if(x&&val+sum<mini){
				mini=val+sum;
				vec.pb(x);
				ans=vec;
			}
		}
		p=fa[p];
	}
	if(mini==Inf){
		puts("-1");
		return 0;
	}
	printf("%lld\n%d\n",mini,(int)ans.size());
	for(auto v:ans)printf("%d ",v);
}