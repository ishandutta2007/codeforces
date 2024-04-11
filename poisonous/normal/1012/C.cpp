#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#include<vector>
#include<map>
#include<set>
#include<stack>
#include<string>
#include<cmath>
#include<cctype>
#include<ctime>
using namespace std;
const int maxlongint=2147483647;
const int inf=1000000000;
int dp[5010][2510][3];
int num[5010];
int main()
{
	int n;
	cin>>n;
	dp[0][0][0]=0;
	dp[0][0][1]=dp[0][0][2]=inf;
	for(int j=1;j<=((n/2)+(n%2))+1;j++)
		dp[0][j][0]=dp[0][j][1]=dp[0][j][2]=inf;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		dp[i][0][0]=0;
		dp[i][0][1]=dp[i][0][2]=inf;
		for(int j=((i/2)+(i%2))+1;j<=((n/2)+(n%2))+1;j++)
			dp[i][j][0]=dp[i][j][1]=dp[i][j][2]=inf;
		for(int j=1;j<=((i/2)+(i%2));j++)
		{
			dp[i][j][0]=min(dp[i-1][j][0],dp[i-1][j][1]);
			dp[i][j][1]=dp[i-1][j][2]+max(0,num[i]-num[i-1]+1);
			if(i==1)
				dp[i][j][2]=0;
			else
				if(i==2)
					dp[i][j][2]=dp[i-1][j-1][0]+max(0,num[i-1]-num[i]+1);
				else
					dp[i][j][2]=min(dp[i-1][j-1][0]+max(0,num[i-1]-num[i]+1),dp[i-1][j-1][1]+max(0,min(num[i-2]-1,num[i-1])-num[i]+1));
			//cout<<i<<' '<<j<<' '<<dp[i][j][0]<<' '<<dp[i][j][1]<<' '<<dp[i][j][2]<<endl;
		}
	}
	for(int j=1;j<=((n/2)+(n%2));j++)
		printf("%d ",min(min(dp[n][j][0],dp[n][j][1]),dp[n][j][2]));
}