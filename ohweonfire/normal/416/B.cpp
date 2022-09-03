#include <cstdio>
#include <algorithm>
using namespace std;
int dp[500005][10],tm[50005][10],n,m;
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&tm[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			dp[i][j]=max(dp[i][j-1],dp[i-1][j])+tm[i][j];
	for(int i=1;i<=n;i++)
		printf("%d ",dp[i][m]);
	return 0;
}