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
int n,a[MN],b[MN];
int main(){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i),++b[a[i]];
	F(i,1,n)if(b[i]!=1)return puts("-1"),0;
	ll ans=1;
	F(i,1,n){
		int x=a[i],t=1;
		while(x!=i)++t,x=a[x];
		if(~t&1)t/=2;
		ans=ans/__gcd(ans,(ll)t)*t;
	}
	printf("%lld\n",ans);
	return 0;
}