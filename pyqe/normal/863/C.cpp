#include <bits/stdc++.h>

using namespace std;

long long n,a[2][3][3],ls[3][3],ps[2][10];

int main()
{
	long long i,j,ii,p[2],tg[2],cl,cd,z;
	
	scanf("%lld%lld%lld",&n,p,p+1);
	for(ii=0;ii<2;ii++)
	{
		p[ii]--;
		for(i=0;i<3;i++)
		{
			for(j=0;j<3;j++)
			{
				scanf("%lld",&a[ii][i][j]);
				a[ii][i][j]--;
				ls[i][j]=-1;
			}
		}
	}
	for(i=0;ls[p[0]][p[1]]==-1;i++)
	{
		ls[p[0]][p[1]]=i;
		for(ii=0;ii<2;ii++)
		{
			ps[ii][i+1]=ps[ii][i];
			tg[ii]=a[ii][p[0]][p[1]];
		}
		if(p[0]!=p[1])
		{
			ps[2-(p[1]+3-p[0])%3][i+1]++;
		}
		for(ii=0;ii<2;ii++)
		{
			p[ii]=tg[ii];
		}
	}
	cl=i-ls[p[0]][p[1]];
	cd=ls[p[0]][p[1]];
	for(ii=0;ii<2;ii++)
	{
		if(n<cd)
		{
			z=ps[ii][n];
		}
		else
		{
			z=(ps[ii][i]-ps[ii][cd])*((n-cd)/cl)+ps[ii][(n-cd)%cl+cd];
		}
		printf("%lld%c",z," \n"[ii]);
	}
}