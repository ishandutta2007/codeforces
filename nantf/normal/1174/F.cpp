#include<bits/stdc++.h>
using namespace std;
const int maxn=200020;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,head[maxn],el,to[maxn*2],nxt[maxn*2];
int dep[maxn],fa[maxn],sz[maxn],son[maxn],bot[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
void dfs(int u,int f){
	dep[u]=dep[fa[u]=f]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		sz[u]+=sz[v];
		if(sz[v]>sz[son[u]]) son[u]=v;
	}
}
void dfs2(int u){
	if(son[u]) dfs2(son[u]),bot[u]=bot[son[u]];
	else bot[u]=u;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==fa[u] || v==son[u]) continue;
		dfs2(v);
	}
}
inline int qd(int u){
	printf("d %d\n",u);
	fflush(stdout);
	return read();
}
inline int qs(int u){
	printf("s %d\n",u);
	fflush(stdout);
	return read();
}
inline void ans(int u){
	printf("! %d\n",u);
	fflush(stdout);
	exit(0);
}
int main(){
	n=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);dfs2(1);
	int xd=qd(1),u=1;
	if(!xd) ans(1);
	while(true){
		int v=bot[u],ld=(dep[v]+xd-qd(v))>>1;
		while(dep[u]<=ld) u=son[u];
		if(xd==ld) ans(u);
		u=qs(u);
	}
}