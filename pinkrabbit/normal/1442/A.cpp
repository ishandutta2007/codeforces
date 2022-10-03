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
int n,m,q,k;
int a[MN],b[MN],f[MN],g[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	ll s1=0,s2=0;
	F(i,2,n)
		if(a[i-1]>a[i])s1+=a[i-1]-a[i];
		else s2+=a[i]-a[i-1];
//	printf("%lld,%lld\n",s1,s2);
	puts(s1<=a[1]&&s2<=a[n]?"YES":"NO");
}	return 0;
}