#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

int n;
string s;
vector<int> L;
vector<int> pos[500005];
set<int> p;
ll cur;

void solve() {
	cin >> n >> s;
	if (*max_element(s.begin(), s.end()) == '0') {
		cout << "0\n";
		return;
	}
	ll ans = 0;

	L.resize(n);
	cur = 0;
	if (s[n - 1] == '1') L[n - 1] = 1;
	else L[n - 1] = 0;
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == '0') L[i] = 0;
		else L[i] = 1 + L[i + 1];
	}
	for (int i = 0; i < n; i++) {
		pos[L[i]].push_back(i);
	}

	int k = n + 1;
	while (pos[k].size() == 0) k--;
	for (int i = 0; i < pos[k].size(); i++) {
		p.insert(pos[k][i]);

		if (i == 0) {
			cur += ll(n - pos[k][i] - k + 1) * (pos[k][i] + 1);
		}
		else {
			cur += ll(n - pos[k][i] - k + 1) * (pos[k][i] - pos[k][i - 1]);
		}
	}
	ans += cur;
	while (k > 1) {
		k--;
		cur += *p.rbegin() + 1;
		for (const auto &x : pos[k]) {
			if (x < *p.begin()) {
				int p0 = *p.begin();
				cur -= ll(n - p0 - k + 1) * (p0 + 1);
				cur += ll(n - x - k + 1) * (x + 1);
				cur += ll(n - p0 - k + 1) * (p0 - x);
			}
			else if (x > *p.rbegin()) {
				int plast = *p.rbegin();
				cur += ll(n - x - k + 1) * (x - plast);
			}
			else {
				auto it = p.upper_bound(x);
				int nxt = *it, pre = *prev(it);
				cur -= ll(n - nxt - k + 1) * (nxt - pre);
				cur += ll(n - x - k + 1) * (x - pre);
				cur += ll(n - nxt - k + 1) * (nxt - x);
			}
			p.insert(x);
		}
		ans += cur;
	}
	cout << ans << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}