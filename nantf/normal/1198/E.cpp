#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=555,maxm=255555;
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
inline int read(){
    int x=0,f=0;char ch=getchar();
    while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
    while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
    return f?-x:x;
}
int n,xl[maxn],yl[maxn],xr[maxn],yr[maxn],xtmp[maxn],ytmp[maxn],xsz,ysz;
int s,t,el=1,head[maxn],cur[maxn],to[maxm],nxt[maxm],flow[maxm];
int ans,q[maxn],h,r,dis[maxn];
inline void add(int u,int v,int f){
//	printf("add(%d,%d,%d)\n",u,v,f);
	to[++el]=v;nxt[el]=head[u];head[u]=el;flow[el]=f;
	to[++el]=u;nxt[el]=head[v];head[v]=el;flow[el]=0;
}
bool bfs(){
//	puts("yet another bfs");
	MEM(dis,-1);
	FOR(i,1,t) cur[i]=head[i];
	dis[q[h=r=1]=s]=0;
	while(h<=r){
		int u=q[h++];
//		printf("u=%d\n",u);
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(flow[i] && dis[v]==-1) dis[q[++r]=v]=dis[u]+1;
		}
	}
	return ~dis[t];
}
int dfs(int u,int minres){
//	printf("dfs(%d,%d)\n",u,minres);
	if(u==t || !minres) return minres;
	int f,rtf=0;
	for(int &i=cur[u];i;i=nxt[i]){
		int v=to[i];
		if(dis[v]==dis[u]+1 && (f=dfs(v,min(minres,flow[i])))){
			flow[i]-=f;flow[i^1]+=f;
			minres-=f;rtf+=f;
			if(!minres) break;
		}
	}
	return rtf;
}
int main(){
	read();n=read();
	FOR(i,1,n){
		xl[i]=read();yl[i]=read();xr[i]=read()+1,yr[i]=read()+1;
		xtmp[2*i-1]=xl[i];
		xtmp[2*i]=xr[i];
		ytmp[2*i-1]=yl[i];
		ytmp[2*i]=yr[i];
	}
	sort(xtmp+1,xtmp+2*n+1);
	xsz=unique(xtmp+1,xtmp+2*n+1)-xtmp-1;
	sort(ytmp+1,ytmp+2*n+1);
	ysz=unique(ytmp+1,ytmp+2*n+1)-ytmp-1;
	FOR(i,1,xsz-1) FOR(j,1,ysz-1){
		bool flag=false;
		FOR(k,1,n) flag|=xl[k]<=xtmp[i] && xr[k]>=xtmp[i+1] && yl[k]<=ytmp[j] && yr[k]>=ytmp[j+1];
		if(!flag) continue;
		add(i,j+xsz-1,2e9);
	}
	s=xsz+ysz-1;t=xsz+ysz;
	FOR(i,1,xsz-1) add(s,i,xtmp[i+1]-xtmp[i]);
	FOR(i,1,ysz-1) add(i+xsz-1,t,ytmp[i+1]-ytmp[i]);
	while(bfs()) ans+=dfs(s,2e9);
	printf("%d\n",ans);
}