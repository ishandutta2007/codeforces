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

	vector<int> a(n), b(n);
	for (auto &v : a) cin >> v;
	for (auto &v : b) cin >> v;

	sort(a.begin(), a.end());
	sort(b.rbegin(), b.rend());

	ll ans(0);
	ll tot_sum(0);
	for (auto v : a) tot_sum += v;
	ans = tot_sum;
	for (int take(1); take <= k; ++take)
	{
		tot_sum += b[take-1];
		tot_sum -= a[take-1];
		ans = max(ans, tot_sum);
	}
	return ans;
}