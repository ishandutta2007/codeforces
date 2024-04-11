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
const int maxn=2e5+5;
int n,m;
vector<int> g[maxn];
int fa[maxn],dep[maxn],s[maxn],t[maxn];
void work(int x,int y){
	int u=x;
	while(u!=y){
		if(s[u]) break;
		s[u]=x;
		t[u]=y;
		u=fa[u];
	}
	if(u!=y){
		printf("YES\n");
		if(dep[y]<dep[t[u]]){
			swap(x,s[u]);
			swap(y,t[u]);
		}
		vector<int> vec={u};
		int v=u;
		while(v!=y) vec.push_back(v=fa[v]);
		printf("%d ",(int)vec.size());
		for(int i:vec) printf("%d ",i);
		printf("\n");
		vec={v=x};
		while(v!=u) vec.push_back(v=fa[v]);
		reverse(vec.begin(),vec.end());
		vec.push_back(y);
		printf("%d ",(int)vec.size());
		for(int i:vec) printf("%d ",i);
		printf("\n");
		vec={v=s[u]};
		while(v!=u) vec.push_back(v=fa[v]);
		reverse(vec.begin(),vec.end());
		vector<int> vec2={v=y};
		while(v!=t[u]) vec2.push_back(v=fa[v]);
		reverse(vec2.begin(),vec2.end());
		for(int i:vec2) vec.push_back(i);
		printf("%d ",(int)vec.size());
		for(int i:vec) printf("%d ",i);
		printf("\n");
		exit(0);
	}
}
void dfs(int u){
	dep[u]=dep[fa[u]]+1;
	for(int v:g[u]) if(v!=fa[u]){
		if(dep[v]){
			if(dep[v]<dep[u]) work(u,v);
			continue;
		}
		fa[v]=u;
		dfs(v);
	}
}
int main(){
	#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
	#endif
	n=read();
	m=read();
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();
		v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	for(int i=1;i<=n;i++) if(!dep[i]) dfs(i);
	printf("NO\n");
	#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
	#endif
	return 0;
}