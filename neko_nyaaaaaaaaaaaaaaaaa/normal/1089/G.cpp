#include <bits/stdc++.h>
#define N 100
#define ll long long
#define pp pair<int, int>
#define fastio ios_base::sync_with_stdio(false), cin.tie(NULL);
#define reset(x, val) memset(x, val, sizeof(x))
#define sort_arr(x, size) sort(x + 1, x + 1 + size);
#define sort_vec(x) sort(x.begin(), x.end());
#define endl '\n'
#define input_file freopen("input.txt", "r", stdin);
#define output_file freopen("output.txt", "w", stdout);
using namespace std;
void solve()
{
	int k; cin >> k;
	vector<int> a(7);
	for (int &i :a) cin >> i;

	int ans = 998244353;
	int sum = accumulate(a.begin(), a.end(), 0);
	for (int st = 0; st < 7; st++) {
		int cnt = 0, days = 0;
		for (int i = st; i < 7; i++) {
			cnt += a[i]; days++;
			if (cnt >= k) break;
		}
		if (cnt >= k) {
			ans = min(ans, days);
			continue;
		}

		int weeks = (k - cnt)/sum;
		if (weeks*sum + cnt == k) weeks--;

		days += weeks*7;
		cnt += weeks*sum;

		for (int i = 0; ; i = (i + 1) % 7) {
			cnt += a[i]; days++;
			if (cnt >= k) break;
		}

		ans = min(ans, days);
	}
	cout << ans << '\n';
}
int main()
{
	fastio;
	int testcase = 1;
	cin >> testcase;
	while (testcase--)
	{
		solve();
	}
	
}