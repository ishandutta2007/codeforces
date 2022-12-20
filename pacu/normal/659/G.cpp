#include <iostream>
using namespace std;
#define MOD 1000000007

int N;
int h[1000000];
int both[1000000];
int l[1000000];
int r[1000000];
long long dp[1000000];

int main()
{
	ios::sync_with_stdio(0);
	cin >> N;
	for(int i=0;i<N;i++)
	{
		cin >> h[i];
		h[i]--;
	}
	for(int i=0;i<N;i++)
	{
		l[i] = r[i] = h[i];
		if(i>0) r[i] = min(r[i],h[i-1]);
		if(i<N-1) l[i] = min(l[i],h[i+1]);
		both[i] = min(l[i],r[i]);
	}
	dp[0] = l[0];
	for(int i=1;i<N;i++)
		dp[i] = (dp[i-1]*both[i]+l[i])%MOD;
	long long ans = 0;
	for(int i=0;i<N-1;i++)
		ans = (ans + dp[i]*r[i+1])%MOD;
	for(int i=0;i<N;i++)
		ans = (ans + h[i])%MOD;
	cout << ans << '\n';
}