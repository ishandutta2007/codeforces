#include<bits/stdc++.h>
using namespace std;
using ll=long long;
inline ll read(){
	ll x=0;
	bool f=0;
	char c=getchar();
	while(!isdigit(c)){
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return f?-x:x;
}
const int maxn=5e5+5;
int n;
vector<pair<int,int>> g[maxn];
int c[maxn],sz[maxn],pre[maxn];
vector<int> s[maxn];
int f[maxn],f2[maxn];
void dfs(int u,int fa){
	if(u!=1){
		pre[u]=s[c[u]].back();
		s[c[u]].push_back(u);
	}
	sz[u]=1;
	for(auto e:g[u]){
		int v=e.first;
		if(v==fa) continue;
		c[v]=e.second;
		dfs(v,u);
		sz[u]+=sz[v];
	}
	if(u!=1){
		f[u]+=sz[u];
		if(pre[u]) f[pre[u]]-=sz[u];
		else f2[c[u]]-=sz[u];
		s[c[u]].pop_back();
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<n;i++){
		int u,v,x;
		u=read();
		v=read();
		x=read();
		g[u].push_back({v,x});
		g[v].push_back({u,x});
	}
	for(int i=1;i<=n;i++){
		s[i].push_back(0);
		f2[i]=n;
	}
	dfs(1,0);
	ll ans=0;
	for(int i=2;i<=n;i++)
		ans+=1ll*f[i]*(pre[i]?f[pre[i]]:f2[c[i]]);
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}