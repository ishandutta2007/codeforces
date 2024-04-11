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
int n;
int a[MN],b[MN];
vector<int>c;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%1d",a+i);
	F(i,1,n)scanf("%1d",b+i);
	c.clear();
	int l=1,r=n,rev=0,flp=0;
	dF(i,n,1){
		int nbit=flp^(rev?a[r]:a[l]);
		if(nbit==b[i])c.pb(1);
		c.pb(i);
		if(rev)--r;
		else ++l;
		rev^=1,flp^=1;
	}
	printf("\t\t\t%d ",(int)c.size());
	for(int x:c)printf("%d ",x);
	puts("");
}	return 0;
}