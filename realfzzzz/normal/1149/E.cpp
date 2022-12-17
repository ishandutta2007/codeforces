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
ll a[maxn];
vector<int> g[maxn];
int f[maxn];
bool vis[maxn],c[maxn];
void dfs(int u){
	if(vis[u]) return;
	vis[u]=1;
	for(int v:g[u]) dfs(v);
	for(int v:g[u]) c[f[v]]=1;
	while(c[f[u]]) f[u]++;
	for(int v:g[u]) c[f[v]]=0;
}
vector<int> vec[maxn];
ll s[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=1;i<=m;i++){
		int u,v;
		u=read();
		v=read();
		g[u].push_back(v);
	}
	for(int i=1;i<=n;i++) dfs(i);
	for(int i=1;i<=n;i++){
		s[f[i]]^=a[i];
		vec[f[i]].push_back(i);
	}
	int x=n;
	while(x>=0&&!s[x]) x--;
	if(x<0){
		printf("LOSE\n");
		return 0;
	}
	int u=0;
	while((a[vec[x][u]]^s[x])>=a[vec[x][u]]) u++;
	a[u=vec[x][u]]^=s[x];
	for(int v:g[u]){
		a[v]^=s[f[v]];
		s[f[v]]=0;
	}
	printf("WIN\n");
	for(int i=1;i<=n;i++) printf("%lld ",a[i]);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}