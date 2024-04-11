#include<bits/stdc++.h>
using namespace std;
const int maxn=10010;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	char ch=getchar();int x=0,f=0;
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,p[maxn],c[maxn],d,k[maxn],with[maxn],el,head[maxn],to[maxn],nxt[maxn],tmp,ans[maxn];
bool vis[maxn],del[maxn];
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
bool dfs(int u){
	if(vis[u]) return false;
	vis[u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(with[v]==-1 || dfs(with[v])){
			with[u]=v;with[v]=u;
			return true;
		}
	}
	return false;
}
int main(){
	MEM(with,-1);
	n=read();m=read();
	FOR(i,1,n) p[i]=read();
	FOR(i,1,n) c[i]=read();
	d=read();
	FOR(i,1,d) del[k[i]=read()]=true;
	FOR(i,1,n) if(!del[i] && p[i]<m) add(p[i],c[i]+m),add(c[i]+m,p[i]);
	ROF(i,d,1){
		MEM(vis,0);
		while(dfs(tmp)) tmp++,MEM(vis,0);
		ans[i]=tmp;
		if(p[k[i]]<m) add(p[k[i]],c[k[i]]+m),add(c[k[i]]+m,p[k[i]]);
	}
	FOR(i,1,d) printf("%d\n",ans[i]);
}