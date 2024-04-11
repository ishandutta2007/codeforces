#include <bits/stdc++.h>

using namespace std;

long long n,fq[3][3],pm[3]={0,1,2},inf=1e18;
string ky="RGB";

int main()
{
	long long i,j,sm,e[3],z=inf;
	char ch;
	
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf(" %c",&ch);
		for(j=0;ky[j]!=ch;j++);
		fq[i%3][j]++;
	}
	for(;1;)
	{
		sm=n;
		for(i=0;i<3;i++)
		{
			sm-=fq[i][pm[i]];
		}
		if(sm<z)
		{
			z=sm;
			for(i=0;i<3;i++)
			{
				e[i]=pm[i];
			}
		}
		if(!next_permutation(pm,pm+3))
		{
			break;
		}
	}
	printf("%lld\n",z);
	for(i=0;i<n;i++)
	{
		printf("%c",ky[e[i%3]]);
	}
	printf("\n");
}