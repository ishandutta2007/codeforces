#include <bits/stdc++.h>

using namespace std;

long long n,a[100069],wg[100069];

int main()
{
	long long i,ii,k,l,l2;
	bool bad;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld%lld",a+i,wg+i);
	}
	for(ii=0;ii<2;ii++)
	{
		bad=!ii;
		l=!ii;
		l2=!ii;
		for(i=n;i;i--)
		{
			for(k=wg[i];k>=a[i];k/=2)
			{
				if(!l2)
				{
					bad=1;
					l=1;
					l2=1;
				}
				else
				{
					bad=0;
					l2=!l^k%2;
					l=l2^(k/2+1)%2;
				}
			}
			bad=!l2^(a[i]%2&&!bad);
			l=bad;
			l2=bad;
		}
		printf("%lld%c",(long long)!bad," \n"[ii]);
	}
}