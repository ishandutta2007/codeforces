#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define MM 1000005
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
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,k;
int a[MN],b[MN],x[MN],y[MN],ca[MN],cb[MN],z[MN];
int d[MN],c;
int mnv[MN];
vector<int>g1[MM],g2[MM];

#define li (i<<1)
#define ri (li|1)
#define mid ((l+r)>>1)
#define ls li,l,mid
#define rs ri,mid+1,r
int mn[MS],tg[MS];
inline void P(int i,int x){mn[i]+=x;tg[i]+=x;}
inline void pd(int i){if(tg[i])P(li,tg[i]),P(ri,tg[i]),tg[i]=0;}
void build(int i,int l,int r){
	if(l==r){mn[i]=mnv[l];return;}
	build(ls),build(rs);
	mn[i]=min(mn[li],mn[ri]);
}
void mdf(int i,int l,int r,int a,int b,int x){
	if(r<a||b<l)return;
	if(a<=l&&r<=b)return P(i,x);
	pd(i),mdf(ls,a,b,x),mdf(rs,a,b,x);
	mn[i]=min(mn[li],mn[ri]);
}
int ans=0x7fffffff;
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,n)scanf("%d%d",a+i,ca+i),g1[a[i]].pb(i);
	F(i,1,m)scanf("%d%d",b+i,cb+i),d[++c]=b[i];
	sort(d+1,d+c+1),c=unique(d+1,d+c+1)-d-1;
	F(i,1,c)mnv[i]=inf;
	F(i,1,m)b[i]=lower_bound(d+1,d+c+1,b[i])-d,mnv[b[i]]=min(mnv[b[i]],cb[i]);
	build(1,1,c);
	F(i,1,k)scanf("%d%d%d",x+i,y+i,z+i),g2[x[i]].pb(i);
	F(v,1,1000000){
		for(auto i:g1[v])ans=min(ans,mn[1]+ca[i]);
		for(auto i:g2[v]){
			int p=upper_bound(d+1,d+c+1,y[i])-d;
			if(p<=c)mdf(1,1,c,p,c,-z[i]);
		}
	}
	printf("%d\n",-ans);
}	return 0;
}