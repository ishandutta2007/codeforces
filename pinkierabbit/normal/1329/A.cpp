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
int n,m;
int a[MN],b[MN];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d",a+i);
	int ok=1;
	F(i,1,m)if(i>n-a[i]+1)ok=0;
	if(!ok)return puts("-1"),0;
	ll sum=0;
	F(i,1,m)sum+=a[i];
	if(sum<n)return puts("-1"),0;
	F(i,1,m)b[i]=i;
	int val=n+1;
	dF(i,m,1)if(b[i]+a[i]<val)b[i]=val-a[i],val=b[i];else break;
	F(i,1,m)printf("%d ",b[i]);
	return 0;
}