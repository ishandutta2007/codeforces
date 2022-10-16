#include <bits/stdc++.h>

using namespace std;

long long n,m,a[169],ky[169][169],mx[169][169],tmp[169][169],z,dv=1e9+7,c=0;

void pwm(long long b)
{
	long long i,j,r;
	
	if(b==1)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				mx[i][j]=ky[i][j];
				c++;
			}
		}
		return;
	}
	pwm(b/2);
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			tmp[i][j]=0;
			for(r=0;r<m;r++)
			{
				tmp[i][j]+=mx[i][r]*mx[r][j];
				tmp[i][j]%=dv;
				c++;
			}
		}
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<m;j++)
		{
			mx[i][j]=tmp[i][j];
			c++;
		}
	}
	if(b%2==1)
	{
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				tmp[i][j]=0;
				for(r=0;r<m;r++)
				{
					tmp[i][j]+=mx[i][r]*ky[r][j];
					tmp[i][j]%=dv;
					c++;
				}
			}
		}
		for(i=0;i<m;i++)
		{
			for(j=0;j<m;j++)
			{
				mx[i][j]=tmp[i][j];
				c++;
			}
		}
	}
}

int main()
{
	long long i,j;
	
	scanf("%lld%lld",&n,&m);
	if(n<m)
	{
		printf("1\n");
		return 0;
	}
	for(i=0;i<m;i++)
	{
		a[i]=1;
		for(j=0;j<m;j++)
		{
			if((i==0&&(j==0||j==m-1))||i-1==j)
			{
				ky[i][j]=1;
			}
			c++;
		}
	}
	pwm(n-m+1);
	for(i=0;i<m;i++)
	{
		z+=mx[0][i]*a[i];
		z%=dv;
	}
	printf("%lld\n",z);
}