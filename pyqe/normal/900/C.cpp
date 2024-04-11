#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,nn=0,a[100069],sk[100069],sq[100069],inf=1e18;
bitset<100069> vtd;

int main()
{
	long long i,j,mx=-inf,c=0,p;
	pair<long long,long long> z={-inf,0};
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		sq[i]=c;
		c+=a[i]>mx;
		mx=max(mx,a[i]);
	}
	mx=n;
	for(i=n;i;i--)
	{
		vtd[a[i]]=1;
		for(;vtd[mx];mx--);
		p=lower_bound(sk+1,sk+nn+1,-mx)-sk;
		sq[i]+=p-1;
		for(;nn&&-sk[nn]<=a[i];nn--);
		nn++;
		sk[nn]=-a[i];
	}
	for(i=1;i<=n;i++)
	{
		z=max(z,{sq[i],-a[i]});
	}
	printf("%lld\n",-z.sc);
}