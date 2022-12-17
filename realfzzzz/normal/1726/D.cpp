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
const int maxn=2e5+5;
int n,m;
vector<pair<int,int>> g[maxn];
int fa[maxn],fa2[maxn],dep[maxn];
vector<vector<int>> e2;
void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	for(auto e:g[u]){
		int v=e.first;
		if(v==fa[u]) continue;
		if(dep[v]){
			if(dep[v]<dep[u])
				e2.push_back({u,v,e.second});
			continue;
		}
		fa[v]=u;
		fa2[v]=e.second;
		dfs(v);
	}
}
bool ans[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=m;i++){
			int u,v;
			u=read();
			v=read();
			g[u].push_back({v,i});
			g[v].push_back({u,i});
		}
		for(int i=1;i<=n;i++) dep[i]=0;
		e2.clear();
		dfs(1);
		sort(e2.begin(),e2.end(),[](auto a,auto b){
			if(dep[a[0]]!=dep[b[0]]) return dep[a[0]]<dep[b[0]];
			return dep[a[1]]<dep[b[1]];
		});
		for(int i=1;i<=m;i++) ans[i]=0;
		for(auto e:e2) ans[e[2]]=1;
		if(m==n+2&&e2[1][0]==e2[2][0]&&e2[0][0]==e2[2][1]&&e2[0][1]==e2[1][1]){
			ans[e2[0][2]]=0;
			ans[fa2[e2[0][0]]]=1;
		}
		for(int i=1;i<=m;i++) printf("%d",ans[i]);
		printf("\n");
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}