#include <bits/stdc++.h>
#define N 25
#define M 1048600
using namespace std;
long long ans=0;
long long n,m,a,b,i,j,k,lb[M]={},dp[M][N]={};
bool ft[N][N]={};
int main(){
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ft[a-1][b-1]=ft[b-1][a-1]=true;
	}
	for(i=1;i<(1<<n);i++)
	{
		j=0;
		while(!(i&(1<<j)))
		{
			j++;
		}
		lb[i]=j;
	}
	for(i=0;i<n;i++)
	{
		dp[(1<<i)][i]=1;
	}
	for(i=0;i<(1<<n);i++)
	{
		for(j=0;j<n;j++)
		{
			if(dp[i][j]<=0)
			{
				continue;
			}
			for(k=lb[i]+1;k<n;k++)
			{
				if(ft[j][k]&&(i&(1<<k))==0)
				{
					dp[i|(1<<k)][k]+=dp[i][j];
				}
			}
		}
	}
	for(i=0;i<(1<<n);i++)
	{
		if(__builtin_popcount(i)<3)
		{
			continue;
		}
		for(j=0;j<n;j++)
		{
			if(ft[j][lb[i]])
			{
				ans+=dp[i][j];
			}
		}
	}
	cout<<ans/2<<endl;
	return 0;
}