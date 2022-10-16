#include <bits/stdc++.h>

using namespace std;

long long fq[3][9],inf=1e18;

int main()
{
	long long i,j,r,k,l,c,z=inf;
	char ch;
	
	for(i=0;i<3;i++)
	{
		scanf("%lld %c",&k,&ch);
		k--;
		l=(ch=='p')+(ch!='m');
		fq[l][k]++;
	}
	for(i=0;i<3;i++)
	{
		for(j=0;j<9;j++)
		{
			z=min(z,3-fq[i][j]);
			if(j<7)
			{
				c=0;
				for(r=j;r<j+3;r++)
				{
					c+=!fq[i][r];
				}
				z=min(z,c);
			}
		}
	}
	printf("%lld\n",z);
}