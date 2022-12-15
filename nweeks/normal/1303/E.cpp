#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 401;


int dp[MAXN][MAXN];
int closest[MAXN][26];

bool can(string s, string a, string b)
{
	int n1 = a.length();
	int n2 = b.length();
	
	for (int i(0); i <= n1; ++i)
		for (int j(0); j <= n2; ++j)
			dp[i][j] = 1e9;

	dp[0][0] = 0;
	for (int x(0); x <= n1; ++x)
		for (int y(0); y <= n2; ++y)
		{
			if (dp[x][y] == 1e9) continue;
			int cur = dp[x][y];
			
			if (y != n2)
				dp[x][y+1] = min(dp[x][y+1], closest[cur][b[y] -'a']+1);
			if (x != n1)
				dp[x+1][y] = min(dp[x+1][y], closest[cur][a[x]-'a']+1);
		}

	return dp[n1][n2] < 1e9;
}

bool is_sub(string s, string t)
{
	int cur(0);
	for (int i(0); i < s.size(); ++i)
		if (cur < t.size() and s[i] == t[cur])
			++cur;
	return cur == t.size();
}

void solve(void)
{
	string s;
	string t;
	cin >> s >> t;
	for (int i(0); i < 26; ++i)
		closest[s.size()][i] = 1e9;
	for (int i(s.size() - 1); i >= 0; --i)
	{
		for (int c(0); c < 26; ++c)
		{
			closest[i][c] = closest[i+1][c];
			if (c+'a' == s[i])
				closest[i][c] = i;
		}
	}

	if (is_sub(s, t))
	{
		cout << "YES\n";
		return ;
	}

	for (int k(1); k < t.size(); ++k)
	{
		string a = t.substr(0, k);
		string b = t.substr(k, t.size()-k);
		if (can(s, a, b))
		{
			cout << "YES" << '\n';
			return ;
		}
	}
	cout << "NO\n";
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int t; cin >> t;
	while (t--)
		solve();
}