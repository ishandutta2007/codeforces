#include <iostream>
using namespace std;
#define MOD 1000000007

long long dp[2000][2000];	//[k][prev num]
int N;

long long ways(int k,int prev)
{
	if(k==0)
		return 1;
	if(dp[k-1][prev-1]>-1)
		return dp[k-1][prev-1];
	long long ans=0;
	for(int cur=prev;cur<=N;cur+=prev)
	{
		ans += ways(k-1,cur);
		ans %= MOD;
	}
	dp[k-1][prev-1] = ans;
	return ans;
}

int main()
{
	int K;
	cin >> N >> K;
	int i,j;
	for(i=0;i<K;i++)
		for(j=0;j<N;j++)
			dp[i][j] = -1;
	cout << ways(K,1) << endl;
}