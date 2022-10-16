#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=500050,mod=998244353;
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
struct edge{
	int u,v,w;
	bool operator<(const edge &e)const{return w<e.w;}
}e[maxn];
int n,m,s,t,tot,el=1,head[maxn],to[maxn],nxt[maxn],flow[maxn],dis[maxn],q[maxn],h,r,cur[maxn],mxf;
inline void add(int u,int v,int w){
	to[++el]=v;nxt[el]=head[u];head[u]=el;flow[el]=w;
	to[++el]=u;nxt[el]=head[v];head[v]=el;flow[el]=0;
}
bool bfs(){
	FOR(i,1,tot) dis[i]=-1,cur[i]=head[i];
	q[h=r=1]=s;
	dis[s]=0;
	while(h<=r){
		int u=q[h++];
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(flow[i] && dis[v]==-1){
				dis[v]=dis[u]+1;
				q[++r]=v;
			}
		}
	}
	return ~dis[t];
}
int dfs(int u,int minres){
	if(u==t || !minres) return minres;
	int f=0,rtf=0;
	for(int &i=cur[u];i;i=nxt[i]){
		int v=to[i];
		if(dis[v]==dis[u]+1 && (f=dfs(v,min(minres,flow[i])))){
			flow[i]-=f;flow[i^1]+=f;
			rtf+=f;minres-=f;
			if(!minres) break;
		}
	}
	return rtf;
}
void dinic(){
	while(bfs()) mxf+=dfs(s,1e9);
}
bool check(int x){
	FOR(i,2,el) to[i]=nxt[i]=flow[i]=0;
	FOR(i,1,tot) head[i]=0;
	el=1;tot=0;
	s=2*n+1;tot=t=2*n+2;
	FOR(i,1,n) add(s,i,1),add(i+n,t,1);
	FOR(i,1,x){
		int u=e[i].u,v=e[i].v;
		add(u,v+n,1);
	}
	mxf=0;
	dinic();
	return mxf==n;
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		e[i]=(edge){u,v,w};
	}
	sort(e+1,e+m+1);
	int l=1,r=m+1;
	while(l<r){
		int mid=(l+r)>>1;
		if(check(mid)) r=mid;
		else l=mid+1;
	}
	printf("%d\n",l==m+1?-1:e[l].w);
}