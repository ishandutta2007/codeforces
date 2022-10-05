#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;
vector<int> b;
vector<int> fix, got;

pair<int, int> work(int x) {
	int start = x;
	int end = x;
	int iter = 0;
	while (!got[a[x]]) {
		iter = 1;
		fix[x] = 1;
		got[a[x]] = 1;
		x = a[x];
		end = x;
	}
	fix[x] = 1;
	if (start == end && iter == 1) {
		return{ -1, -1 };
	}
	return{ start, end };
}

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, --i;
	b = a;
	fix.resize(n);
	got.resize(n);
	for (int i = 0; i < n; i++)
		fix[i] = got[i] = 0;
	set<int> good, bad;
	for (auto &i : a) good.insert(i);
	for (int i = 0; i < n; i++) if (!good.count(i)) bad.insert(i);
	vector<pair<int, int>> p;
	for (auto &i : bad) {
		if (!fix[i]) {
			auto res = work(i);
			if (res.first != -1)
				p.emplace_back(res);
		}
	}
	if (p.size()) {
		if (p.size() == 1) {
			b[p[0].second] = p[0].first;
		}
		else {
			for (int i = 0; i < p.size(); i++) {
				b[p[i].second] = p[(i + 1) % p.size()].first;
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) if (a[i] == b[i]) cnt++;
	cout << cnt << '\n';
	for (const auto &i : b) cout << i + 1 << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}