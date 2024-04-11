#include <bits/stdc++.h>

using namespace std;

long long n,d,a[2],wg[2];

int main()
{
	long long i,j,z;
	
	scanf("%lld%lld%lld%lld%lld%lld",&d,&n,a,a+1,wg,wg+1);
	for(i=-1;i<n;i++)
	{
		for(j=-1;j<n;j++)
		{
			z=(a[0]-wg[0]*i)*!!(i+1)+(a[1]-wg[1]*j)*!!(j+1);
			if(z==d)
			{
				printf("YES\n");
				return 0;
			}
		}
	}
	printf("NO\n");
}