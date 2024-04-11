#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <iostream>
#include <deque>
#include <cmath>
#include <string>
using namespace std;
typedef long long LL;
const int maxn=2005;
LL c[maxn],dp[maxn][maxn];
int t[maxn],n;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d%I64d",t+i,c+i);
	for(int i=0;i<=n+1;i++)
	{
		dp[0][i]=1e18;
		dp[i][0]=0;
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			dp[i][j]=min(dp[i-1][j],dp[i-1][max(0,j-t[i]-1)]+c[i]);
	printf("%I64d\n",dp[n][n]);
	return 0;
}