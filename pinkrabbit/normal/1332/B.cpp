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
int n,m,q,k;
int a[MN],b[MN],c[MN];
const int pp[11]={2,3,5,7,11,13,17,19,23,29,31};
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n);
	F(i,1,n)scanf("%d",a+i);
	F(j,0,10)b[j]=0;
	F(i,1,n){
		F(j,0,10)if(a[i]%pp[j]==0){c[i]=j;break;}
		b[c[i]]=1;
	}
	F(j,1,10)b[j]+=b[j-1];
	printf("%d\n",b[10]);
	F(i,1,n)printf("%d ",b[c[i]]);puts("");
}	return 0;
}