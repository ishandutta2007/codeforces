#include <bits/stdc++.h>
#define int long long
#define pb push_back

using namespace std;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	int m; cin >> m;
	std::vector<std::vector<int>> a(n, std::vector<int> (m));
	std::vector<std::vector<int>> b(n, std::vector<int> (m));
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> a[i][j];
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j)
			cin >> b[i][j];
	std::vector<std::vector<int> > aa(n + m - 1);
	std::vector<std::vector<int> > bb(n + m - 1);
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < m; ++j) {
			aa[i + j].pb(a[i][j]);
			bb[i + j].pb(b[i][j]);
		}
	for (int i = 0; i < n + m - 1; ++i) {
		sort(aa[i].begin(), aa[i].end()), sort(bb[i].begin(), bb[i].end());
	}
	for (int i = 0; i < (n + m - 1); ++i)
		for (int j = 0; j < aa[i].size(); ++j)
			// cout << aa[i][j] << " " << bb[i][j] << "\n";
			if (aa[i][j] != bb[i][j]) {
				cout << "NO\n";
				exit(0);
			}
	cout << "YES\n";
}