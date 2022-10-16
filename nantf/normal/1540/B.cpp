#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444,mod=1000000007,inv2=(mod+1)/2;
#define fi first
#define se second
#define MP make_pair
#define PB push_back
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline ll read(){
	char ch=getchar();ll x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
inline int qmo(int x){return x+(x>>31?mod:0);}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
int n,el,head[maxn],to[maxn],nxt[maxn],f[maxn][maxn],dfn[maxn],cnt,id[maxn],sz[maxn],lca[maxn][maxn],dep[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
} 
void dfs(int u,int F){
	dep[u]=dep[F]+1;
	dfn[u]=++cnt;
	id[cnt]=u;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		dfs(v,u);
		FOR(j,dfn[u],dfn[u]+sz[u]-1) FOR(k,dfn[v],dfn[v]+sz[v]-1) lca[id[j]][id[k]]=lca[id[k]][id[j]]=u;
		sz[u]+=sz[v];
	}
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	FOR(i,1,n) f[0][i]=1;
	FOR(i,1,n) FOR(j,1,n) f[i][j]=1ll*inv2*(f[i-1][j]+f[i][j-1])%mod;
	int ans=0,invn=qpow(n,mod-2);
	FOR(i,1,n){
		cnt=0;
		dfs(i,0);
		FOR(j,1,n) FOR(k,1,j-1){
			int l=lca[j][k];
			int a=dep[j]-dep[l],b=dep[k]-dep[l];
			ans=(ans+1ll*f[a][b]*invn)%mod;
		}
	}
	printf("%d\n",ans);
}