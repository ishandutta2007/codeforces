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
int n,m,k;
int a[MN],b[MN];
int c[MN],d[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d",&n,&m,&k);
	F(i,1,k)scanf("%d",a+i);
	F(i,1,k)scanf("%d",b+i);
	F(i,1,n)c[i]=0;
	F(i,1,m)d[i]=0;
	F(i,1,k)++c[a[i]],++d[b[i]];
	ll ans=(ll)k*(k-1);
	F(i,1,k)ans-=c[a[i]]-1+d[b[i]]-1;
	printf("%lld\n",ans/2);
}	return 0;
}