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
ll ans;
void check(){
	int c=0,d=0;
	F(i,1,n)if(a[i])f[++c]=i;
	F(i,1,n)if(b[i])g[++d]=i;
	ll sum=0;
	F(i,1,c)sum+=std::abs(f[i]-g[i]);
	ans=min(ans,sum);
}
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	int s=0;
	F(i,1,n)scanf("%d",a+i),a[i]&=1,s+=a[i];
	if(2*s<n-1||2*s>n+1)puts("-1");
	else{
		ans=1e18;
		if(n&1){
			F(i,1,n)b[i]=(i^(2*s==n-1))&1;
			check();
		}else{
			F(i,1,n)b[i]=i&1;
			check();
			F(i,1,n)b[i]=~i&1;
			check();
		}
		printf("\t%lld\n",ans);
	}
}	return 0;
}