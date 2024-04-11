#include <bits/stdc++.h>

using namespace std;

long long a[2][2];

int main()
{
	long long t,rr,ii,jj,z;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		for(ii=0;ii<2;ii++)
		{
			for(jj=0;jj<2;jj++)
			{
				scanf("%lld",&a[ii][jj]);
			}
		}
		if(a[0][0]*a[1][1]==a[1][0]*a[0][1])
		{
			z=0;
		}
		else if(!a[0][0]||!a[1][0]||a[0][0]*a[1][1]%(a[1][0]*a[0][1])==0||a[1][0]*a[0][1]%(a[0][0]*a[1][1])==0)
		{
			z=1;
		}
		else
		{
			z=2;
		}
		printf("%lld\n",z);
	}
}