#include <iostream>
#include <string>
using namespace std;
#define MOD 1000000007

int N,M;
string s;

long long dp[2001][2001];	//[length][depth]

int main()
{
	cin >> N >> M >> s;
	int low = 0;
	int cur = 0;
	for(int i=0;i<M;i++)
	{
		if(s[i]=='(') cur++;
		else cur--;
		low = min(low,cur);
	}
	dp[0][0] = 1;
	for(int l=1;l<=2000;l++)
	{
		dp[l][0] = dp[l-1][1];
		for(int d=1;d<2000;d++)
			dp[l][d] = (dp[l-1][d-1]+dp[l-1][d+1])%MOD;
		dp[l][2000] = dp[l-1][2000-1];
	}
	long long ans = 0;
	for(int l=0;l<=N-M;l++)
		for(int d=-low;d<=2000-cur;d++)
			if(0 <= d && d <= 2000)
				ans = (ans+dp[l][d]*dp[N-M-l][d+cur])%MOD;
	cout << ans << '\n';
}