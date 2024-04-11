#include <bits/stdc++.h>

using namespace std;

long long n,m,fq[2][1069],pwk;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk*=pwk;
	if(y%2)
	{
		pwk*=x;
	}
	return pwk;
}

int main()
{
	long long i,j,ii,k,z=0;
	
	scanf("%lld%lld",&n,&m);
	for(i=1;i<=n;i++)
	{
		for(j=1;j<=m;j++)
		{
			scanf("%lld",&k);
			fq[0][i]+=k;
			fq[1][j]+=k;
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=1;i<=n;i++)
		{
			z+=pw(2,fq[ii][i])-1+pw(2,m-fq[ii][i])-1;
		}
		swap(n,m);
	}
	z-=n*m;
	printf("%lld\n",z);
}