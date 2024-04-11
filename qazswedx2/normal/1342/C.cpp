#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
typedef long long ll;
int t,a,b,q,n,f[1000005];
ll getans(ll x)
{
	return 1ll*f[n-1]*(x/n)+f[x%n];
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&a,&b,&q);
		n=a*b;
		for(int i=0;i<n;i++)
			if(i%a%b!=i%b%a) f[i]=1;
			else f[i]=0;
		for(int i=1;i<n;i++)
			f[i]+=f[i-1];
		for(int i=1;i<=q;i++)
		{
			ll l,r;
			scanf("%lld%lld",&l,&r);
			printf("%lld ",getans(r)-getans(l-1));
		}
		printf("\n");
	}
	return 0;
}