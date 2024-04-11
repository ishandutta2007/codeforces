#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <set>
#include <map>
#include <cassert>
#include <queue>
#include <iomanip>

using namespace std;

#define debug(x) cout << #x << " is " << x << '\n';
#define ld long double
#define int long long

const int mod = 1e9 + 7;

int gcd(int a, int b) {
	return (b ? gcd(b, a % b) : a);
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout << fixed << setprecision(8);
	int tt; cin >> tt;
	while (tt --> 0) {
		int n; cin >> n;
		vector <int> a(n);
		for (auto& x : a) cin >> x;
		set <pair <int, int>> cur;
		int ans = 0;
		for (int i = 0; i < n; ++i) {
			cur.insert({ a[i] - gcd(a[i], a[(i + 1) % n]), i });
		}
		while (true) {
			vector <int> add, nw;
			while (cur.lower_bound({ 0, mod }) != cur.end()) {
				auto it = cur.lower_bound({ 0, mod });
				int id = it->second;
				nw.push_back(gcd(a[id], a[(id + 1) % n]));
				add.push_back(id);
				cur.erase(it);
			}
			if (add.empty()) break;
			set <int> was;
			for (auto& x : add) {
				was.insert(x);
			}
			for (int i = 0; i < add.size(); ++i) {
				int i1 = add[i], i2 = (add[i] + n - 1) % n;
				if (gcd(a[i1], a[i2]) != gcd(a[i2], nw[i]) and was.find(i2) == was.end()) {
					cur.erase({ a[i2] - gcd(a[i1], a[i2]), i2 });
					a[i1] = nw[i];
					cur.insert({ a[i2] - gcd(a[i1], a[i2]), i2 });
				}
				a[i1] = nw[i];
			}
			ans++;
			for (auto& x : add) {
				cur.insert({ a[x] - gcd(a[x], a[(x + 1) % n]), x });
			}
		}
		cout << ans << '\n';
	}
	return 0;
}