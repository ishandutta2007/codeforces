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
const int maxn=1e3+5;
int n,m,a[maxn];
vector<int> g[maxn],s;
bool vis[maxn];
void dfs(int u){
	vis[u]=1;
	for(int v:g[u]) if(!vis[v]) dfs(v);
	s.push_back(u);
}
const ll mod=998244353;
ll f[maxn];
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	int T=read();
	while(T--){
		n=read();
		m=read();
		for(int i=1;i<=n;i++) a[i]=read();
		for(int i=1;i<=n;i++) g[i].clear();
		for(int i=1;i<=m;i++){
			int u,v;
			u=read();
			v=read();
			g[u].push_back(v);
		}
		for(int i=1;i<=n;i++) vis[i]=0;
		s.clear();
		for(int i=1;i<=n;i++) if(!vis[i]) dfs(i);
		bool flag=0;
		for(int i=0;i<n;i++){
			flag=1;
			for(int j=1;j<=n;j++) flag&=!a[j];
			if(flag){
				printf("%d\n",i);
				break;
			}
			for(int u:s) if(a[u]){
				a[u]--;
				for(int v:g[u]) a[v]++;
			}
		}
		if(flag) continue;
		f[s[0]]=1;
		for(int u:s) if(u!=s[0]){
			f[u]=0;
			for(int v:g[u]) f[u]=(f[u]+f[v])%mod;
		}
		ll ans=n;
		for(int i=1;i<=n;i++) ans=(ans+a[i]%mod*f[i]%mod)%mod;
		printf("%lld\n",ans);
	}
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}