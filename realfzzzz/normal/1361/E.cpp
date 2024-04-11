#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
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
mt19937 rnd(time(0));
const int maxn=1e5+5;
int n,m;
vector<int> g[maxn];
int fa[maxn],dep[maxn];
bool b[maxn];
bool dfs1(int u){
	dep[u]=dep[fa[u]]+1;
	b[u]=1;
	for(int v:g[u]){
		if(dep[v]){
			if(!b[v]) return 0;
			continue;
		}
		fa[v]=u;
		if(!dfs1(v)) return 0;
	}
	b[u]=0;
	return 1;
}
int mn[maxn],mn2[maxn];
void dfs2(int u){
	auto upd=[u](int x){
		if(!mn[u]||dep[x]<dep[mn[u]]){
			mn2[u]=mn[u];
			mn[u]=x;
		}
		else if(!mn2[u]||dep[x]<dep[mn2[u]]) mn2[u]=x;
	};
	for(int v:g[u]){
		if(dep[v]<dep[u]){
			upd(v);
			continue;
		}
		dfs2(v);
		if(mn[v]) upd(mn[v]);
		if(mn2[v]) upd(mn2[v]);
	}
}
bool f[maxn];
void dfs3(int u){
	f[u]=!fa[u]||(mn[u]&&dep[mn[u]]<dep[u]&&(!mn2[u]||dep[mn2[u]]>=dep[u])&&f[mn[u]]);
	for(int v:g[u]) if(dep[v]>dep[u]) dfs3(v);
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) vector<int>().swap(g[i]);
		for(int i=1;i<=m;i++){
			int u,v;
			u=read();
			v=read();
			g[u].push_back(v);
		}
		int r=0;
		for(int t=0;t<100;t++){
			r=rnd()%n+1;
			fa[r]=0;
			for(int i=1;i<=n;i++) dep[i]=b[i]=0;
			if(dfs1(r)) break;
			r=0;
		}
		if(!r){
			printf("-1\n");
			continue;
		}
		for(int i=1;i<=n;i++) mn[i]=mn2[i]=0;
		dfs2(r);
		dfs3(r);
		int cnt=0;
		for(int i=1;i<=n;i++) cnt+=f[i];
		if(cnt*5>=n){
			for(int i=1;i<=n;i++) if(f[i]) printf("%d ",i);
			printf("\n");
		}
		else printf("-1\n");
	}
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}