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
		solve();
}

ll solve(void)
{
	int n;
	cin >> n;
	vector<int> s(n);
	for (auto &v : s)
		cin >> v;
	sort(s.begin(), s.end());
	int ans(1e9);
	for (int i(0); i+1 < n; ++i)
		ans = min(ans, s[i+1] - s[i]);
	cout << ans << '\n';

	return 0;
}