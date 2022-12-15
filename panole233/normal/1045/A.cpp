#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<set>
#include<map>
#include<ctime>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#define pb push_back
#define SZ(x) ((int)x.size())
#define fi first
#define se second
#define L(i,u) for (int i=head[u]; i!=0; i=nxt[i])
#define rep(i,a,b) for (register int i=a; i<=b; i++)
#define per(i,a,b) for (register int i=a; i>=b; i--)
using namespace std;
typedef long long ll;
typedef unsigned int ui;
typedef pair<int,int> Pii;
typedef vector<int> Vi;
inline void read(int &x) {
	x=0; char c=getchar(); int f=1;
	while (!isdigit(c)) {if (c=='-') f=-1; c=getchar();}
	while (isdigit(c)) {x=x*10+c-'0'; c=getchar();} x*=f;
}
inline ui R() {
	static ui seed=416;
	return seed^=seed>>5,seed^=seed<<17,seed^=seed>>13;
}
const int N = 15555, M = 1040030, inf = 0x3f3f3f3f;
int n,m,S,T,head[N],cur[N],nxt[M],cap[M],to[M],edgenum=1; //1.WA--edgenum 
void addedge(int u, int v, int c){
	to[++edgenum]=v;cap[edgenum]=c;nxt[edgenum]=head[u];head[u]=edgenum;
}
void add(int u, int v, int c){
	addedge(u,v,c);addedge(v,u,0);
}
int dis[N],q[N],mx;
inline bool bfs(int S, int T) {
	memset(dis,inf,4*(mx+2));//2.memsetsizeof()
	int f=0,r=1; q[f]=T; dis[T]=0;
	while (f!=r) {
		int u=q[f++];
		L(i,u) if (cap[i^1]&&dis[to[i]]==inf){
			q[r++]=to[i];dis[to[i]]=dis[u]+1;if(to[i]==S)return 1;//3.
		}
	}
	return dis[S]<inf;
}
vector<Pii>res;
inline int dfs(int u, int flow) {
	if (u==T||!flow)return flow;int res=0;
	for(register int &i=cur[u];i;i=nxt[i])if(cap[i]&&dis[u]==dis[to[i]]+1){//4. 
		int tmp=dfs(to[i],min(flow,cap[i]));
		res+=tmp;flow-=tmp;cap[i]-=tmp;cap[i^1]+=tmp;if(!flow)break;
	}
	return res;
}
inline int dinic(int S, int T){
	int res=0;
	while (bfs(S,T)) {
		memcpy(cur,head,4*(mx+2)); res+=dfs(S,inf);
	}
	return res;
}

int l[M],r[M],lc[M],rc[M],sz=1,A[N],B[N],C[N];vector<Pii> e[N];
void build(int k, int L, int R){
	l[k]=L;r[k]=R;if(L==R)return;
	int mid=(L+R)>>1;lc[k]=++sz;build(lc[k],L,mid);
	rc[k]=++sz;build(rc[k],mid+1,R);
	add(k,lc[k],inf);add(k,rc[k],inf);
}
int find(int k, int p, int q){
	if(l[k]==p&&r[k]==p)return k;
	if(p<=r[lc[k]])return find(lc[k],p,q);return find(rc[k],p,q);
}
void query(int t, int k, int L, int R){
	if(R<l[k]||L>r[k])return;if(L<=l[k]&&R>=r[k]){
		add(t,k,1);return;
	}
	query(t,lc[k],L,R);query(t,rc[k],L,R);
}
bool vis[N];
inline bool DFS(int u, int &x, int &y){
	if(u==T)return 1;vis[u]=1;
	per(i,SZ(e[u])-1,0)if(e[u][i].se&&!vis[e[u][i].fi]){
		int t=DFS(e[u][i].fi,x,y);if(!t)continue;e[u][i].se--;
		if(e[u][i].fi==T)y=u;if(u==S)x=e[u][i].fi;
		return 1;
	}
	vis[u]=0;return 0;
}
int main() {
	read(n);read(m);build(1,1,m);S=sz+n+1;T=S+1;mx=T;
	rep(i,1,m)add(find(1,i,i),T,1);
	rep(i,1,n){
		int op;read(op);
		if(op==0){
			int l,x;read(l);add(S,sz+i,1);
			rep(t,1,l)read(x),add(sz+i,find(1,x,x),1);
		}else if(op==1){
			int l,r;read(l);read(r);add(S,sz+i,1);
			query(sz+i,1,l,r);
		}else{
			int a,b,c;read(a);read(b);read(c);A[i]=a;B[i]=b;C[i]=c;
			add(S,sz+i,2);add(sz+i,find(1,a,a),1);
			add(sz+i,find(1,b,b),1);add(sz+i,find(1,c,c),1);
		}
	}
	int num=dinic(S,T);cout<<num<<endl;
	for(int i=3;i<=edgenum;i+=2)if(cap[i])e[to[i]].pb(Pii(to[i^1],cap[i]));
	rep(i,1,num){memset(vis,0,sizeof(vis));int x,y;DFS(S,x,y);res.pb(Pii(x-sz,l[y]));}
	rep(i,1,n)if(A[i]){
		int cnt=0;rep(j,0,num-1)cnt+=res[j].fi==i;
		if(cnt==1){
			int p=0;rep(j,0,num-1)
				if(res[j].se==A[i]&&res[j].fi!=i||res[j].se==B[i]&&res[j].fi!=i||res[j].se==C[i]&&res[j].fi!=i)p=j;
			res[p].fi=i;
		}
	}
	rep(i,0,num-1)printf("%d %d\n",res[i].fi,res[i].se);
	return 0;
}