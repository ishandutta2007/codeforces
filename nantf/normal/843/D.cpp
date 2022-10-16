#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int maxn=100010,mod=998244353;
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
int n,m,q,el,head[maxn],to[maxn],nxt[maxn],w[maxn],w2[maxn],d[maxn];
ll dis[maxn];
priority_queue<PII,vector<PII>,greater<PII> > pq;
vector<int> vec[maxn];
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
void dijkstra(){
	FOR(i,1,n) dis[i]=1e18;
	dis[1]=0;
	pq.push(MP(0,1));
	while(!pq.empty()){
		ll d=pq.top().first;
		int u=pq.top().second;
		pq.pop();
		if(dis[u]!=d) continue;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>dis[u]+w[i]) pq.push(MP(dis[v]=dis[u]+w[i],v)); 
		}
	}
}
void dijkstra2(){
	FOR(i,1,n) d[i]=m+1;
	d[1]=0;
	FOR(i,0,m+1) vec[i].clear();
	FOR(i,1,n) vec[d[i]].PB(i);
	FOR(i,0,m){
		while(!vec[i].empty()){
			int u=vec[i].back();
			vec[i].pop_back();
			if(d[u]!=i) continue;
			for(int j=head[u];j;j=nxt[j]){
				int v=to[j];
				if(d[v]>d[u]+w2[j]){
					d[v]=d[u]+w2[j];
					vec[d[v]].PB(v);
				}
			}
		}
	}
}
void build(){
	FOR(u,1,n) for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		w2[i]=dis[u]+w[i]-dis[v];
	}
}
int main(){
	n=read();m=read();q=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		add(u,v,w);
	}
	dijkstra();
	build();
	while(q--){
		int op=read();
		if(op==1){
			int id=read();
			if(dis[id]<1e18) printf("%I64d\n",dis[id]);
			else puts("-1");
		}
		else{
			int m=read();
			while(m--){
				int id=read();
				w[id]++;w2[id]++;
			}
			dijkstra2();
			FOR(i,1,n) dis[i]+=d[i];
			build();
		}
	}
}