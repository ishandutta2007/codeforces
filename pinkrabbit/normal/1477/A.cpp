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
int n;
ll a[MN],k;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%lld",&n,&k);
	F(i,1,n)scanf("%lld",a+i);
	ll g=0;
	F(i,2,n)g=__gcd(g,a[i]>a[1]?a[i]-a[1]:a[1]-a[i]);
//	printf("g=%lld\n",g);
//	F(i,1,n)printf("%lld,",(a[i]%g+g)%g);puts("");
	puts((k%g+g)%g==(a[1]%g+g)%g?"YES":"NO");
}	return 0;
}