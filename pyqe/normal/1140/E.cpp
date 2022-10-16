#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fr first
#define sc second

long long n,d,a[2][100069],lr[2][100069][2],dp[2][100069][3],z=1,dv=998244353,sz;

int main()
{
	long long i,ii,nn,k;
	
	scanf("%lld%lld",&n,&d);
	for(i=2;i<n+2;i++)
	{
		scanf("%lld",&a[i%2][i/2]);
	}
	for(ii=0;ii<2;ii++)
	{
		nn=(n+!ii)/2+1;
		for(i=0;i<=nn;i++)
		{
			if(a[ii][i]==-1)
			{
				lr[ii][i][0]=lr[ii][i-1][0];
			}
			else
			{
				lr[ii][i][0]=a[ii][i];
			}
			if(a[ii][i]>0&&a[ii][i]==a[ii][i-1])
			{
				printf("0\n");
				return 0;
			}
		}
		for(i=nn;i>=0;i--)
		{
			if(a[ii][i]==-1)
			{
				lr[ii][i][1]=lr[ii][i+1][1];
			}
			else
			{
				lr[ii][i][1]=a[ii][i];
			}
		}
	}
	for(ii=0;ii<2;ii++)
	{
		for(i=0;i<=nn;i++)
		{
			if(a[ii][i]==-1)
			{
				sz=d-2;
				if(lr[ii][i][0]==lr[ii][i][1])
				{
					sz++;
				}
				if(!lr[ii][i][0]||!lr[ii][i][1])
				{
					sz++;
				}
				sz=max((long long)0,sz);
				if(a[ii][i-1]!=-1)
				{
					dp[ii][i-1][0]=1;
					dp[ii][i-1][1]=0;
					dp[ii][i-1][2]=0;
				}
				if(lr[ii][i][0])
				{
					dp[ii][i][0]=(dp[ii][i-1][1]+sz*dp[ii][i-1][2]%dv)%dv;
				}
				else
				{
					dp[ii][i][0]=0;
				}
				if(lr[ii][i][1]&&lr[ii][i][0]!=lr[ii][i][1])
				{
					dp[ii][i][1]=(dp[ii][i-1][0]+sz*dp[ii][i-1][2]%dv)%dv;
				}
				else
				{
					dp[ii][i][1]=0;
				}
				dp[ii][i][2]=((dp[ii][i-1][0]+dp[ii][i-1][1])%dv+(sz-1)*dp[ii][i-1][2]%dv)%dv;
				if(a[ii][i+1]!=-1)
				{
					k=sz*dp[ii][i][2]%dv;
					if(lr[ii][i][0]!=lr[ii][i][1])
					{
						k=(k+dp[ii][i][0])%dv;
					}
					z=z*k%dv;
				}
			}
		}
	}
	printf("%lld\n",z);
}