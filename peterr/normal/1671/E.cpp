#include <bits/stdc++.h>
 
using namespace std;

const int MOD = 998244353;
const int MAXN = 18;
const int NODES = 1 << MAXN;
string mn[NODES + 1];
int dp[NODES + 1];
string s;

void add(int &x, int y)
{
	x += y;
	if (x >= MOD)
		x -= MOD;
}

void dfs(int v, int n)
{
	if (v * 2 >= (1 << n))
	{
		mn[v] = s[v];
		dp[v] = 1;
	}
	else
	{
		dfs(v * 2, n);
		dfs(v * 2 + 1, n);
		mn[v] = s[v] + mn[v * 2 + 1] + mn[v * 2];
		mn[v] = min(mn[v], s[v] + mn[v * 2] + mn[v * 2 + 1]);
		dp[v] = (int) ((long long) 2 * dp[v * 2] * dp[v * 2 + 1] % MOD);
		if (mn[v * 2] == mn[v * 2 + 1])
			add(dp[v], MOD - (int) ((long long) dp[v * 2] * dp[v * 2] % MOD));
	}
	//cout << "min " << v << " " << mn[v] << endl;
	//cout << "dp " << v << " " << dp[v] << endl;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n >> s;
	s = "d" + s;
	dfs(1, n);
	cout << dp[1] << "\n";
	return 0;
}