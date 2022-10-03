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
int a[MN],b[MN],c[MN],d,e;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	d=e=0;
	F(i,1,n)if(a[i]>0)b[++d]=a[i];else c[++e]=a[i];
	if(d+e<5){puts("0");continue;}
	sort(b+1,b+d+1),reverse(b+1,b+d+1);
	sort(c+1,c+e+1);
	ll ans=-infll;
	F(i,0,5){
		ll val=1;
		if(i>d||5-i>e)continue;
		F(j,1,i)val*=b[j];
		F(j,1,5-i)val*=c[j];
//		printf("%d %lld\n",i,val);
		ans=max(ans,val);
	}
	F(i,0,5){
		ll val=1;
		if(i>d||5-i>e)continue;
		F(j,1,i)val*=b[d-j+1];
		F(j,1,5-i)val*=c[e-j+1];
//		printf("%d %lld\n",i,val);
		ans=max(ans,val);
	}
	printf("%lld\n",ans);
}	return 0;
}