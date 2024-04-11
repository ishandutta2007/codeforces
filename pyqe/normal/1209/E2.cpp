#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long ky[13][1<<12],n,m,aa[2069][12],a[13][12],mx[13][1<<12],dp[13][1<<12];
pair<long long,long long> d[2069];

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
		for(i=1;i<=m;i++)
		{
			d[i]={0,i};
		}
		for(i=0;i<n;i++)
		{
			for(j=1;j<=m;j++)
			{
				scanf("%lld",&aa[j][i]);
				d[j].fr=max(d[j].fr,aa[j][i]);
			}
		}
		sort(d+1,d+m+1,greater<pair<long long,long long>>());
		for(i=1;i<=min(n,m);i++)
		{
			for(j=0;j<n;j++)
			{
				a[i][j]=aa[d[i].sc][j];
			}
		}
		for(i=1;i<=min(n,m);i++)
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
		for(i=1;i<=min(n,m);i++)
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
		printf("%lld\n",dp[min(n,m)][(1<<n)-1]);
	}
}