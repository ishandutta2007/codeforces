#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
using namespace std;
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define M 150020
#define pii pair<int,int>
#define mp make_pair
#define vl first
#define rm second
int n,Q,P,K,A[M];
int tg[M<<2],len[M<<2];
pii p[M<<2][5],res[5];
inline void ins(pii *t,int x,int k){
	for(int i=0;i<K;i++) if(t[i].vl==x){t[i].rm+=k;return;} int mi=k;
	for(int i=0;i<K;i++)  mi=min(mi,t[i].rm);
	for(int i=0;i<K;i++) t[i].rm-=mi; k-=mi; if(!k) return;
	for(int i=0;i<K;i++) if(!t[i].rm){t[i]=mp(x,k);return;}
}
inline void Ins(pii *t,pii *q){for(int i=0;i<K;i++) if(q[i].rm>0) ins(t,q[i].vl,q[i].rm);}
inline void clr(pii *t){for(int i=0;i<K;i++)t[i]=mp(0,0);}
inline void cpy(pii *t,pii *q){for(int i=0;i<K;i++)t[i]=q[i];}
inline void pushup(int x){cpy(p[x],p[x<<1]),Ins(p[x],p[x<<1|1]);}
inline void chg(int x,int w){tg[x]=w,clr(p[x]),p[x][0]=mp(w,len[x]);}
inline void pushdown(int x){if(tg[x])chg(x<<1,tg[x]),chg(x<<1|1,tg[x]),tg[x]=0;}
inline void build(int x,int l,int r){
	len[x]=(r-l+1); if(l==r){p[x][0]=mp(A[l],1);return;}
	int mid=((l+r)>>1); build(x<<1,l,mid),build(x<<1|1,mid+1,r),pushup(x);
//	printf("[  %d   %d   ]\n",l,r);
//	for(int i=0;i<K;i++) debug(p[x][i].vl)sp,debug(p[x][i].rm)el;
//	fgx;
}
inline void mdf(int x,int l,int r,int ls,int rs,int w){
	if(ls<=l&&r<=rs){chg(x,w);return;} if(r<ls||rs<l) return; int mid=((l+r)>>1);
	pushdown(x),mdf(x<<1,l,mid,ls,rs,w),mdf(x<<1|1,mid+1,r,ls,rs,w),pushup(x);
}
inline void qry(int x,int l,int r,int ls,int rs){
	if(ls<=l&&r<=rs){Ins(res,p[x]);return;} if(r<ls||rs<l) return; int mid=((l+r)>>1);
	pushdown(x),qry(x<<1,l,mid,ls,rs),qry(x<<1|1,mid+1,r,ls,rs);
}
int main(){
	n=read(),Q=read(),P=read(),K=100/P;
	for(int i=1;i<=n;i++) A[i]=read(); build(1,1,n);
	for(int l,r,op;Q;--Q){
		op=read(),l=read(),r=read();
		if(op==1){mdf(1,1,n,l,r,read());continue;}
		clr(res),qry(1,1,n,l,r); int cnt=0;
		for(int i=0;i<K;i++) cnt+=(res[i].rm>0); printf("%d",cnt);
		for(int i=0;i<K;i++) if(res[i].rm>0) printf(" %d",res[i].vl); puts("");
	}
	return 0;
}