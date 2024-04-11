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
int n,a[MN];
int vis[MN],stk[MN],tp,k;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d",&n),tp=1;
	F(i,1,n)scanf("%d",a+i),a[i]=i-a[i],vis[i]=0;
	for(int x=1;!(k=vis[x]);x=a[x])stk[vis[x]=++tp]=x;
	printf("%d\n",tp-k+1);
	F(i,k,tp)printf("%d ",stk[i]);puts("");
}	return 0;
}