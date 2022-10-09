#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll solve()
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for (int i = 0; i < n; ++i) cin >> a[i];
	sort(a.begin(), a.end());
	ll ans = 0, sum = 0;
	for (int i = 1; i < n; ++i)
	{
		ans += a[i] - a[i - 1];
		ans -= i * a[i] - sum;
		sum += a[i];
	}
	return ans;
}

int main()
{
	ios::sync_with_stdio(false);
	int t;
	cin >> t; 
	while (t--)cout << solve() << '\n';
}