#include<bits/stdc++.h>
using namespace std;
typedef long long ll; 
const int maxn=1111111;
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
struct node{
	int mn,mncnt;
	node operator+(const node &nd)const{
		if(mn<nd.mn) return *this;
		else if(mn>nd.mn) return nd;
		else return (node){mn,mncnt+nd.mncnt};
	}
}seg[maxn];
int n,a[maxn],stkmx[maxn],tpmx,stkmn[maxn],tpmn,tag[maxn];
ll ans;
inline void setadd(int o,int v){
	tag[o]+=v;
	seg[o].mn+=v;
}
inline void pushdown(int o){
	if(tag[o]){
		setadd(o<<1,tag[o]);
		setadd(o<<1|1,tag[o]);
		tag[o]=0;
	}
}
void build(int o,int l,int r){
	if(l==r) return void(seg[o]=(node){l,1});
	int mid=(l+r)>>1;
	build(lson);build(rson);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
void update(int o,int l,int r,int ql,int qr,int v){
	if(l>=ql && r<=qr) return setadd(o,v);
	int mid=(l+r)>>1;
	pushdown(o);
	if(mid>=ql) update(lson,ql,qr,v);
	if(mid<qr) update(rson,ql,qr,v);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
int main(){
	n=read();
	FOR(i,1,n){
		int x=read(),y=read();
		a[x]=y;
	}
	build(1,1,n);
	stkmx[tpmx=1]=stkmn[tpmn=1]=0;
	FOR(i,1,n){
		update(1,1,n,1,n,-1);
		while(tpmx>1 && a[i]>a[stkmx[tpmx]]) update(1,1,n,stkmx[tpmx-1]+1,stkmx[tpmx],-a[stkmx[tpmx]]),tpmx--;
		update(1,1,n,stkmx[tpmx]+1,i,a[i]);
		stkmx[++tpmx]=i;
		while(tpmn>1 && a[i]<a[stkmn[tpmn]]) update(1,1,n,stkmn[tpmn-1]+1,stkmn[tpmn],a[stkmn[tpmn]]),tpmn--;
		update(1,1,n,stkmn[tpmn]+1,i,-a[i]);
		stkmn[++tpmn]=i;
		ans+=seg[1].mncnt;
	}
	printf("%lld\n",ans);
}