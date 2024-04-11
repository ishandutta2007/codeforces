#include <bits/stdc++.h>

using namespace std;

const long long mm=2;
long long n,m0[mm][mm],m1[mm][mm]={{0,1},{2,1}},mz[mm][mm],tmp[mm][mm],pwk,dv=1e9+7;

void cop(long long x[mm][mm],long long y[mm][mm])
{
	long long i,j;
	
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			y[i][j]=x[i][j];
		}
	}
}

void mul(long long x[mm][mm],long long y[mm][mm],long long z[mm][mm])
{
	long long i,j,r;
	
	for(i=0;i<mm;i++)
	{
		for(j=0;j<mm;j++)
		{
			tmp[i][j]=0;
			for(r=0;r<mm;r++)
			{
				tmp[i][j]=(tmp[i][j]+x[i][r]*y[r][j])%dv;
			}
		}
	}
	cop(tmp,z);
}

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
	long long i,k,dn=2;
	
	for(i=0;i<mm;i++)
	{
		m0[i][i]=1;
	}
	scanf("%lld",&n);
	for(i=0;i<n;i++)
	{
		scanf("%lld",&k);
		mpw(k);
		cop(mz,m1);
		dn=pw(dn,k)%dv;
	}
	printf("%lld/%lld\n",mz[0][0]*pw(2,dv-2)%dv,dn*pw(2,dv-2)%dv);
}