#include <bits/stdc++.h>

using namespace std;

long long ky[13][1<<12],n,m,a[2069][12],mx[2069][1<<12],dp[2069][1<<12];

int main()
{
	long long i,t,rr,j,k,mk,r,mkk,mkkk;
	
	for(n=1;n<=12;n++)
	{
		for(i=0;i<1<<n;i++)
		{
			ky[n][i]=-1;
		}
		for(i=0;i<1<<n;i++)
		{
			k=i;
			for(j=0;j<n;j++)
			{
				if(ky[n][k]!=-1)
				{
					j=-1;
					break;
				}
				k=(k+(k%2<<n))/2;
			}
			if(j==-1)
			{
				ky[n][i]=ky[n][k];
			}
			else
			{
				ky[n][i]=i;
			}
		}
	}
	scanf("%lld",&t);
	for(rr=0;rr<t;rr++)
	{
		scanf("%lld%lld",&n,&m);
		for(i=0;i<n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&a[j][i]);
			}
		}
		for(i=1;i<=m;i++)
		{
			for(mk=0;mk<1<<n;mk++)
			{
				if(ky[n][mk]!=mk)
				{
					continue;
				}
				mx[i][mk]=0;
				for(j=0;j<n;j++)
				{
					k=0;
					for(r=0;r<n;r++)
					{
						if(mk&1<<r)
						{
							k+=a[i][(j+r)%n];
						}
					}
					mx[i][mk]=max(mx[i][mk],k);
				}
			}
		}
		for(i=1;i<=m;i++)
		{
			for(mk=0;mk<1<<n;mk++)
			{
				if(ky[n][mk]!=mk)
				{
					continue;
				}
				dp[i][mk]=0;
				for(mkk=0;mkk<1<<n;mkk++)
				{
					if((mk&mkk)==mkk)
					{
						mkkk=mk-mkk;
						dp[i][mk]=max(dp[i][mk],dp[i-1][ky[n][mkk]]+mx[i][ky[n][mkkk]]);
					}
				}
			}
		}
		printf("%lld\n",dp[m][(1<<n)-1]);
	}
}