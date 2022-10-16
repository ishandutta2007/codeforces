#include <bits/stdc++.h>

using namespace std;

const long long mm=100;
long long n,d,a[mm],m0[mm][mm],m1[mm][mm],mz[mm][mm],tmp[mm][mm],dv=1e9+7;

void cop(long long x[mm][mm],long long y[mm][mm])
{
	long long i,j;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			y[i][j]=x[i][j];
		}
	}
}

void mul(long long x[mm][mm],long long y[mm][mm],long long z[mm][mm])
{
	long long i,j,r;
	
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			tmp[i][j]=0;
			for(r=0;r<n;r++)
			{
				tmp[i][j]=(tmp[i][j]+x[i][r]*y[r][j])%dv;
			}
		}
	}
	cop(tmp,z);
}

void mpw(long long x)
{
	if(!x)
	{
		cop(m0,mz);
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
	long long i,j,z=0;
	
	scanf("%lld%lld",&n,&d);
	for(i=0;i<n;i++)
	{
		scanf("%lld",a+i);
		m0[i][i]=1;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			m1[i][j]=__builtin_popcountll(a[i]^a[j])%3==0;
		}
	}
	mpw(d-1);
	for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			z=(z+mz[i][j])%dv;
		}
	}
	printf("%lld\n",z);
	
}