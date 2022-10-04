#include<bits/stdc++.h>
using namespace std;
#define F(i,a,b) for(int i=a;i<=(b);++i)
#define F2(i,a,b) for(int i=a;i<(b);++i)
#define dF(i,a,b) for(int i=a;i>=(b);--i)
#define MN 300005
#define MM 600005
#define ll long long
int n,m,q,k;
ll a[MN],b[MN],f[MN],g[MN];
int main(){
	scanf("%d%d",&n,&m);
	F(i,1,n)scanf("%lld",a+i);
	F(i,1,m)scanf("%lld",b+i);
	sort(a+1,a+n+1);
	ll g=0;
	F(i,2,n)if(a[i]-a[i-1])g=__gcd(g,a[i]-a[i-1]);
	F(i,1,m)if(g%b[i]==0)return printf("YES\n%lld %d\n",a[1],i),0;
	puts("NO");
	return 0;
}