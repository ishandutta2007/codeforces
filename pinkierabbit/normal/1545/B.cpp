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
int fac[MN],ifac[MN];
void init(int n){
	fac[0]=1;
	F(i,1,n)fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	dF(i,n,1)ifac[i-1]=(ll)ifac[i]*i%mod;
}
int n,a[MN],b[MN],c;
int main(){init(200000);int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%1d",a+i);
	c=0;
	F(i,1,n)if(a[i]==0)b[++c]=i&1;
	b[0]=0;
	int len=0;
	F(i,1,c)len+=b[i]==b[i-1]?2:1;
	len=(n-len)/2;
	printf("%lld\n",(ll)fac[len+c]*ifac[len]%mod*ifac[c]%mod);
}	return 0;
}