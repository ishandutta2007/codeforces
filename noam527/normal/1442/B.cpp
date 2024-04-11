#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define finish(X) return cout << (X) << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 2e18;
const int OO = 0;
using namespace std;

int n, k;
vector<int> a, b;
vector<int> pos;

void solve() {
	cin >> n >> k;
	a.resize(n);
	b.resize(k);
	pos.resize(n);
	for (auto &i : a) cin >> i, --i;
	for (auto &i : b) cin >> i, --i;
	for (int i = 0; i < n; i++)
		pos[a[i]] = i;
	for (int i = 0; i < k; i++)
		b[i] = pos[b[i]];

	set<int> have, nxt;
	for (int i = 0; i < n; i++)
		have.insert(i);
	for (int i = 0; i < k; i++)
		nxt.insert(b[i]);

	int ans = 1;
	for (auto x : b) {
		if (OO) {
			for (const auto &i : have) cout << i << " "; cout << '\n';
		}
		nxt.erase(x);
		auto it = have.lower_bound(x);
		if (it == have.begin()) {
			auto nit = next(it);
			if (nxt.count(*nit)) {
				cout << "0\n";
				return;
			}
			have.erase(nit);
		}
		else if (next(it) == have.end()) {
			auto pit = prev(it);
			if (nxt.count(*pit)) {
				cout << "0\n";
				return;
			}
			have.erase(pit);
		}
		else {
			auto pit = prev(it), nit = next(it);
			int cp = nxt.count(*pit), cn = nxt.count(*nit);
			if (cp == 1 && cn == 1) {
				cout << "0\n";
				return;
			}
			else if (cp == 0 && cn == 0) {
				ans = 2 * ans % md;
				have.erase(pit);
			}
			else if (cp == 0) {
				have.erase(pit);
			}
			else {
				have.erase(nit);
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) {
		solve();
	}
}