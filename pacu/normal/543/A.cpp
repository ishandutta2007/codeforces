#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstdio>
using namespace std;
int A[1000];
long long dp[2][501][501];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int N,M,B,mod;
	cin >> N >> M >> B >> mod;
	for(int i=0;i<N;i++)
		cin >> A[i+1];
	//k = 0
	for(int l=0;l<=M;l++)
		for(int b=0;b<=B;b++)
			dp[0][l][b] = 0;
	dp[0][0][0] = 1;
	//l = 0
	/*
	for(int k=1;k<=N;k++)
		dp[k][0][0] = 1;
	for(int k=1;k<=N;k++)
		for(int b=1;b<=B;b++)
			dp[k][0][b] = 0;
			*/
	int pre = 0;
	int cur = 1;
	for(int k=1;k<=N;k++)
	{
		dp[cur][0][0] = 1;
		for(int b=1;b<=B;b++)
			dp[cur][0][b] = 0;
		for(int l=1;l<=M;l++)
			for(int b=0;b<=B;b++)
			{
				dp[cur][l][b] = dp[pre][l][b];
				if(b >= A[k])
					dp[cur][l][b] = (dp[cur][l][b]+dp[cur][l-1][b-A[k]])%mod;
			}
		swap(cur,pre);
	}
	long long ans = 0;
	for(int b=0;b<=B;b++)
	{
		ans += dp[pre][M][b];
		ans %= mod;
	}
	cout << ans << endl;
	return 0;
}