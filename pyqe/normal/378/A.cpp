#include <bits/stdc++.h>

using namespace std;

long long d[2],sq[3];

int main()
{
	long long i,ii,w[2];
	
	for(ii=0;ii<2;ii++)
	{
		scanf("%lld",d+ii);
	}
	for(i=1;i<=6;i++)
	{
		for(ii=0;ii<2;ii++)
		{
			w[ii]=abs(i-d[ii]);
		}
		sq[(w[0]>=w[1])+(w[0]>w[1])]++;
	}
	for(i=0;i<3;i++)
	{
		printf("%lld%c",sq[i]," \n"[i==2]);
	}
}