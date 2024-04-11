#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,int> PII;
const int maxn=222222,mod=998244353;
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
int n,m,q,el=1,head[maxn],to[maxn*2],nxt[maxn*2],w[maxn*2],fa[maxn],tmp[maxn],tmp2[maxn],tl,L[maxn],R[maxn],id[maxn*2];
ll dis[2][maxn],mn[maxn*4];
PII p[maxn];
bool in[maxn];
priority_queue<PII,vector<PII>,greater<PII> > pq;
inline void add(int u,int v,int ww){
	to[++el]=v;nxt[el]=head[u];head[u]=el;w[el]=ww;
}
void dijkstra(ll *dis,int s){
	FOR(i,1,n) dis[i]=1e18;
	pq.push(MP(dis[s]=0,s));
	while(!pq.empty()){
		PII p=pq.top();pq.pop();
		int u=p.second;
		if(p.first>dis[u]) continue;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[v]>dis[u]+w[i]){
				pq.push(MP(dis[v]=dis[u]+w[i],v));
				fa[v]=i;
			}
		}
	}
}
void build(int o,int l,int r){
	mn[o]=1e18;
	if(l==r) return;
	int mid=(l+r)>>1;
	build(lson);build(rson);
}
void update(int o,int l,int r,int ql,int qr,ll v){
	if(ql>qr) return;
//	if(o==1) printf("update %d %d %lld\n",ql,qr,v);
	if(l>=ql && r<=qr) return mn[o]=min(mn[o],v),void();
	int mid=(l+r)>>1;
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
}
ll query(int o,int l,int r,int p){
	if(l==r) return mn[o];
	int mid=(l+r)>>1;
	ll ans=mn[o];
	if(mid>=p) ans=min(ans,query(lson,p));
	else ans=min(ans,query(rson,p));
	return ans;
}
int main(){
	n=read();m=read();q=read();
	FOR(i,1,m){
		int u=read(),v=read(),w=read();
		add(u,v,w);add(v,u,w);
	}
	dijkstra(dis[1],n);
	for(int cur=1;cur!=n;cur=to[fa[cur]^1]) tmp[++tl]=cur,tmp2[tl]=fa[cur]^1,in[cur]=true;
	tmp[++tl]=n;
	in[n]=true;
	FOR(i,1,tl-1) id[tmp2[i]]=id[tmp2[i]^1]=i;
	MEM(L,0x3f);MEM(R,~0x3f);
	FOR(i,1,tl) R[tmp[i]]=i;
	FOR(i,1,n) p[i]=MP(dis[1][i],i);
	sort(p+1,p+n+1);
	FOR(ii,1,n){
		int u=p[ii].second;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[1][v]==dis[1][u]+w[i] && !in[v]) R[v]=max(R[v],R[u]);
		}
	}
	dijkstra(dis[0],1);
	FOR(i,1,tl) L[tmp[i]]=i;
	FOR(i,1,n) p[i]=MP(dis[0][i],i);
	sort(p+1,p+n+1);
	FOR(ii,1,n){
		int u=p[ii].second;
		for(int i=head[u];i;i=nxt[i]){
			int v=to[i];
			if(dis[0][v]==dis[0][u]+w[i] && !in[v]) L[v]=min(L[v],L[u]);
		}
	}
	build(1,1,tl);
	FOR(u,1,n) for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(id[i]) continue;
		update(1,1,tl,L[u],R[v]-1,dis[0][u]+dis[1][v]+w[i]);
		update(1,1,tl,L[v],R[u]-1,dis[0][v]+dis[1][u]+w[i]);
	}
	while(q--){
		int x=read()*2,y=read();
		int u=to[x],v=to[x^1];
		if(id[x]){
			if(y>w[x]) printf("%lld\n",min(dis[0][n]-w[x]+y,query(1,1,tl,id[x])));
			else printf("%lld\n",dis[0][n]-w[x]+y);
		}
		else{
			if(y>w[x]) printf("%lld\n",dis[0][n]);
			else printf("%lld\n",min(dis[0][n],y+min(dis[0][u]+dis[1][v],dis[0][v]+dis[1][u])));
		}
	}
}
// locked up