#include <bits/stdc++.h>

using namespace std;

long long n,a[100069];

int main()
{
	long long i,j,ii,u,mk=(1ll<<30)-1,mx=0,c,z=0;
	
	scanf("%lld",&n);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",a+i);
		mk&=a[i];
	}
	for(i=1;i<=n;i++)
	{
		a[i]^=mk;
		mx=max(mx,a[i]);
	}
	for(c=0;1ll<<c+1<=mx;c++);
	for(i=1;i<=n;i++)
	{
		if(a[i]>>c&1)
		{
			for(ii=0;ii<2;ii++)
			{
				u=!ii*2-1;
				mx=0;
				for(j=i+u;j&&j<=n&&!(a[j]>>c&1);j+=u)
				{
					mx=max(mx,a[j]);
					z=max(z,a[i]^mx);
				}
			}
		}
	}
	printf("%lld\n",z);
}