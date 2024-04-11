#include <bits/stdc++.h>

using namespace std;

long long n,ky[3][3]={{1,2,4},{1,2,6},{1,3,6}},fq[8],sq[3];

int main()
{
	long long i,j,r,k,sm=0;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		fq[k]++;
	}
	for(i=0;i<3;i++)
	{
		sq[i]=1e18;
		for(j=0;j<3;j++)
		{
			sq[i]=min(sq[i],fq[ky[i][j]]);
		}
		for(j=0;j<3;j++)
		{
			fq[ky[i][j]]-=sq[i];
		}
		sm+=sq[i];
	}
	if(sm*3!=n)
	{
		printf("-1\n");
	}
	else
	{
		for(i=0;i<3;i++)
		{
			for(j=0;j<sq[i];j++)
			{
				for(r=0;r<3;r++)
				{
					printf("%lld%c",ky[i][r]," \n"[r==2]);
				}
			}
		}
	}
}