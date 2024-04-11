#include <bits/stdc++.h>
#define pb emplace_back
#define fi first
#define se second
#define int long long
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n; cin >> n;
	int m; cin >> m;
	int k; cin >> k;
	std::vector<int> bl(n + 1, 0);
	for (int i = 0; i < m; ++i) {
		int y; cin >> y; bl[y] = 1;
		if (y == 0) {
			cout << -1;
			return 0;
		} 
	}
	std::vector<int> rm(n + 2, n + 1);
	for (int i = n; i >= 0; --i) {
		if (!bl[i]) 
			rm[i] = i;
		else
			rm[i] = rm[i + 1];
	}
	std::vector<int> lm(n + 2, -1);
	lm[0] = ((bl[0]) ? -1 : 0);
	for (int i = 1; i <= n; ++i) {
		if (!bl[i]) 
			lm[i] = i;
		else
			lm[i] = lm[i - 1];
	}
	int ma = 0;
	int cn = 0;
	for (int i = 0; i <= n; ++i) {
		if (bl[i]) {
			cn++;
		} else {
			cn = 0;
		}
		ma = max(ma, cn);
	}
	if (ma + 1 > k) {
		cout << -1;
		return 0;
	}
	int y = 10000000000000ll;
	vector<int> a(k); for (int o = 0; o < k; o++) { cin >> a[o]; }
	for (int i = max(ma + 1, 1ll); i <= k; ++i) {
		int st = 0;
		cn = 0;
		while (st < n) {
			if (!bl[st]) {
				cn++;
				st = st + i;
			} else {
				cn++;
				st = lm[st] + i;
			}
		} 
		y = min(y, cn * a[i - 1]);
	}
	cout << y;
}