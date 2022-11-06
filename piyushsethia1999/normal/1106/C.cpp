#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	sort(a.begin(), a.end());
	int ans = 0;
	for (int i = 0; i < n / 2; ++i)
	{
		ans += (a[i] + a[n - i - 1]) * (a[i] + a[n - i - 1]);
	}
	cout << ans;
}