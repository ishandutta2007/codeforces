#include <bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define lsb(x) (x & (-x))

using namespace std;

const int B = (int)1e9 + 7;

int main() {
#ifdef HOME
	ifstream cin("C.in");
	ofstream cout("C.out");
#endif
	int t, i;
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);

	cin >> t;
	while(t--) {
		int n, m; cin >> n >> m;
		vector<ll> c(n + 1);
		vector<pair<ull, int>> hsh(n + 1);
		for(i = 1; i <= n; i++) {
			cin >> c[i];
			hsh[i].second = i;
		}
		vector<vector<int>> g(n + 1);
		for(i = 1; i <= m; i++) {
			int x, y; cin >> x >> y;
			g[y].push_back(x);
		}
		for(i = 1; i <= n; i++) {
			sort(g[i].begin(), g[i].end());
			for(auto it : g[i]) {
				hsh[i].first = hsh[i].first * B + it;
			}
		}
		sort(hsh.begin(), hsh.end());
		ll ans = 0;
		i = 1;
		while(i <= n) {
			int j = i;
			ll cur = 0;
			while(j <= n && hsh[i].first == hsh[j].first) {
				cur += c[hsh[j].second];
				j++;
			}
			if(hsh[i].first != 0) {
				ans = __gcd(ans, cur);
			}
			i = j;
		}
		cout << ans << "\n";
	}

	return 0;
}