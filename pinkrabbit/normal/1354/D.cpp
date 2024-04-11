// Author : PinkRabbit
#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define debug(...) fprintf(stderr,__VA_ARGS__)
#define Debug debug("Passing [%s] in LINE %d\n",__FUNCTION__,__LINE__)
#define MN 1000005
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
int n,q;
int b[MN];
inline void add(int i,int x){for(;i<=n;i+=i&-i)b[i]+=x;}
inline int bs(int x){
	--x;
	int i=0,j=19;
	for(;~j;--j)
		if((i|1<<j)<=n&&b[i|1<<j]<=x)
			x-=b[i|=1<<j];
	return i+1;
}
int main(){int x;
	scanf("%d%d",&n,&q);
	F(i,1,n)scanf("%d",&x),add(x,1);
	while(q--){
		scanf("%d",&x);
		if(1<=x)add(x,1);
		else{
			int p=bs(-x);
//			printf("p=%d\n",p);
			add(p,-1);
		}
	}
	F(i,1,n)if(b[i])return printf("%d\n",i),0;
	puts("0");
	return 0;
}