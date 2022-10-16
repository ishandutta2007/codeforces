#include <bits/stdc++.h>

using namespace std;

long long a[2],ti[2];

int main()
{
	long long ii,z[2];
	
	scanf("%lld%lld%lld%lld",a,a+1,ti,ti+1);
	for(ii=0;ii<2;ii++)
	{
		z[ii]=max(a[ii]-a[ii]/250*ti[ii],a[ii]*3/10);
	}
	if(z[0]>z[1])
	{
		printf("Misha\n");
	}
	else if(z[0]<z[1])
	{
		printf("Vasya\n");
	}
	else
	{
		printf("Tie\n");
	}
}