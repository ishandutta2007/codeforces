#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=100010,mod=998244353,INF=1e9;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T=int>
inline T read(){
	T x=0,f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	return f?-x:x;
}
int n,m,Q,c[maxn],s,t,el=1,head[maxn],to[maxn],nxt[maxn],flow[maxn],a1,a2,pl;
int q[maxn],h,r,pre[maxn],flw[maxn],ans,cost[maxn],d[maxn],dis[maxn];
bool inq[maxn];
PII p[maxn];
inline void add(int u,int v,int w,int c){
	to[++el]=v;nxt[el]=head[u];head[u]=el;flow[el]=w;cost[el]=c;
	to[++el]=u;nxt[el]=head[v];head[v]=el;flow[el]=0;cost[el]=-c;
}
void spfa(){
	FOR(i,1,t) d[i]=INF;
	d[s]=0;
	q[h=r=1]=s;
	inq[s]=true;
	while(h<=r){
		int u=q[h++];
		inq[u]=false;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(flow[i] && d[v]>d[u]+cost[i]){
				d[v]=d[u]+cost[i];
				if(!inq[v]) q[++r]=v,inq[v]=true;
			}
		}
	}
}
priority_queue<PII,vector<PII>,greater<PII> > pq;
bool dij(){
	FOR(i,1,t) dis[i]=INF,pre[i]=0,flw[i]=INF;
	while(!pq.empty()) pq.pop();
	pq.push(MP(dis[s]=0,s));
	while(!pq.empty()){
		PII p=pq.top();pq.pop();
		int u=p.second;
		if(p.first!=dis[u]) continue;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(flow[i] && dis[v]>dis[u]+d[u]-d[v]+cost[i]){
				dis[v]=dis[u]+d[u]-d[v]+cost[i];
				pre[v]=i;
				flw[v]=min(flw[u],flow[i]);
				pq.push(MP(dis[v],v));
			}
		}
	}
	if(dis[t]==INF) return false;
	a1+=flw[t];
	a2+=flw[t]*(dis[t]+d[t]);
	int now=t;
	while(now!=s){
		flow[pre[now]]-=flw[t];
		flow[pre[now]^1]+=flw[t];
		now=to[pre[now]^1];
	}
	return true;
}
int main(){
	n=read();m=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		add(u,v,1,w);
	}
	s=1;t=n;
	spfa();
	while(dij()) p[++pl]=MP(a1,a2);
	Q=read();
	while(Q--){
		int s=read();
		double ans=1e9;
		FOR(i,1,pl) ans=min(ans,1.0*(p[i].se+s)/p[i].fi);
		printf("%.10lf\n",ans);
	}
}