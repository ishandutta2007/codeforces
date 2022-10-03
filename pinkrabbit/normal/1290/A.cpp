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
int n,m,k,ans;
int a[MN],b[MN],f[MN],g[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d",&n,&m,&k),ans=0;
	if(k>=m)k=m-1;
	F(i,1,n)scanf("%d",a+i);
	F(i,1,m)b[i]=max(a[i],a[i+n-m]);
//	F(i,1,m)printf("%d\n",b[i]);
	F(i,1,k+1){
		int x=inf;
		F(j,1,m-k)x=min(x,b[i+j-1]);
		ans=max(ans,x);
	}
	printf("%d\n",ans);
}	return 0;
}