#include <bits/stdc++.h>

using namespace std;

long long n,dp[200069][10],z[4],b[4],b2;
priority_queue<long long> pq;

int main()
{
	long long i,j,d,ky,k,it,jj,zzz=0;
	
	scanf("%lld",&n);
	for(i=0;i<=n;i++)
	{
		for(j=0;j<10;j++)
		{
			dp[i][j]=-1;
		}
	}
	dp[0][0]=0;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&d);
		for(;!pq.empty();pq.pop());
		z[1]=0;
		b2=-1;
		for(j=0;j<d;j++)
		{
			scanf("%lld%lld",&ky,&k);
			if(ky==1)
			{
				pq.push(k);
			}
			else if(ky==2)
			{
				b2=max(b2,k);
			}
			z[1]=max(z[1],k);
		}
		b[1]=z[1];
		if(pq.empty())
		{
			z[2]=-1;
			z[3]=-1;
		}
		else
		{
			z[2]=pq.top();
			b[2]=z[2];
			z[3]=z[2];
			b[3]=z[3];
			pq.pop();
			if(pq.empty())
			{
				z[3]=-1;
				if(b2==-1)
				{
					z[2]=-1;
				}
				else
				{
					z[2]+=b2;
					b[2]=max(b[2],b2);
				}
			}
			else
			{
				z[2]+=max(pq.top(),b2);
				b[2]=max(b[2],b2);
				z[3]+=pq.top();
				pq.pop();
				if(pq.empty())
				{
					z[3]=-1;
				}
				else
				{
					z[3]+=pq.top();
				}
			}
		}
		for(j=0;j<10;j++)
		{
			for(it=0;it<=3;it++)
			{
				if(z[it]==-1)
				{
					continue;
				}
				jj=(j+10-it)%10;
				k=dp[i-1][jj]+z[it];
				if(jj>j)
				{
					k+=b[it];
				}
				if(dp[i-1][jj]>=0)
				{
					dp[i][j]=max(dp[i][j],k);
				}
			}
			if(i==n)
			{
				zzz=max(zzz,dp[i][j]);
			}
		}
	}
	printf("%lld\n",zzz);
}