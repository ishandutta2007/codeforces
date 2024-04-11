#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=200020;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
struct edge{
	int u,v,w,id;
	bool operator<(const edge &e)const{
		return w<e.w;
	}
}e[maxn];
int n,c[maxn],el,head[maxn],to[maxn*2],nxt[maxn*2],el2;
int lft[maxn],rig[maxn],dfn[maxn],dfs_clock,ccc,fa[maxn],at[maxn],sss[maxn],al;
bool good[maxn];
ll ans;
inline void add(int u,int v){
	to[++el]=v;nxt[el]=head[u];head[u]=el;
}
int getfa(int x){
	return x==fa[x]?x:fa[x]=getfa(fa[x]);
}
void dfs(int u,int f){
	dfn[u]=++dfs_clock;
	lft[u]=n+1;rig[u]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f) continue;
		dfs(v,u);
		lft[u]=min(lft[u],lft[v]);
		rig[u]=max(rig[u],rig[v]);
	}
	if(!rig[u]) lft[u]=rig[u]=++ccc;
}
int main(){
	n=read();
	FOR(i,1,n) c[i]=read();
	FOR(i,1,n-1){
		int u=read(),v=read();
		add(u,v);add(v,u);
	}
	dfs(1,0);
	FOR(i,1,n) e[++el2]=(edge){lft[i],rig[i]+1,c[i],i};
	sort(e+1,e+el2+1);
	FOR(i,1,ccc) fa[i]=i;
	FOR(i,1,el2){
		int j=i;
		while(j<=el2 && e[j].w==e[i].w) j++;
		j--;
		FOR(k,i,j){
			int u=e[k].u,v=e[k].v;
			u=getfa(u);v=getfa(v);
			if(u!=v) good[e[k].id]=true,al++;
		}
		FOR(k,i,j){
			int u=e[k].u,v=e[k].v;
			u=getfa(u);v=getfa(v);
			if(u!=v) fa[u]=v,ans+=e[k].w;
		}
		i=j;
	}
	cout<<ans<<" "<<al<<endl;
	FOR(i,1,n) if(good[i]) printf("%d ",i);
}