#include <bits/stdc++.h>
using namespace std;

typedef	long long ll;

const int MAXN = 2e5;

void solve(void)
{
	int n;
	cin >> n;
	vector<ll> a(n);
	for (auto &v : a)
		cin >> v;

	set<ll> missing;
	for (int i(0); i < n; ++i)
	{
		if (a[i] != -1) continue;
		if (i and a[i-1] != -1)
			missing.insert(a[i-1]);
		if (i != n-1 and a[i+1] != -1)
			missing.insert(a[i+1]);
	}

	if (missing.size() == 0)
	{
		cout << 0 << ' ' << 0 << '\n';
		return ;
	}
	
	ll small = *missing.begin();
	ll big = *missing.rbegin();

	ll k = (small+big)/2;
	ll b = max(big  - k, k - small);
	for (int i(0); i < n-1; ++i)
		if (a[i] != -1 and a[i+1] != -1)
			b = max(b, abs(a[i+1] - a[i]));

	cout << b << ' ' << k << '\n';
}

int main(void)
{
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	
	int t;
	cin >> t;
	while (t--)
		solve();
}