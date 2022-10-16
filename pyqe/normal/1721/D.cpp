#include <bits/stdc++.h>

using namespace std;

const long long mm=30;
long long n,a[2][100069],ca[2][100069];

int main()
{
	long long t,rr,i,j,ii,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=1;i<=n;i++)
			{
				scanf("%lld",&a[ii][i]);
				if(ii)
				{
					a[ii][i]^=(1ll<<mm)-1;
				}
			}
		}
		z=0;
		for(i=mm-1;i>=0;i--)
		{
			z|=1ll<<i;
			for(ii=0;ii<2;ii++)
			{
				for(j=1;j<=n;j++)
				{
					ca[ii][j]=a[ii][j]&z;
				}
				sort(ca[ii]+1,ca[ii]+n+1);
			}
			for(j=1;j<=n;j++)
			{
				if(ca[0][j]!=ca[1][j])
				{
					break;
				}
			}
			if(j<=n)
			{
				z^=1ll<<i;
			}
		}
		printf("%lld\n",z);
	}
}