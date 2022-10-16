#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int maxn=444444,mod=998244353;
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define lson o<<1,l,mid
#define rson o<<1|1,mid+1,r
#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define ROF(i,a,b) for(int i=(a);i>=(b);i--)
#define MEM(x,v) memset(x,v,sizeof(x))
template<typename T>
inline void read(T &x){
	x=0;
	bool f=0;char ch=getchar();
	while(ch<'0' || ch>'9') f|=ch=='-',ch=getchar();
	while(ch>='0' && ch<='9') x=x*10+ch-'0',ch=getchar();
	if(f) x=-x;
}
int n,m,el2,head2[maxn],to2[maxn],nxt2[maxn],a2[maxn],b2[maxn];
int cnt,el=1,head[maxn],to[maxn],nxt[maxn],a[maxn],b[maxn];
int p[maxn*20],pl,q[maxn],ql,stk[maxn*20],tp,wl;
ll A[maxn*20],B[maxn*20];
int sz[maxn],rt,tot;
bool vis[maxn];
inline void add2(int u,int v,int aa,int bb){
	to2[++el2]=v;nxt2[el2]=head2[u];head2[u]=el2;a2[el2]=aa;b2[el2]=bb;
	to2[++el2]=u;nxt2[el2]=head2[v];head2[v]=el2;a2[el2]=aa;b2[el2]=bb;
}
inline void add(int u,int v,int aa,int bb){
	to[++el]=v;nxt[el]=head[u];head[u]=el;a[el]=aa;b[el]=bb;
	to[++el]=u;nxt[el]=head[v];head[v]=el;a[el]=aa;b[el]=bb;
}
void build(int u,int f){
	int tmp=u;
	for(int i=head2[u];i;i=nxt2[i]){
		int v=to2[i];
		if(v==f) continue;
		build(v,u);
		add(tmp,v,a2[i],b2[i]);
		add(tmp,++cnt,0,0);
		tmp=cnt;
	}
}
void getrt(int u,int f){
	sz[u]=1;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f || vis[i]) continue;
		getrt(v,u);
		sz[u]+=sz[v];
		if(!rt || max(sz[v],tot-sz[v])<max(sz[to[rt]],tot-sz[to[rt]])) rt=i;
	}
}
void getdis(int u,int f){
	p[++pl]=u; 
	if(!f) A[u]=B[u]=0;
	for(int i=head[u];i;i=nxt[i]){
		int v=to[i];
		if(v==f || vis[i]) continue;
		A[v]=A[u]+a[i];
		B[v]=B[u]+b[i];
		getdis(v,u);
	}
}
inline bool cmp(int x,int y){
	if(A[x]!=A[y]) return A[x]<A[y];
	return B[x]<B[y];
}
inline double slope(int x,int y){
	return 1.0*(B[y]-B[x])/(A[y]-A[x]);
}
void convex(){
	tp=0;
	sort(p+1,p+pl+1,cmp);
	FOR(i,1,pl){
		while(tp && A[stk[tp]]==A[p[i]] && B[stk[tp]]<=B[p[i]]) tp--;
		while(tp>1 && slope(stk[tp-1],stk[tp])<slope(stk[tp],p[i])) tp--;
		stk[++tp]=p[i];
	}
}
void getall(int uu){
	rt=0;
	getrt(uu,0);
	assert(sz[uu]==tot);
	if(!rt) return;
	vis[rt]=vis[rt^1]=true;
	int u=to[rt^1],v=to[rt];
	pl=0;
	getdis(u,0);
	convex();
	ql=tp;
	FOR(i,1,ql) q[i]=stk[i];
	pl=0;
	getdis(v,0);
	convex();
	pl=tp;
	FOR(i,1,pl) p[i]=stk[i];
	A[++wl]=A[p[1]]+A[q[1]]+a[rt];
	B[wl]=B[p[1]]+B[q[1]]+b[rt];
	int x=2,y=2;
	while(x<=pl || y<=ql){
		double s1=x<=pl?slope(p[x-1],p[x]):-1e18,s2=y<=ql?slope(q[y-1],q[y]):-1e18;
		if(s1>s2){
			A[wl+1]=A[wl]+A[p[x]]-A[p[x-1]];
			B[wl+1]=B[wl]+B[p[x]]-B[p[x-1]];
			x++,wl++;
		}
		else{
			A[wl+1]=A[wl]+A[q[y]]-A[q[y-1]];
			B[wl+1]=B[wl]+B[q[y]]-B[q[y-1]];
			y++,wl++;
		}
	}
	tot=tot-sz[v];getall(u);
	tot=sz[v];getall(v);
}
int main(){
	read(n);read(m);
	FOR(i,1,n-1){
		int u,v,a,b;
		read(u);read(v);read(a);read(b);
		add2(u,v,a,b);
	}
	cnt=n;
	build(1,0);
	wl=cnt;
	tot=cnt;
	getall(1);
	pl=wl-n;
	FOR(i,1,pl) p[i]=i+n;
	convex();
	int at=1;
	FOR(i,0,m-1){
		while(at<tp && A[stk[at]]*i+B[stk[at]]<A[stk[at+1]]*i+B[stk[at+1]]) at++;
		printf("%lld ",A[stk[at]]*i+B[stk[at]]);
	}
}