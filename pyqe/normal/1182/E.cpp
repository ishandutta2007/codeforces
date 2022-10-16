#include <bits/stdc++.h>

using namespace std;

const long long mm=15;
long long n,d,a[5],pwk,a1[mm],m0[mm][mm],m1[mm][mm],tmp[mm][mm],mz[mm][mm],az[mm],dv=1e9+7;

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

void mul(long long x[mm][mm],long long y[mm][mm],long long z[mm][mm])
{
	long long i,j,r;
	
	for(i=1;i<mm;i++)
	{
		for(j=1;j<mm;j++)
		{
			tmp[i][j]=0;
			for(r=1;r<mm;r++)
			{
				tmp[i][j]=(tmp[i][j]+x[i][r]*y[r][j])%(dv-1);
			}
		}
	}
	for(i=1;i<mm;i++)
	{
		for(j=1;j<mm;j++)
		{
			z[i][j]=tmp[i][j];
		}
	}
}

void mpw(long long x)
{
	if(!x)
	{
		mul(m0,m0,mz);
		return;
	}
	mpw(x/2);
	mul(mz,mz,mz);
	if(x%2)
	{
		mul(mz,m1,mz);
	}
}

int main()
{
	long long i,j,z=1;
	
	for(i=1;i<mm;i++)
	{
		m0[i][i]=1;
	}
	for(i=1;i<=4;i++)
	{
		for(j=i;j<=12;j+=4)
		{
			m1[i][j]=1;
		}
	}
	for(i=1;i<=8;i++)
	{
		m1[i+4][i]=1;
	}
	m1[4][13]=1;
	m1[4][14]=2;
	m1[13][13]=1;
	m1[13][14]=2;
	m1[14][14]=1;
	for(i=3;i<12;i+=3)
	{
		a1[i]=1;
	}
	a1[13]=0;
	a1[14]=1;
	scanf("%lld",&n);
	for(i=1;i<=4;i++)
	{
		scanf("%lld",a+i);
	}
	mpw(n-3);
	for(i=1;i<mm;i++)
	{
		az[i]=0;
		for(j=1;j<mm;j++)
		{
			az[i]=(az[i]+a1[j]*mz[i][j])%(dv-1);
		}
	}
	for(i=1;i<=4;i++)
	{
		z=z*pw(a[i],az[i])%dv;
	}
	printf("%lld\n",z);
}