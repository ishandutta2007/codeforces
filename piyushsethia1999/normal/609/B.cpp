#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long


using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	std::vector<int> a(m, 0);
	for (int i = 0; i < n; ++i) {
		int j; cin >> j;
		a[j - 1]++;
	}

	int u = 0;
	for (int i = 0; i < m; ++i) {
		u += (n - a[i]) * a[i];
	}
	u /= 2ll;
	cout << u << "\n";
}