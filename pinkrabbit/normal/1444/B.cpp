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
int n,m,q,k;
int a[MN],f[MN];
int main(){
	scanf("%d",&n);
	F(i,1,2*n)scanf("%d",a+i);
	sort(a+1,a+2*n+1);
	int ans=0;
	F(i,1,n)ans=((ll)ans+a[2*n-i+1]-a[i]+mod)%mod;
	F2(i,0,n)ans=(ll)ans*(2*n-i)%mod;
	f[1]=1;
	F(i,2,n)f[i]=(ll)(mod-mod/i)*f[mod%i]%mod;
	F(i,1,n)ans=(ll)ans*f[i]%mod;
	printf("%d\n",ans);
	return 0;
}