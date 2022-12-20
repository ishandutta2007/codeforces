#include <iostream>
#include <algorithm>
using namespace std;
#define DIF 250000
#define MOD 1000000007

long long dp[500000][2];
long long sm[500000];
int a,b,k,t;

int main()
{
	cin >> a >> b >> k >> t;
	dp[a-b+DIF][0] = 1;
	int cur = 0;
	int nxt = 1;
	for(int turn=1;turn<=t;turn++,swap(cur,nxt))
	{
		sm[2*k] = 0;
		for(int i=2*k-DIF+1;i<=DIF-2*k;i++)
			sm[i+DIF] = (sm[i-1+DIF]+dp[i+DIF][cur]+MOD-dp[i-2*k-1+DIF][cur])%MOD;
		
		dp[2*k][nxt] = 0;
		for(int i=2*k-DIF+1;i<=DIF-2*k;i++)
		{
			dp[i+DIF][nxt] = (dp[i-1+DIF][nxt]+MOD-sm[i-1+DIF]+sm[i+2*k+DIF])%MOD;
		}
	}
	long long ans = 0;
	for(int i=1;i<=2*k*t+200;i++)
		ans = (ans + dp[i+DIF][cur])%MOD;
	cout << ans << '\n';
}