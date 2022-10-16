#include <bits/stdc++.h>

using namespace std;

const long long mm=2;
long long n,nn=0,a1[mm+1],m0[mm+1][mm+1],m1[mm+1][mm+1],tmp[mm+1][mm+1],mz[mm+1][mm+1],az[mm+1],dv;
queue<long long> q;

void mul(long long x[mm+1][mm+1],long long y[mm+1][mm+1],long long z[mm+1][mm+1])
{
	long long i,j,r;
	
	for(i=1;i<=mm;i++)
	{
		for(j=1;j<=mm;j++)
		{
			tmp[i][j]=0;
			for(r=1;r<=mm;r++)
			{
				tmp[i][j]=(tmp[i][j]+x[i][r]*y[r][j])%dv;
			}
		}
	}
	for(i=1;i<=mm;i++)
	{
		for(j=1;j<=mm;j++)
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
	long long i,j,lb,rb,ln,k,z;
	
	for(i=1;i<=mm;i++)
	{
		m0[i][i]=1;
	}
	scanf("%lld%lld%lld%lld",&dv,&lb,&rb,&n);
	ln=rb-lb+1;
	if(ln/n<=1000000)
	{
		for(i=(ln-1)/(n-1);i>=ln/n;i--)
		{
			if(rb/i-(lb-1)/i>=n)
			{
				z=i;
				break;
			}
		}
	}
	else
	{
		for(i=1;1;i++)
		{
			for(;nn&&q.front()>rb/i;q.pop(),nn--);
			q.push((lb-1)/i+1);
			nn++;
			if(nn>=n)
			{
				z=rb/i;
				break;
			}
		}
	}
	a1[1]=1;
	m1[1][1]=1;
	m1[1][2]=1;
	m1[2][1]=1;
	mpw(z-1);
	for(i=1;i<=mm;i++)
	{
		for(j=1;j<=mm;j++)
		{
			az[i]=(az[i]+a1[j]*mz[i][j])%dv;
		}
	}
	printf("%lld\n",az[1]);
}