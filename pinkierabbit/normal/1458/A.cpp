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
int n,m;
ll a[MN],b[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%lld",a+i);
	F(i,1,m)scanf("%lld",b+i);
	sort(a+1,a+n+1),n=unique(a+1,a+n+1)-a-1;
	ll d=0;
	F(i,2,n)d=__gcd(d,a[i]-a[1]);
	F(i,1,m)printf("%lld\n",__gcd(b[i]+a[1],d));
}	return 0;
}