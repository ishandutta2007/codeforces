#include <bits/stdc++.h>

using namespace std;

const int N = 5e5 + 50;

typedef long long ll;

ll n, a[N];

inline void solve()
{
	cin >> n;
	long long sum = 0;
	for (int i = 1; i <= n; ++i)
	{
		cin >> a[i];
		sum += a[i];
	}
	if ((2 * sum) % n != 0)
	{
		cout << 0 << endl;
		return;
	}
	map<long long, int> mp;
	long long ans = 0, r = 2 * sum / n;
	for (int i = 1; i <= n; ++i)
	{
		if (mp.count(r - a[i])) 
		{
			ans += mp[r - a[i]];
		}
		++mp[a[i]];
	}
	cout << ans << endl;

}

int main()
{
	srand(time(0));
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	int t;
	cin >> t;
	while (t--)
	{
		solve();
	}
}