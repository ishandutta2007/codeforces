#include<bits/stdc++.h>

using namespace std;

#define LL long long 
#define N 3000000

const int mod=998244353;
int n,ans,pw[N],x,y,tot,head[N],sz[N],f[N],g[N];
struct edge{int v,nxt;}e[N];

void add(int x,int y){
	e[++tot].v=y; e[tot].nxt=head[x]; head[x]=tot;
}

void dfs(int u,int fa){
	f[u]=1; sz[u]=1;
	for (int i=head[u],v;i;i=e[i].nxt)
		if ((v=e[i].v)!=fa){
			dfs(v,u);
			sz[u]+=sz[v];
			f[u]=f[u]*((LL)g[v]+pw[sz[v]-1])%mod;
		}
	g[u]=(pw[sz[u]-1]-f[u]+mod)%mod;
	ans=(ans+(LL)g[u]*pw[n-sz[u]])%mod;
}

int main(){
	scanf("%d",&n);
	pw[0]=1; for (int i=1;i<=n;++i) pw[i]=pw[i-1]*2%mod;
	for (int i=1;i<n;++i){
		scanf("%d%d",&x,&y);
		add(x,y); add(y,x);
	}
	dfs(1,0);
	printf("%d\n",ans*2%mod);
	
	return 0;
}