#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 200005
#define ll long long
#define mod 998244353
#define inv2 499122177
#define inf 0x3f3f3f3f
#define infll 0x3f3f3f3f3f3f3f3f
typedef pair<int,int> pii;
#define pb push_back
#define mkp make_pair
#define fi first
#define se second
inline int qpow(int b,int e){int a=1;for(;e;e>>=1,b=(ll)b*b%mod)if(e&1)a=(ll)a*b%mod;return a;}
int n,k,c,a[MN],ans;
int fac[MN],ifac[MN];
void init(int n){
	fac[0]=1;
	F(i,1,n)fac[i]=(ll)fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	dF(i,n,1)ifac[i-1]=(ll)ifac[i]*i%mod;
}
inline int binom(int n,int m){return (ll)fac[n]*ifac[m]%mod*ifac[n-m]%mod;}
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&k),ans=0;
	F(i,1,n)scanf("%d",a+i);
	F(i,1,n)if(a[i]!=a[i%n+1])++c;
	init(n);
//	debug("c=%d\n",c);
	F(i,0,c){
		int s=qpow(2,i);
		if(~i&1)s=(s-binom(i,i/2)+mod)%mod;
		s=(ll)s*binom(c,i)%mod;
//		printf("i=%d,s=%d\n",i,s);
		s=(ll)s*qpow(k-2,c-i)%mod;
		ans=(ans+s)%mod;
	}
//	debug("ans=%d\n",ans);
	ans=(ll)ans*qpow(k,n-c)%mod*inv2%mod;
	printf("%d\n",ans);
}	return 0;
}