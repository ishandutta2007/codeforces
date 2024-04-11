#include <bits/stdc++.h>
using namespace std;

#define SZ(v) ((int)(v).size())
using ll = long long;

ll solve(void);

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

	int nb_tests;
	cin >> nb_tests;

	for (int i(0); i < nb_tests; ++i)
		cout << solve() << '\n';
}

ll solve(void)
{
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	vector<int> suffix(n+1);
	suffix[n]=0;
	for (int i(n-1); i >= 0; --i)
		suffix[i] = suffix[i+1] + (s[i]=='1');
	int ans(n);

	vector<int> dp(n);

	for (int start(n-1); start >= 0; --start)
	{
		int cur_ans = suffix[start+1] + (s[start]=='0');
		if (start + k < n)
			cur_ans = min(cur_ans, dp[start+k] + (s[start] == '0') - suffix[start+k] + suffix[start+1]);
		dp[start] = cur_ans;
	}
	int nb_un_avant(0);
	for (int i(0); i < n; ++i)
	{
	//	cout << dp[i] << ' ';
		ans = min(ans, nb_un_avant + dp[i]);
		nb_un_avant += s[i]=='1';
	}
	ans = min(ans, nb_un_avant);

	return ans;
}