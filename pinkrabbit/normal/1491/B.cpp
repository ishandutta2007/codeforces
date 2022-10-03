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
int n,u,v;
int a[MN],b[MN],f[MN],g[MN];
int ans;
int main(){int tests=1;scanf("%d",&tests);
while(tests--){
	scanf("%d%d%d",&n,&u,&v);
	F(i,1,n)scanf("%d",a+i);
	int ok=0;
	F(i,2,n)if(std::abs(a[i-1]-a[i])>=2)ok=1;
	if(ok){puts("0");continue;}
	ans=inf;
	ok=0;
	F(i,2,n)if(a[i]!=a[1])ok=1;
	if(ok)printf("%d\n",min(u,v));
	else printf("%d\n",v+min(u,v));
}	return 0;
}