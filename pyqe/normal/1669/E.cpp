#include <bits/stdc++.h>

using namespace std;

const long long mm=11;
long long n,ca[2],fq[2][mm],fq2[mm][mm];

int main()
{
	long long t,rr,i,j,ii,z;
	char ch;
	
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld",&n);
		for(ii=0;ii<2;ii++)
		{
			for(i=0;i<mm;i++)
			{
				fq[ii][i]=0;
			}
		}
		for(i=0;i<mm;i++)
		{
			for(j=0;j<mm;j++)
			{
				fq2[i][j]=0;
			}
		}
		z=0;
		for(i=0;i<n;i++)
		{
			for(ii=0;ii<2;ii++)
			{
				scanf(" %c",&ch);
				ca[ii]=ch-'a';
			}
			for(ii=0;ii<2;ii++)
			{
				z+=fq[ii][ca[ii]]-fq2[ca[0]][ca[1]];
				fq[ii][ca[ii]]++;
			}
			fq2[ca[0]][ca[1]]++;
		}
		printf("%lld\n",z);
	}
}