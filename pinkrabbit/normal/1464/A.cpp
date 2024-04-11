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
int n,m,q,k;
int a[MN],b[MN];
int f[MN],v[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d",&n,&m);
	F(i,1,m)scanf("%d%d",a+i,b+i);
	int ans=0;
	F(i,1,m)if(a[i]!=b[i])++ans;
	F(i,1,n)f[i]=0,v[i]=0;
	F(i,1,m)f[a[i]]=b[i];
	F(i,1,n)if(!v[i]){
		int x=f[i];
		v[i]=1;
		if(x==i)continue;
		while(x&&!v[x])v[x]=1,x=f[x];
		if(x==i)++ans;
	}
	printf("%d\n",ans);
}	return 0;
}