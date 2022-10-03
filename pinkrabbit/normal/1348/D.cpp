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
int n,b[50];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	int k=31-__builtin_clz(n);
//	printf("k=%d\n",k);
	F(i,0,k)b[i]=1<<i;
	int dif=((2<<k)-1)-n;
//	printf("dif=%d\n",dif);
	dF(i,k,1){
		if(dif<=(1<<(i-1)))b[i]-=dif,dif=0;
		else b[i]=1<<(i-1),dif-=1<<(i-1);
	}
//	F(i,0,k)printf("%d,",b[i]);puts("");
	printf("%d\n",k);
	F(i,1,k)printf("%d ",b[i]-b[i-1]);
	puts("");
}	return 0;
}