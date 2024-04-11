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
int n,h[maxn];
vector<int> g[maxn];
int mx[maxn];
ll f[maxn];
void dfs(int u,int fa){
	for(int v:g[u]) if(v!=fa){
		dfs(v,u);
		mx[u]=max(mx[u],mx[v]);
		f[u]+=f[v];
	}
	f[u]+=max(h[u]-mx[u],0);
	mx[u]=max(mx[u],h[u]);
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<=n;i++) h[i]=read();
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int r=1;
	for(int i=2;i<=n;i++) if(h[i]>h[r]) r=i;
	dfs(r,0);
	ll mn=h[r],mn2=9e18;
	for(int v:g[r]){
		ll res=max(h[r]-mx[v],0);
		if(res<mn){
			mn2=mn;
			mn=res;
		}
		else mn2=min(mn2,res);
	}
	ll ans=mn+mn2;
	for(int v:g[r]) ans+=f[v];
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}