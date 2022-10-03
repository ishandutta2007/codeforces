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
int n,m,a[MN],b[MN];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%d",a+i);
	F(i,1,m)scanf("%d",b+i);
	int ans=1, j=n;
	dF(i,m,1){
		while(a[j] > b[i]) --j;
		if(a[j] != b[i]) {ans=0; break;}
		int pos = j;
		while(a[j] >= b[i]) --j;
//		printf("(j,pos)=(%d,%d)\n",j,pos);
		if (i > 1) ans=(ll)ans*(pos-j)%mod;
		else if (j != 0) ans=0;
		else {}
	}
	printf("%d\n",ans);
	return 0;
}