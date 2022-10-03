#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 300005
#define MM 600005
#define ll long long
#define mod 998244353
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,ll e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,k;
int a[MN],b[MN],f[MN],g[MN];
bool chk(int mid){
	int minn=inf;
	F(i,1,n){
		int x=a[i]>=mid?1:-1;
		f[i]=f[i-1]+x;
		if(i>=k){
			minn=min(minn,f[i-k]);
			if(minn<f[i])return 1;
		}
	}
	return 0;
}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%d",a+i);
	int l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(chk(mid))ans=mid,l=mid+1;
		else r=mid-1;
	}
	printf("%d\n",ans);
}	return 0;
}