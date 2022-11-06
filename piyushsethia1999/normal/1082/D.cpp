#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL);
	int n; cin >> n;
	int total = 0;
	int t1 = 0;
	vector<pair<int, int> > a(n); for (int o = 0; o < n; o++) { cin >> a[o].first; total += a[o].first; a[o].second = o + 1; if (a[o].first == 1) {t1++;}}
	sort(a.begin(), a.end());
	if (total < 2 * (n - 1))
	{
		cout << "NO";
		exit(0);
	}
	int diam;
	if (t1 >= 2)
	{
		diam = n - t1 + 2;
	}
	else
	{
		diam = n;
	}
	diam--;
	cout << "YES " << diam << "\n" << n - 1 << "\n";
	for (int i = t1; i < n - 1; ++i)
	{
		cout << a[i].second << " " << a[i + 1].second << "\n";
		a[i].first--;
		a[i + 1].first--;
	}
	if (t1 > 0)
	{
		cout << a[n - 1].second << " " << a[0].second << "\n";
		a[n - 1].first--;
	}
	int y = t1;
	for (int i = 1; i < t1; ++i)
	{
		while (a[y].first == 0)
			y++;
		cout << a[y].second << " " << a[i].second << "\n";
		a[y].first--;
	}
}