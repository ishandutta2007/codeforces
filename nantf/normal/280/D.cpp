#include<bits/stdc++.h>
using namespace std;
const int maxn=100010,mod=998244353;
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
int n,m,a[maxn],ls[maxn],rs[maxn],tp;
inline bool chkmax(int &x,int y){
	if(y>x) return x=y,true;
	return false;
}
inline bool chkmin(int &x,int y){
	if(y<x) return x=y,true;
	return false;
}
struct node{
	int l,r,sum,lmax,rmax,amax,lx,rx,llx,rrx,lmin,rmin,amin,ln,rn,lln,rrn;
	node operator+(const node &nd)const{
		node ans;
		ans.l=l;ans.r=nd.r;
		ans.sum=sum+nd.sum;
		ans.lmax=lmax;ans.llx=llx;
		if(chkmax(ans.lmax,sum+nd.lmax)) ans.llx=nd.llx;
		ans.rmax=nd.rmax;ans.rrx=nd.rrx;
		if(chkmax(ans.rmax,nd.sum+rmax)) ans.rrx=rrx;
		ans.amax=amax;ans.lx=lx;ans.rx=rx;
		if(chkmax(ans.amax,nd.amax)) ans.lx=nd.lx,ans.rx=nd.rx;
		if(chkmax(ans.amax,rmax+nd.lmax)) ans.lx=rrx,ans.rx=nd.llx;
		ans.lmin=lmin;ans.lln=lln;
		if(chkmin(ans.lmin,sum+nd.lmin)) ans.lln=nd.lln;
		ans.rmin=nd.rmin;ans.rrn=nd.rrn;
		if(chkmin(ans.rmin,nd.sum+rmin)) ans.rrn=rrn;
		ans.amin=amin;ans.ln=ln;ans.rn=rn;
		if(chkmin(ans.amin,nd.amin)) ans.ln=nd.ln,ans.rn=nd.rn;
		if(chkmin(ans.amin,rmin+nd.lmin)) ans.ln=rrn,ans.rn=nd.lln;
		return ans;
	}
}seg[maxn*4];
bool rev[maxn*4];
inline void setrev(int o){
	rev[o]^=1;
	seg[o].sum*=-1;
	int tlmax=seg[o].lmax,trmax=seg[o].rmax,tamax=seg[o].amax;
	int tlx=seg[o].lx,trx=seg[o].rx,tllx=seg[o].llx,trrx=seg[o].rrx;
	seg[o].lmax=-seg[o].lmin;seg[o].rmax=-seg[o].rmin;seg[o].amax=-seg[o].amin;
	seg[o].lmin=-tlmax;seg[o].rmin=-trmax;seg[o].amin=-tamax;
	swap(seg[o].lx,seg[o].ln);swap(seg[o].rx,seg[o].rn);
	swap(seg[o].llx,seg[o].lln);swap(seg[o].rrx,seg[o].rrn);
}
inline void pushdown(int o){
	if(rev[o]){
		setrev(o<<1);
		setrev(o<<1|1);
		rev[o]=0;
	}
}
void build(int o,int l,int r){
	if(l==r) return void(seg[o]=(node){l,l,a[l],a[l],a[l],a[l],l,l,l,l,a[l],a[l],a[l],l,l,l,l});
	int mid=(l+r)>>1;
	build(lson);build(rson);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
void update(int o,int l,int r,int p,int v){
	if(l==r) return void(seg[o]=(node){l,l,v,v,v,v,l,l,l,l,v,v,v,l,l,l,l});
	pushdown(o);
	int mid=(l+r)>>1;
	if(mid>=p) update(lson,p,v);
	else update(rson,p,v);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
void reverse(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return setrev(o);
	pushdown(o);
	int mid=(l+r)>>1;
	if(mid>=ql) reverse(lson,ql,qr);
	if(mid<qr) reverse(rson,ql,qr);
	seg[o]=seg[o<<1]+seg[o<<1|1];
}
node query(int o,int l,int r,int ql,int qr){
	if(l>=ql && r<=qr) return seg[o];
	pushdown(o);
	int mid=(l+r)>>1;
	if(mid<ql) return query(rson,ql,qr);
	if(mid>=qr) return query(lson,ql,qr);
	return query(lson,ql,qr)+query(rson,ql,qr);
}
int main(){
	n=read();
	FOR(i,1,n) a[i]=read();
	build(1,1,n);
	m=read();
	while(m--){
		int op=read(),x=read(),y=read();
		if(op){
			int k=read(),s=0,ans=0;
			tp=0;
			while(k--){
				node nd=query(1,1,n,x,y);
				ls[++tp]=nd.lx;rs[tp]=nd.rx;
				chkmax(ans,s+=nd.amax);
				reverse(1,1,n,nd.lx,nd.rx);
			}
			while(tp) reverse(1,1,n,ls[tp],rs[tp]),tp--;
			printf("%d\n",ans);
		}
		else update(1,1,n,x,y);
	}
}