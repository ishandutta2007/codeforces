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
	int k; cin >> k;
	std::vector<int> p(k + 1);
	int u = 0;
	vector<int> a(k + 1); for (int o = 1; o <= k; o++) { cin >> p[o]; a[p[o]] = o; }
	for (int j = 0; j < n; ++j) {
		int ti = 0;
		for (int o = 0; o < m; ++o) {
			int y; cin >> y;
			ti += a[y];
			for (int i = a[y]; i >= 2; --i) {
				p[i] = p[i - 1];
				a[p[i]] = i;
			} 
			a[y] = 1;
			p[1] = y;
		}
		u += ti;
	}
	cout << u << "\n";
}