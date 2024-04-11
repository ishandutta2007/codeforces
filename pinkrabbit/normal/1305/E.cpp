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
inline int qpow(int b,int e,int m=mod){int a=1;for(;e;e>>=1,b=(ll)b*b%m)if(e&1)a=(ll)a*b%m;return a;}
int n,m,q;
int a[MN],b[MN],f[MN],g[MN];
int main(){int tests=1;//scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	if(n<=2&&m)return puts("-1"),0;
	if(n==1)return puts("1"),0;
	if(n==2)return puts("1 2"),0;
	int z=0;
	F(i,1,n)z+=min(i-1,n-i);
	if(m>z)return puts("-1"),0;
	int k=3,c=1;
	while(c<m)++k,c+=(k-1)/2;
	F(i,1,k-1)printf("%d ",i);
	printf("%d ",k+(c-m)*2);
	int vv=k+(c-m)*2+1;
	F(i,k+1,n)printf("%d ",1000000000-(n-i)*vv);
}	return 0;
}
//200 1000