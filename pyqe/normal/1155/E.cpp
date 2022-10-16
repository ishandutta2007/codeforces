#include <bits/stdc++.h>

using namespace std;

long long a[11],ge[11][11],pwk,dv=1e6+3;

long long pw(long long x,long long y)
{
	if(!y)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

int main()
{
	long long i,j,r,k,sm,z;
	
	for(i=0;i<=10;i++)
	{
		printf("? %lld\n",i);
		fflush(stdout);
		scanf("%lld",a+i);
		sm=1;
		for(j=0;j<=10;j++)
		{
			ge[i][j]=sm;
			sm=sm*i%dv;
		}
		for(j=0;j<i;j++)
		{
			k=ge[i][j];
			a[i]=(a[i]+dv-a[j]*k%dv)%dv;
			for(r=j;r<=10;r++)
			{
				ge[i][r]=(ge[i][r]+dv-ge[j][r]*k%dv)%dv;
			}
		}
		k=pw(ge[i][i],dv-2);
		a[i]=a[i]*k%dv;
		for(j=i;j<=10;j++)
		{
			ge[i][j]=ge[i][j]*k%dv;
		}
	}
	for(i=10;i+1;i--)
	{
		for(j=i+1;j<=10;j++)
		{
			a[i]=(a[i]+dv-a[j]*ge[i][j]%dv)%dv;
			ge[i][j]=0;
		}
	}
	for(i=0;i<dv;i++)
	{
		sm=1;
		z=0;
		for(j=0;j<=10;j++)
		{
			z=(z+a[j]*sm)%dv;
			sm=sm*i%dv;
		}
		if(!z)
		{
			printf("! %lld\n",i);
			fflush(stdout);
			return 0;
		}
	}
	printf("! -1\n");
	fflush(stdout);
}