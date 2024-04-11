#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define MS 600005
#define ll long long
#define inf 5000000000000ll
#define mod 998244353
typedef pair<int,int> pii;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
int n,m,q,k;
int b[MN];
ll a[MN];
ll mn[MS],tg[MS];
void build(int i,int l,int r){
	if(l==r){mn[i]=a[l];return;}
	build(i<<1,l,l+r>>1),build(i<<1|1,(l+r>>1)+1,r);
	mn[i]=min(mn[i<<1],mn[i<<1|1]);
}
inline void P(int i,ll x){mn[i]+=x,tg[i]+=x;}
inline void pd(int i){P(i<<1,tg[i]),P(i<<1|1,tg[i]),tg[i]=0;}
void mdf(int i,int l,int r,int a,ll x){
	if(r<a)return;
	if(l>=a)return P(i,x);
	pd(i);
	mdf(i<<1,l,l+r>>1,a,x),mdf(i<<1|1,(l+r>>1)+1,r,a,x);
	mn[i]=min(mn[i<<1],mn[i<<1|1]);
}
int find(int i,int l,int r){
	if(l==r)return l;
	pd(i);
	return mn[i<<1|1]==0?find(i<<1|1,(l+r>>1)+1,r):find(i<<1,l,l+r>>1);
}
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%lld",a+i);
	build(1,1,n);
	F(i,1,n){
		int p=find(1,1,n);
//		printf("p=%d\n",p);
		b[p]=i;
		mdf(1,1,n,p,inf);
		if(p<n)mdf(1,1,n,p+1,-inf-i);
	}
	F(i,1,n)printf("%d ",b[i]);
	return 0;
}