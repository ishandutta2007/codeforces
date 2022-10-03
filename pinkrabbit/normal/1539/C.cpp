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
ll k,x,a[MN],b[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%lld%lld",&n,&k,&x);
	F(i,1,n)scanf("%lld",a+i);
	sort(a+1,a+n+1);
	F(i,2,n){
		ll d=a[i]-a[i-1];
		d=d?(d-1)/x:0;
		b[i-1]=d;
	}
	sort(b+1,b+n);
//	F(i,1,n-1)printf("%lld,",b[i]);puts("");
	int ans=n;
	F(i,1,n-1)if(k>=b[i])k-=b[i],--ans;
	printf("%d\n",ans);
}	return 0;
}