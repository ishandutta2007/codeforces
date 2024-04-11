#include <bits/stdc++.h>

using namespace std;

long long n,a[2][2];

int main()
{
	long long i,j,ii,jj,z[2];
	
	scanf("%lld",&n);
	for(ii=0;ii<2;ii++)
	{
		for(jj=0;jj<2;jj++)
		{
			scanf("%lld",&a[ii][jj]);
		}
	}
	z[0]=__gcd(abs(a[0][0]),abs(a[1][0]));
	if(!z[0])
	{
		printf("NO\n");
		return 0;
	}
	z[1]=abs(a[0][1]*a[1][0]-a[1][1]*a[0][0])/z[0];
	if(z[1]&&n==z[0]*z[1])
	{
		printf("YES\n");
		for(i=0;i<z[0];i++)
		{
			for(j=0;j<z[1];j++)
			{
				printf("%lld %lld\n",i,j);
			}
		}
	}
	else
	{
		printf("NO\n");
	}
}