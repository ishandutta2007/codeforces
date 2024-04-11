#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=111111,mod=998244353;
#define MP make_pair
#define PB push_back
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
namespace io{
	char buf[maxn*50],*s,*t;
	inline int gc(){
		if(s==t){
			t=(s=buf)+fread(buf,1,maxn*50,stdin);
			if(s==t) return -1;
		}
		return *s++;
	}
}
inline int read(){
	char ch=io::gc();int x=0,f=0;
	while(ch<'0' || ch>'9') ch=io::gc();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=io::gc();
	return x;
}
inline int qpow(int a,int b){
	int ans=1;
	for(;b;b>>=1,a=1ll*a*a%mod) if(b&1) ans=1ll*ans*a%mod;
	return ans;
}
namespace graph{
	int s,t,el=1,head[maxn],to[maxn],nxt[maxn],flw[maxn];
	inline void add(int u,int v,int w){
//		printf("add(%d,%d,%d)\n",u,v,w);
		to[++el]=v;nxt[el]=head[u];head[u]=el;flw[el]=w;
		to[++el]=u;nxt[el]=head[v];head[v]=el;flw[el]=0;
	}
	inline void undo(int u){
		head[u]=nxt[head[u]];
	}
	void clear(){
		FOR(i,1,t) head[i]=0;
		FOR(i,1,el) to[i]=nxt[i]=flw[i]=0;
		s=t=0;el=1;
	}
}
namespace dinic{
	using namespace graph;
	int cur[maxn],dis[maxn],q[maxn],h,r;
	void clear(){
		graph::clear();
	}
	bool bfs(){
		FOR(i,1,t) dis[i]=-1,cur[i]=head[i];
		dis[q[h=r=1]=s]=0;
		while(h<=r){
			int u=q[h++];
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				if(dis[v]==-1 && flw[i]) dis[q[++r]=v]=dis[u]+1;
			}
		}
		return ~dis[t];
	}
	int dfs(int u,int res){
		if(u==t || !res) return res;
		int f=0,tot=0;
		for(int &i=cur[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]==dis[u]+1 && (f=dfs(v,min(res,flw[i])))){
				tot+=f;res-=f;
				flw[i]-=f;flw[i^1]+=f;
				if(!res) break;
			}
		}
		return tot;
	}
	int work(){
		int tot=0;
		while(bfs()) tot+=dfs(s,1e9);
		return tot;
	}
}
namespace ff{
	using namespace graph;
	int vis[maxn],cnt,q[maxn],h,r,w[maxn],fa[maxn];
	short x[maxn*100],y[maxn*100];
	int tp;
	void clear(){
		graph::clear();
	}
	inline void add(int i,int j){
		flw[i]+=j;flw[i^1]-=j;
		x[++tp]=i;y[tp]=j;
	}
	inline void undo(){
		int i=x[tp],j=y[tp--];
		flw[i]-=j;flw[i^1]+=j;
	}
	int bfs(){
		q[h=r=1]=s;
		vis[s]=cnt;
		w[s]=1e9;
		while(h<=r){
			int u=q[h++];
			if(!w[u]) continue;
			for(int i=head[u];i;i=nxt[i]){
				int v=to[i];
				if(flw[i] && vis[v]!=cnt){
					w[v]=min(w[u],flw[i]);
					fa[v]=i;
					vis[v]=cnt;
					if(v==t) break;
					q[++r]=v;
				}
			}
			if(vis[t]==cnt) break;
		}
		if(vis[t]!=cnt) return 0;
		for(int u=t;u!=s;u=to[fa[u]^1]) add(fa[u],-w[t]);
		return w[t];
	}
	int work(){
		int tot=0,f=0;
		while(cnt++,f=bfs()) tot+=f;
		return tot;
	}
}
int n,m,k,q,U[maxn],V[maxn],sum,ans[maxn],sz[maxn];
void dfs(int d,int s){
	if(d>k){
		ans[s]=sum;
//		printf("ans[%d]=%d\n",s,ans[s]);
		return;
	}
	dfs(d+1,s);
	graph::add(U[d],V[d],25);
//	puts("add");
	int ts=sum,tp=ff::tp,te=graph::el;
	sum+=ff::work();
	dfs(d+1,s|1<<(d-1));
//	puts("undo");
	sum=ts;
	while(ff::tp>tp) ff::undo();
	graph::undo(U[d]);graph::undo(V[d]);
}
int main(){
	n=read();m=read();k=read();q=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		if(i<=k) U[i]=u,V[i]=v;
		graph::add(u,v,w);
	}
	graph::s=1;graph::t=n;
	sum=dinic::work();
	dfs(1,0);
	while(q--){
		FOR(i,0,k-1) sz[1<<i]=read();
		FOR(i,1,(1<<k)-1) sz[i]=sz[i&-i]+sz[i^(i&-i)];
		int s=1e9;
		FOR(i,0,(1<<k)-1) s=min(s,sz[i]+ans[((1<<k)-1)^i]);
		printf("%d\n",s);
	}
}