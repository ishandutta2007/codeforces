#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	cout << n + 1 << "\n";
	vector<int> a(n); for (int o = 0; o < n; o++) { cin >> a[o]; }
	int su = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		int y = n + i - ((a[i] + su) % n);
		cout << 1 << " " << i + 1 << " " << y << "\n";
		su += y;
	}
	cout << 2 << " " << n << " " << n;
}