#include <bits/stdc++.h>
using namespace std;
#define SZ(x) ((int)(x).size())

typedef	long long ll;

void solve(void)
{
	int n;
	cin >> n;
	map<int, int> cnt;
	for (int i(0); i < n; ++i)
	{
		int t; cin >> t;
		cnt[t]++;
	}
	int ans(0);
	for (auto [t, c] : cnt)
	{
		if (c > 1)
			ans = max(ans, min(SZ(cnt), c-1));
		ans = max(ans, min(SZ(cnt)-1, c));
	}
	cout << ans << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int __t(1);
	cin >> __t;
	while (__t--)
		solve();
}