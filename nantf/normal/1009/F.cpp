#include<bits/stdc++.h>
using namespace std;
const int maxn=1000100,mod=998244353;
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,el,head[maxn],to[maxn*2],nxt[maxn*2],len[maxn],fa[maxn],son[maxn],ans[maxn],*f[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs1(int u,int f){
	fa[u]=f;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs1(v,u);
		if(len[v]+1>len[u]) son[u]=v,len[u]=len[v]+1;
	}
}
void dfs2(int u){
	if(son[fa[u]]!=u) f[u]=new int[len[u]+5]();
	if(son[u]){
		f[son[u]]=f[u]+1;
		dfs2(son[u]);
		if(f[u][ans[son[u]]+1]>1) ans[u]=ans[son[u]]+1;
	}
	f[u][0]++;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v);
		FOR(j,0,len[v]){
			f[u][j+1]+=f[v][j];
			if(f[u][j+1]==f[u][ans[u]]) ans[u]=min(ans[u],j+1);
			if(f[u][j+1]>f[u][ans[u]]) ans[u]=j+1;
		}
	}
//	FOR(i,0,len[u]) printf("%d ",f[u][i]);
//	puts("");
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs1(1,0);dfs2(1);
	FOR(i,1,n) if(son[fa[i]]!=i) delete[] f[1];
	FOR(i,1,n) printf("%d\n",ans[i]);
}