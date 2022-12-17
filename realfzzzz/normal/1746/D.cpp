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
int n,a[maxn],c[maxn];
vector<int> g[maxn];
ll f[maxn],f2[maxn];
void dfs(int u){
	f[u]=1ll*a[u]*c[u];
	int d=g[u].size();
	if(!d){
		f2[u]=f[u]+a[u];
		return;
	}
	vector<ll> vec;
	for(int v:g[u]){
		c[v]=c[u]/d;
		dfs(v);
		f[u]+=f[v];
		vec.push_back(f2[v]-f[v]);
	}
	sort(vec.begin(),vec.end(),greater<int>());
	for(int i=0;i<c[u]%d;i++) f[u]+=vec[i];
	f2[u]=f[u]+a[u]+vec[c[u]%d];
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		c[1]=read();
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=2;i<=n;i++) g[read()].push_back(i);
		for(int i=1;i<=n;i++) a[i]=read();
		dfs(1);
		printf("%lld\n",f[1]);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}