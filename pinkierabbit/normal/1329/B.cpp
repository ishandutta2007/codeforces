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
int d,m;
int f[50],ans;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	ans=0;
	scanf("%d%d",&d,&m);
	int bt=31-__builtin_clz(d);
	F2(j,0,bt){
		f[j]=1;
		F2(k,0,j)f[j]=(f[j]+f[k])%m;
		f[j]=(ll)f[j]*(1<<j)%m;
		ans=(ans+f[j])%m;
	}
	int sum=1;
	F2(j,0,bt)sum=(sum+f[j])%m;
	ans=(ans+(ll)sum*(d-(1<<bt)+1))%m;
	printf("%d\n",ans);
}	return 0;
}

// 1
// 10 11