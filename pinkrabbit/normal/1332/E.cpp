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
int n,m,L,R,c0,c1;
int main(){
	scanf("%d%d%d%d",&n,&m,&L,&R);
	if(L==R)return puts("1"),0;
	if((ll)n*m%2==1)return printf("%d\n",qpow(R-L+1,(ll)n*m)),0;
	c0+=R/2,c1+=R-R/2;
	c0-=(L-1)/2,c1-=(L-1)-(L-1)/2;
//	printf("%d %d\n",c0,c1);
	int ans=(ll)(qpow(c0+c1,(ll)n*m)+qpow(c0-c1,(ll)n*m))*((mod+1)/2)%mod;
	printf("%d\n",ans);
	return 0;
}