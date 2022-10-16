#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=666666,mod=998244353;
#define PB push_back
#define MP make_pair
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
int n,m,s,el,head[maxn],to[maxn],nxt[maxn],w[maxn];
int el2,head2[maxn],to2[maxn],nxt2[maxn],deg[maxn];
int q[maxn],h,r,id[maxn],sz[maxn],ans,tmp[maxn];
ll dis[maxn];
struct node{
	ll d;
	int u;
	bool operator<(const node &nd)const{return d>nd.d;}
};
priority_queue<node> pq; 
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
inline void add2(int u,int v){
	to2[++el2]=v;nxt2[el2]=head2[u];head2[u]=el2;deg[v]++;
}
int main(){
	n=read();m=read();s=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	FOR(i,1,n) dis[i]=1e18;
	pq.push((node){dis[s]=0,s});
	while(!pq.empty()){
		int u=pq.top().u;
		ll d=pq.top().d;
		pq.pop();
		if(dis[u]!=d) continue;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(d+w[i]<dis[v]) pq.push((node){dis[v]=d+w[i],v});
		}
	}
	FOR(u,1,n) for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(dis[u]+w[i]==dis[v]) add2(u,v);
	}
	q[h=r=1]=s;
	FOR(i,1,n) tmp[i]=i;
	while(h<=r){
		int u=q[h++];
		if(tmp[u]!=-1 && tmp[u]!=s) id[u]=tmp[u];
		else id[u]=u;
		sz[id[u]]++;
		for(int i=head2[u];i;i=nxt2[i]){
			int v=to2[i];
			if(tmp[v]==v) tmp[v]=id[u];
			else if(tmp[v]!=id[u]) tmp[v]=-1;
			if(!--deg[v]) q[++r]=v;
		}
	}
	FOR(i,1,n) if(i!=s) ans=max(ans,sz[i]);
	printf("%d\n",ans);
}
// for best solution (