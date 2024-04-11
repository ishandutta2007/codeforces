#include <bits/stdc++.h>

using namespace std;

long long n,d,m=0,fq=0,pwk,bc[169],m1[169][169],mz[169][169],tmp[169][169],sq[169],dv=1e9+7;
bitset<169> a;

long long pw(long long x,long long y)
{
	if(y==0)
	{
		return 1;
	}
	pwk=pw(x,y/2);
	pwk=pwk*pwk%dv;
	if(y%2==1)
	{
		pwk=pwk*x%dv;
	}
	return pwk;
}

void pwm(long long y)
{
	long long i,j,r;
	
	if(y==1)
	{
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=m;j++)
			{
				mz[i][j]=m1[i][j];
			}
		}
		return;
	}
	pwm(y/2);
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
		{
			tmp[i][j]=0;
			for(r=0;r<=m;r++)
			{
				tmp[i][j]=(tmp[i][j]+mz[i][r]*mz[r][j])%dv;
			}
		}
	}
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
		{
			mz[i][j]=tmp[i][j];
		}
	}
	if(y%2==1)
	{
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=m;j++)
			{
				tmp[i][j]=0;
				for(r=0;r<=m;r++)
				{
					tmp[i][j]=(tmp[i][j]+mz[i][r]*m1[r][j])%dv;
				}
			}
		}
		for(i=0;i<=m;i++)
		{
			for(j=0;j<=m;j++)
			{
				mz[i][j]=tmp[i][j];
			}
		}
	}
}

int main()
{
	long long i,j,k;
	
	scanf("%lld%lld",&n,&d);
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&k);
		a[i]=k;
		m+=!a[i];
	}
	for(i=1;i<=m;i++)
	{
		fq+=!a[i];
	}
	bc[fq]=1;
	for(i=0;i<=m;i++)
	{
		m1[i][i]=m*(m-1)/2+(n-m)*(n-m-1)/2+i*(m-i)+(m-i)*(n-m-m+i);
		if(i)
		{
			m1[i-1][i]=i*(n-m-m+i);
		}
		if(i<m)
		{
			m1[i+1][i]=(m-i)*(m-i);
		}
	}
	pwm(d);
	for(i=0;i<=m;i++)
	{
		for(j=0;j<=m;j++)
		{
			sq[i]=(sq[i]+mz[i][j]*bc[j])%dv;
		}
	}
	printf("%lld\n",sq[m]*pw(pw(n*(n-1)/2,d),dv-2)%dv);
}