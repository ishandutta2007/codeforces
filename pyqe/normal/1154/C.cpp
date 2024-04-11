#include <bits/stdc++.h>

using namespace std;

long long aa[3],a[3],ky[7]={0,1,2,0,2,1,0},inf=1e18;

int main()
{
	long long i,j,mn=inf,z=-inf;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld",aa+i);
		mn=min(mn,aa[i]/(2+!i));
	}
	for(i=0;i<3;i++)
	{
		aa[i]-=mn*(2+!i);
	}
	for(i=0;i<7;i++)
	{
		for(j=0;j<3;j++)
		{
			a[j]=aa[j];
		}
		for(j=0;a[ky[(i+j)%7]];a[ky[(i+j)%7]]--,j++);
		z=max(z,j);
	}
	printf("%lld\n",mn*7+z);
}