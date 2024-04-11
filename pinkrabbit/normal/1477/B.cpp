#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MS (1<<19|7)
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
int n,q;
int a[MN],b[MN];
int l[MN],r[MN];
#define li (i<<1)
#define ri (li|1)
#define mid ((l+r)>>1)
#define ls li,l,mid
#define rs ri,mid+1,r
int lb[MS],rb[MS],s[MS],tg[MS];
void P(int i,int x){s[i]=x*(rb[i]-lb[i]+1);tg[i]=x;}
void pd(int i){if(tg[i]!=-1)P(li,tg[i]),P(ri,tg[i]),tg[i]=-1;}
void build(int i,int l,int r){
	lb[i]=l,rb[i]=r,tg[i]=-1;
	if(l==r)return s[i]=b[l],void();
	build(ls),build(rs);
	s[i]=s[li]+s[ri];
}
int qur(int i,int l,int r,int a,int b){
	if(r<a||b<l)return 0;
	if(a<=l&&r<=b)return s[i];
	pd(i);
	return qur(ls,a,b)+qur(rs,a,b);
}
void mdf(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b)return P(i,x);
	pd(i);
	mdf(ls,a,b,x),mdf(rs,a,b,x);
	s[i]=s[li]+s[ri];
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&q);
	F(i,1,n)scanf("%1d",a+i);
	F(i,1,n)scanf("%1d",b+i);
	build(1,1,n);
	F(i,1,q)scanf("%d%d",l+i,r+i);
	int ok=1;
	dF(i,q,1){
		int len=r[i]-l[i]+1;
		int v=qur(1,1,n,l[i],r[i]);
		if(2*v<len)mdf(1,1,n,l[i],r[i],0);
		else if(2*v>len)mdf(1,1,n,l[i],r[i],1);
		else{ok=0;break;}
	}
	if(ok)F(i,1,n)if(qur(1,1,n,i,i)!=a[i]){ok=0;break;}
	puts(ok?"YES":"NO");
}	return 0;
}