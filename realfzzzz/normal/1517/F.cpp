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
const int maxn=300+5;
int n;
vector<int> g[maxn];
int k,sz[maxn];
const ll mod=998244353,inv2=499122177;
inline void add(ll& x,ll y){
	x=(x+y)%mod;
}
ll f[maxn][2][maxn],tmp[2][maxn];
void dfs(int u,int fa){
	sz[u]=1;
	f[u][0][0]=f[u][1][0]=1;
	for(int v:g[u]) if(v!=fa){
		dfs(v,u);
		memset(tmp,0,sizeof(tmp));
		for(int i=0;i<sz[u];i++) for(int j=0;j<sz[v];j++){
			add(tmp[0][max(i,j+1)],f[u][0][i]*f[v][0][j]%mod);
			if(i+j+1<=k){
				add(tmp[1][j+1],f[u][0][i]*f[v][1][j]%mod);
				add(tmp[1][i],f[u][1][i]*f[v][0][j]%mod);
			}
			else{
				add(tmp[0][i],f[u][0][i]*f[v][1][j]%mod);
				add(tmp[0][j+1],f[u][1][i]*f[v][0][j]%mod);
			}
			add(tmp[1][min(i,j+1)],f[u][1][i]*f[v][1][j]%mod);
		}
		sz[u]+=sz[v];
		for(int i=0;i<sz[u];i++){
			f[u][0][i]=tmp[0][i];
			f[u][1][i]=tmp[1][i];
		}
	}
}
int main(){
#ifdef LOCAL
	freopen("in.txt","r",stdin);
	freopen("out.txt","w",stdout);
#endif
	n=read();
	for(int i=1;i<n;i++){
		int u,v;
		u=read();
		v=read();
		g[u].push_back(v);
		g[v].push_back(u);
	}
	ll ans=n-1;
	for(int i=1;i<=n;i++) ans=ans*2%mod;
	for(k=1;k<n;k++){
		dfs(1,0);
		for(int i=0;i<n;i++) ans=(ans-f[1][1][i]+mod)%mod;
	}
	for(int i=1;i<=n;i++) ans=ans*inv2%mod;
	printf("%lld\n",ans);
#ifdef LOCAL
	fprintf(stderr,"%f\n",1.0*clock()/CLOCKS_PER_SEC);
#endif
	return 0;
}