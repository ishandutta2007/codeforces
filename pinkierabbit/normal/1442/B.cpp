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
int n,k;
int a[MN],ia[MN],b[MN],c[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%d",a+i),ia[a[i]]=i;
	F(i,1,k)scanf("%d",b+i),b[i]=ia[b[i]];
//	F(i,1,k)printf("%d,",b[i]);puts("");
	F(i,1,n)c[i]=0;
	F(i,1,k)c[b[i]]=i;
	c[0]=c[n+1]=k+1;
	int ans=1;
	F(i,1,k){
		int x=0;
		x+=c[b[i]-1]<i;
		x+=c[b[i]+1]<i;
		if(!x)ans=0;
		else if(x==2)ans=ans*2%mod;
	}
	printf("%d\n",ans);
}	return 0;
}