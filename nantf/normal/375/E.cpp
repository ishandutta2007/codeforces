#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=505,mod=998244353;
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
int n,m,x,c[maxn],el,head[maxn],to[maxn*2],nxt[maxn*2],w[maxn*2],sz[maxn],dfn[maxn],cnt,cur,dep[maxn],p[maxn],pre[maxn],f[2][maxn][maxn*2],tmp[maxn][maxn],mn[maxn][maxn];
bool cl[maxn][maxn];
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
void dfs(int u,int F){
	dfn[u]=++cnt;
	dep[u]=dep[F]+1;
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		dfs(v,u);
		sz[u]+=sz[v];
	}
}
void dfs2(int u,int F,int rt,int d){
	if(d>x) return;
	cl[rt][u]=true;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==F) continue;
		dfs2(v,u,rt,d+w[i]);
	}
}
inline bool in(int u,int v){
	return dfn[v]>=dfn[u] && dfn[v]<=dfn[u]+sz[u]-1;
}
inline bool cmp(int x,int y){
	return dep[x]>dep[y];
}
inline int &g(int cur,int u,int v,int i){
//	if(u==7 && v==6 && i==1) printf("at %d %d %d\n",cur,v,i+pre[u]);
	return f[cur][v][i+pre[u]];
}
int main(){
	n=read();x=read();
	FOR(i,1,n) m+=c[i]=read();
	FOR(i,1,n-1){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	dfs(1,0);
	FOR(i,1,n) dfs2(i,0,i,0);
	FOR(i,1,n) p[i]=i;
	sort(p+1,p+n+1,cmp);
	MEM(mn,0x3f);
	FOR(i,1,n){
		int j=i;
		while(j<n && dep[p[i]]==dep[p[j+1]]) j++;
		MEM(f[cur],0x3f);
		FOR(k,i,j){
			int u=p[k];
			if(k!=i) pre[u]=pre[p[k-1]]+sz[p[k-1]]+1;
			g(cur,u,u,1)=1-c[u];
			FOR(v,1,n) if(cl[u][v] && u!=v) g(cur,u,v,0)=0;
			int s=1;
			for(int e=head[u];e;e=nxt[e]){
				int v=to[e];
				if(dep[v]<dep[u]) continue;
				FOR(a,1,n) FOR(x,0,s+sz[v]) tmp[a][x]=1e9;
				FOR(a,1,n) FOR(x,0,s) FOR(y,0,sz[v]){
					tmp[a][x+y]=min(tmp[a][x+y],g(cur,u,a,x)+g(cur^1,v,a,y));
					if(!in(v,a)) tmp[a][x+y]=min(tmp[a][x+y],g(cur,u,a,x)+mn[v][y]);
//					if(u==2 && a==1 && x+y==0) printf("x=%d,y=%d,g1=%d,g2=%d,mn=%d\n",x,y,g(cur,u,a,x),g(cur^1,v,a,y),mn[v][y]);
					//->tmp[a][x+y];(a out of v,b in v)
				}
				s+=sz[v];
				FOR(a,1,n) FOR(x,0,s) g(cur,u,a,x)=tmp[a][x];
			FOR(a,1,n) FOR(x,0,s){
//				if(in(u,a)) mn[u][x]=min(mn[u][x],g(cur,u,a,x));
//				printf("g(%d,%d,%d)=%d\n",u,a,x,g(cur,u,a,x));
			}
			}
//			if(u==6) printf("g(7,6,0)=%d\n",g(cur^1,7,6,0));
			FOR(a,1,n) FOR(x,0,s){
				if(in(u,a)) mn[u][x]=min(mn[u][x],g(cur,u,a,x));
//				printf("g(%d,%d,%d)=%d\n",u,a,x,g(cur,u,a,x));
			}
//			FOR(x,0,s) printf("mn[%d][%d]=%d\n",u,x,mn[u][x]);
		}
		cur^=1;
		i=j;
	}
	printf("%d\n",mn[1][m]>=1e9?-1:mn[1][m]);
}