#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 500005
#define MS (1<<21)
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f3f3f3f3f
typedef pair<ll,int> pli;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,x[MN],y[MN],c[MN],p[MN];
int dd[MN*2],cc;
pli mx[MS];ll tg[MS];
#define li (i<<1)
#define ri (i<<1|1)
#define mid ((l+r)>>1)
#define ls li,l,mid
#define rs ri,mid+1,r
#define rt 1,1,cc
inline void P(int i,ll x){mx[i].fi+=x,tg[i]+=x;}
inline void pd(int i){if(tg[i])P(li,tg[i]),P(ri,tg[i]),tg[i]=0;}
void build(int i,int l,int r){mx[i]=pli(0ll,l);if(l==r)return;build(ls),build(rs);}
void mdf(int i,int l,int r,int a,int b,ll x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b)return P(i,x);
	pd(i);
	mdf(ls,a,b,x),mdf(rs,a,b,x);
	mx[i]=mx[li].fi>mx[ri].fi?mx[li]:mx[ri];
}
pli qur(int i,int l,int r,int a,int b){
	if(r<a||b<l)return pli(-inf,0);
	if(a<=l&&r<=b)return mx[i];
	pd(i);
	pli la=qur(ls,a,b),ra=qur(rs,a,b);
	return la.fi>ra.fi?la:ra;
}
ll anv;int anl=-1,anr=-1;
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d%d%d",x+i,y+i,c+i),p[i]=i;
	F(i,1,n)if(x[i]<y[i])swap(x[i],y[i]);
	F(i,1,n)dd[++cc]=x[i],dd[++cc]=y[i];
	sort(dd+1,dd+cc+1),cc=unique(dd+1,dd+cc+1)-dd-1;
	F(i,1,n)x[i]=lower_bound(dd+1,dd+cc+1,x[i])-dd,y[i]=lower_bound(dd+1,dd+cc+1,y[i])-dd;
	sort(p+1,p+n+1,[](int i,int j){return x[i]<x[j];});
	build(rt);
	int j=1;
	F(i,1,n){
		mdf(rt,1,y[p[i]],c[p[i]]);
		while(j<x[p[i]])mdf(rt,1,j,dd[j]-dd[j+1]),++j;
		if(i==n||x[p[i]]!=x[p[i+1]]){
//			F(j,1,x[p[i]])printf("%lld ",qur(rt,j,j).fi);puts("");
			pli now=qur(rt,1,x[p[i]]);
			if(anv<now.fi)anv=now.fi,anl=now.se,anr=x[p[i]];
		}
	}
	if(anl==-1)puts("0\n2000000000 2000000000 2000000000 2000000000");
	else printf("%lld\n%d %d %d %d\n",anv,dd[anl],dd[anl],dd[anr],dd[anr]);
	return 0;
}