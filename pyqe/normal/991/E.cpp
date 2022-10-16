#include <bits/stdc++.h>

using namespace std;

long long n,fq[10],dp[1069],fc[69];

long long cb(long long x,long long y)
{
	return fc[x]/fc[y]/fc[x-y];
}

int main()
{
	long long ln=0,i,j,r,ii,k,z=0;
	
	fc[0]=1;
	for(i=1;i<=20;i++)
	{
		fc[i]=fc[i-1]*i;
	}
	scanf("%lld",&n);
	for(;n;n/=10,ln++)
	{
		fq[n%10]++;
	}
	for(ii=0;ii<2;ii++)
	{
		fq[0]-=ii;
		if(fq[0]+1)
		{
			for(i=1;i<=ln;i++)
			{
				dp[i]=0;
			}
			dp[0]=1;
			for(i=0;i<10;i++)
			{
				for(j=ln;j+1;j--)
				{
					if(fq[i]+(ii&&!i))
					{
						k=0;
						for(r=1-(ii&&!i);r<=min(fq[i],j);r++)
						{
							k+=dp[j-r]*cb(j,r);
						}
						dp[j]=k;
					}
					if(i==9)
					{
						z+=dp[j];
					}
				}
			}
		}
		fq[0]+=ii;
		z*=-1;
	}
	printf("%lld\n",z);
}