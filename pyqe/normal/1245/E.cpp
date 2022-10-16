#include <bits/stdc++.h>

using namespace std;

long long ky[10][10],pr[169];
double dp[169];

int main()
{
	long long i,j,k;
	
	for(i=0;i<10;i++)
	{
		for(j=0;j<10;j++)
		{
			ky[i][j]=(9-i)*10;
			if(i%2==1)
			{
				ky[i][j]+=j+1;
			}
			else
			{
				ky[i][j]+=10-j;
			}
			scanf("%lld",&k);
			pr[ky[i][j]]=ky[i-k][j];
		}
	}
	dp[100]=0;
	for(i=99;i>0;i--)
	{
		k=min((long long)6,100-i);
		dp[i]=1;
		for(j=1;j<=k;j++)
		{
			dp[i]+=min(dp[i+j],dp[pr[i+j]])/6;
		}
		dp[i]*=(double)6/k;
	}
	printf("%.10lf\n",dp[1]);
}