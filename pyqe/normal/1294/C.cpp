#include <bits/stdc++.h>

using namespace std;

long long n,zs,sq[3];

int main()
{
	long long t,rr,i;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		zs=0;
		for(i=2;zs<2&&i*i<=n;i++)
		{
			if(n%i==0)
			{
				sq[zs]=i;
				zs++;
				n/=i;
			}
		}
		sq[2]=n;
		if(zs<2||sq[2]==sq[0]||sq[2]==sq[1]||sq[2]==1)
		{
			printf("NO\n");
		}
		else
		{
			printf("YES\n");
			for(i=0;i<3;i++)
			{
				printf("%lld%c",sq[i]," \n"[i==2]);
			}
		}
	}
}