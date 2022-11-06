#include <bits/stdc++.h>
#define pb emplace_back
#define mp make_pair
#define int long long

using namespace std;

int MAXN = 3000000;

int32_t main()
{
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10);
	int n; cin >> n;
	vector<int> a(MAXN + 1, 0); for (int o = 0; o < n; o++) { int op; cin >> op; a[op]++; }
	std::vector<int> p(MAXN + 2, 0);
	int res = 0;
	for (int i = 1; i <= MAXN; ++i) {
		if (a[i]) {
			for (int j = 1; j * i <= MAXN; ++j) {
				if (j != i) {
					p[j * i] += (a[j] * a[i]);
				} else {
					p[j * i] += (a[j] * (a[j] - 1));
				}
			}
		} 
		res += p[i];
	}
	res = n * (n - 1ll) - res;
	p[MAXN + 1] += res;
	for (int i = MAXN; i >= 1; --i) {
		p[i] += p[i + 1];
	} 
	int m; cin >> m;
	for (int i = 0; i < m; ++i) {
		int u; cin >> u;
		cout << p[u] << "\n";
	}
}