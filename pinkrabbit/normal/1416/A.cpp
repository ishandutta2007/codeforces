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
int n,m,q,k;
int a[MN],b[MN],c[MN],d[MN];
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n),d[0]=n+1;
	F(i,1,n)b[i]=c[i]=0,d[i]=n+1;
	F(i,1,n)scanf("%d",a+i),c[a[i]]=max(c[a[i]],i-b[a[i]]),b[a[i]]=i;
	F(i,1,n)c[i]=max(c[i],n+1-b[i]);
//	F(i,1,n)printf("%d,",c[i]);puts("");
	dF(i,n,1)d[c[i]]=i;
//	F(i,1,n)printf("%d,",d[i]);puts("");
	F(i,1,n)d[i]=min(d[i],d[i-1]),printf("%d%c",d[i]<=n?d[i]:-1," \n"[i==n]);
}	return 0;
}