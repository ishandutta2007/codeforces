#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=2222;
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
int n,a,b,x[maxn],y[maxn],el,head[maxn],to[maxn],nxt[maxn],f[maxn][maxn][2],fpre[maxn][maxn][2],dp[maxn][maxn][2],mn[maxn][2];
int fa[maxn],sz[maxn],son[maxn],dep[maxn],top[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs1(int u,int f){
	dep[u]=dep[fa[u]=f]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		dfs1(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u,int topf){
	top[u]=topf;
	if(son[u]) dfs2(son[u],topf);
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==son[u]) continue;
		dfs2(v,v);
	}
}
int lca(int u,int v){
	while(top[u]!=top[v]){
		if(dep[top[u]]<dep[top[v]]) swap(u,v);
		u=fa[top[u]];
	}
	return dep[u]<dep[v]?u:v; 
}
int main(){
	n=read();
	a=read();
	FOR(i,2,a) add(read(),i);
	dep[0]=-1;
	dfs1(1,0);dfs2(1,1);
	FOR(i,1,n) x[i]=read();
	ROF(i,n,1){
		int s=0;
		FOR(j,i,n){
			if(i==j) s=f[i][j][0]=dep[x[j]];
			else s+=f[i][j][0]=dep[x[j]]-dep[lca(x[j],x[i])];
			fpre[i][j][0]=fpre[i][j-1][0]+(i==j?f[j][j][0]:f[j-1][j][0]);
		}
	}
	el=0;MEM(head,0);MEM(to,0);MEM(nxt,0);MEM(fa,0);MEM(sz,0);MEM(son,0);MEM(dep,0);MEM(top,0);
	b=read();
	FOR(i,2,b) add(read(),i);
	dep[0]=-1;
	dfs1(1,0);dfs2(1,1);
	FOR(i,1,n) y[i]=read();
	ROF(i,n,1){
		int s=0;
		FOR(j,i,n){
			if(i==j) s=f[i][j][1]=dep[y[j]];
			else s+=f[i][j][1]=dep[y[j]]-dep[lca(y[j],y[i])];
			fpre[i][j][1]=fpre[i][j-1][1]+(i==j?f[j][j][1]:f[j-1][j][1]);
		}
	}
	MEM(dp,0x3f);MEM(mn,0x3f);
	dp[0][0][0]=dp[0][0][1]=mn[1][0]=mn[1][1]=0;
	FOR(i,1,n) FOR(j,1,i){
		dp[i][j][0]=fpre[j][i][0]+mn[j][1];
		dp[i][j][1]=fpre[j][i][1]+mn[j][0];
		if(i!=n){
			mn[i+1][0]=min(mn[i+1][0],dp[i][j][0]+(j==1?0:f[j-1][i+1][1]-f[i+1][i+1][1]));
			mn[i+1][1]=min(mn[i+1][1],dp[i][j][1]+(j==1?0:f[j-1][i+1][0]-f[i+1][i+1][0]));
		}
	}
	int ans=1e9;
	FOR(j,1,n) ans=min(ans,min(dp[n][j][0],dp[n][j][1]));
	printf("%d\n",a+b-2-ans);
}