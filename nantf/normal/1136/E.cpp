#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=100010;
const ll INF=9e18;
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
int n,q,a[maxn],k[maxn];
ll kpre[maxn],kprepre[maxn],b[maxn],sum[maxn*4],L[maxn*4],R[maxn*4],cov[maxn*4];
char op[5];
inline int pushup(int o){
	sum[o]=sum[o<<1]+sum[o<<1|1];
	L[o]=L[o<<1];
	R[o]=R[o<<1|1];
}
inline void cover(int o,int l,int r,ll x){
	sum[o]=(r-l+1)*x;
	L[o]=R[o]=cov[o]=x;
}
inline void pushdown(int o,int l,int r){
	if(cov[o]!=-INF){
		int mid=(l+r)>>1;
		cover(lson,cov[o]);
		cover(rson,cov[o]);
		cov[o]=-INF;
	}
}
void build(int o,int l,int r){
	cov[o]=-INF;
	if(l==r) return void(sum[o]=L[o]=R[o]=b[l]);
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	build(lson);build(rson);
	pushup(o);
}
ll query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return sum[o];
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	ll s=0;
	if(mid>=ql) s+=query(lson,ql,qr);
	if(mid<qr) s+=query(rson,ql,qr);
	return s;
}
void update(int o,int l,int r,int p,ll v){
	if(r<p || L[o]>v) return;
	if(l>=p && R[o]<=v) return cover(o,l,r,v);
	pushdown(o,l,r);
	int mid=(l+r)>>1;
	update(lson,p,v);update(rson,p,v);
	pushup(o);
}
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	FOR(i,1,n-1) k[i]=read();
	FOR(i,1,n-1) kpre[i]=kpre[i-1]+k[i];
	FOR(i,1,n-1) kprepre[i]=kprepre[i-1]+kpre[i];
	FOR(i,1,n) b[i]=a[i]-kpre[i-1];
	build(1,1,n);
	q=read();
	while(q--){
		scanf("%s",op+1);
		int x=read(),y=read();
		if(op[1]=='+') update(1,1,n,x,query(1,1,n,x,x)+y);
		else cout<<query(1,1,n,x,y)+kprepre[y-1]-kprepre[max(0,x-2)]<<endl;
	}
}