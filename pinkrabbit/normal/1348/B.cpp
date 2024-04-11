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
int a[MN],b[MN],d[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&k);
	F(i,1,n)scanf("%d",a+i),b[i]=0;
	F(i,1,n)b[a[i]]=1;
	int c=0;
	F(i,1,n)if(b[i])d[++c]=i;
	if(c>k){puts("-1");continue;}
	printf("%d\n",k*n);
	F(i,1,n){
		F(j,1,c)printf("%d ",d[j]);
		F(j,1,k-c)printf("1 ");
	}
	puts("");
}	return 0;
}