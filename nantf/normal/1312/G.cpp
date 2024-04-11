#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=1000100,maxm=23333333;
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
struct node{
	int id,d;
	bool operator<(const node &nd)const{return d>nd.d;}
};
int n,ch[maxn][26],k,id[maxn],lft[maxn],rig[maxn],dfn,head[maxn*5],el,to[maxm],nxt[maxm],w[maxm],rt,ls[maxn*5],rs[maxn*5],cnt,dis[maxn*5];
bool in[maxn];
char s[10];
priority_queue<node> pq;
inline void add(int u,int v,int w_){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=w_;
}
void build(int &x,int l,int r){
	if(l==r) return void(x=n+l);
	x=++cnt;
	int mid=(l+r)>>1;
	build(ls[x],l,mid);
	build(rs[x],mid+1,r);
	add(x,ls[x],0);
	add(x,rs[x],mid-l+1);
}
void update(int x,int l,int r,int ql,int qr,int u){
	if(l>=ql && r<=qr) return add(u,x,l-ql+1);
	int mid=(l+r)>>1;
	if(mid>=ql) update(ls[x],l,mid,ql,qr,u);
	if(mid<qr) update(rs[x],mid+1,r,ql,qr,u);
}
void dfs(int u){
	if(in[u]) lft[u]=++dfn,add(n+dfn,u,0);
	else lft[u]=dfn+1;
	FOR(i,0,25) if(ch[u][i]){
		add(u,ch[u][i],1);
		dfs(ch[u][i]);
	}
	rig[u]=dfn;
	if(lft[u]<=rig[u]) update(rt,1,k,lft[u],rig[u],u);
}
void dijkstra(){
	FOR(i,1,cnt) dis[i]=1e9;
	pq.push((node){0,0});
	while(!pq.empty()){
		int u=pq.top().id,d=pq.top().d;
		pq.pop();
		if(d>dis[u]) continue;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>d+w[i]) pq.push((node){v,dis[v]=d+w[i]});
		}
	}
}
int main(){
	n=read();
	FOR(i,1,n){
		int f=read();
		scanf("%s",s);
		ch[f][s[0]-'a']=i;
	}
	k=read();
	FOR(i,1,k) in[id[i]=read()]=true;
	cnt=n+k;
	build(rt,1,k);
	dfs(0);
	dijkstra();
	FOR(i,1,k) printf("%d ",dis[id[i]]);
}