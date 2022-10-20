#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <stack>
#include <algorithm>
#include <utility>
#include <functional>
#include <bitset>
#include <cmath>
#include <ctime>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#define N 100010
#define INF 1e18
#define forn(i, n) for (int i = 0; i < int(n); i++)
using namespace std;
long long dp[N][5],a[N];
int main(){
	string s,hds="hard";
	long long n,i,j,ans=INF;
	cin>>n>>s;
	for(i=0;i<n;i++)
	{
		cin>>a[i];
	}
	memset(dp,127,sizeof(dp));
	dp[0][0]=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<4;j++)
		{
			if(s[i]==hds[j])
			{
				dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
			}
			else
			{
				dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
			}
			dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]);
		}
	}
	for(i=0;i<4;i++)
	{
		ans=min(ans,dp[n][i]);
	}
	cout<<ans<<endl;
	return 0;
}