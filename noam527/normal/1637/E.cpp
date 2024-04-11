#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 998244353;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, m;
vector<int> a;
vector<pair<int, int>> bad;

bool isbad(int x, int y) {
	if (x > y) swap(x, y);
	auto it = lower_bound(bad.begin(), bad.end(), make_pair(x, y));
	if (it == bad.end()) return false;
	if (it->first != x || it->second != y) return false;
	return true;
}

void solve() {
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a) cin >> i;
	bad.resize(m);
	for (auto &i : bad) cin >> i.first >> i.second;
	sort(bad.begin(), bad.end());

	map<int, int> counts;
	for (auto &i : a) counts[i]++;
	vector<int> vcnt;
	for (auto &i : counts)
		vcnt.push_back(i.second);
	sort(vcnt.begin(), vcnt.end());
	vcnt.resize(unique(vcnt.begin(), vcnt.end()) - vcnt.begin());

	vector<vector<int>> v(vcnt.size());
	for (auto &i : counts) {
		int j = lower_bound(vcnt.begin(), vcnt.end(), i.second) - vcnt.begin();
		v[j].push_back(i.first);
	}

	ll ans = -inf;
	for (int i = 0; i < vcnt.size(); i++) for (int j = i; j < vcnt.size(); j++) {
		int cnta = vcnt[i], cntb = vcnt[j];
		for (auto &x : v[i]) {
			for (int k = v[j].size() - 1; k >= 0; k--) {
				int y = v[j][k];
				if (x != y && !isbad(x, y)) {
					ans = max(ans, ll(cnta + cntb) * (x + y));
					break;
				}
			}
		}
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}