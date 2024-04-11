#include<bits/stdc++.h>
#define debug(x) cerr<<#x<<" = "<<x
#define sp <<"  "
#define el <<endl
#define fgx cerr<<"-----------------------------------"<<endl
#define LL long long
#define DB double
#define pb push_back
#define LDB long double
#define ULL unsigned long long
using namespace std;
inline LL read(){
	LL nm=0; bool fh=1; char cw=getchar();
	for(;!isdigit(cw);cw=getchar()) fh^=(cw=='-');
	for(;isdigit(cw);cw=getchar()) nm=nm*10+(cw-'0');
	return fh?nm:-nm;
}
#define mod 998244353
namespace CALC{
	inline int add(int x,int y){return (x+y>=mod)?(x+y-mod):(x+y);}
	inline int mns(int x,int y){return (x-y<0)?(x-y+mod):(x-y);}
	inline int mul(LL x,LL y){return x*y%mod;}
	inline void upd(int &x,int y){x=(x+y>=mod)?(x+y-mod):(x+y);}
	inline void dec(int &x,int y){x=(x-y<0)?(x-y+mod):(x-y);}
	inline int qpow(int x,LL sq){int res=1;for(;sq;sq>>=1,x=mul(x,x))if(sq&1)res=mul(res,x);return res;}
}using namespace CALC;
#define M 200020
int n,pl[M],pr[M],t[M],cod[M<<2],m;
vector<int>ql[2][M<<2];
int rt[2],tg[M<<4],mx[M<<4],L[M<<4],R[M<<4],tot;
inline void build(int &x,int l,int r){
	x=++tot; if(l==r) return; int mid=((l+r)>>1);
	build(L[x],l,mid),build(R[x],mid+1,r);
}
inline void chg(int x,int v){mx[x]+=v,tg[x]+=v;}
inline void pushdown(int x){if(tg[x])chg(L[x],tg[x]),chg(R[x],tg[x]),tg[x]=0;}
inline void mdf(int x,int l,int r,int pr){
	if(r<=pr){chg(x,1);return;} if(l>pr) return; int mid=((l+r)>>1); pushdown(x);
	mdf(L[x],l,mid,pr),mdf(R[x],mid+1,r,pr),mx[x]=max(mx[L[x]],mx[R[x]]);
}
inline void qmx(int x,int l,int r,int pos,int val){
	if(l==r){mx[x]=max(mx[x],val);return;} int mid=((l+r)>>1); pushdown(x);
	(pos<=mid)?qmx(L[x],l,mid,pos,val):qmx(R[x],mid+1,r,pos,val); mx[x]=max(mx[L[x]],mx[R[x]]);
}
int main(){
	n=read();
	for(int i=1;i<=n;i++){
		pl[i]=read(),pr[i]=read(),t[i]=read();
		cod[++m]=pl[i],cod[++m]=pr[i];
	} sort(cod+1,cod+m+1),m=unique(cod+1,cod+m+1)-cod-1;
	for(int i=1;i<=n;i++){
		pl[i]=lower_bound(cod+1,cod+m+1,pl[i])-cod;
		pr[i]=lower_bound(cod+1,cod+m+1,pr[i])-cod;
		t[i]--,ql[t[i]][pr[i]].pb(pl[i]);
	} build(rt[0],1,m),build(rt[1],1,m);
	for(int i=1;i<=m;i++){
		int v0=mx[rt[0]],v1=mx[rt[1]];
		qmx(rt[0],1,m,i,v1),qmx(rt[1],1,m,i,v0);
		for(int k=0;k<2;k++) for(int j=0,TP=ql[k][i].size();j<TP;++j)
			mdf(rt[k],1,m,ql[k][i][j]);
	}
	printf("%d\n",max(mx[rt[0]],mx[rt[1]]));
	return 0;
}