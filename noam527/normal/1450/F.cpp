#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	for (auto &i : a) cin >> i, --i;
	vector<vector<int>> b;
	b.push_back(vector<int>());
	for (auto &i : a) {
		if (b.back().size() == 0 || b.back().back() != i) b.back().push_back(i);
		else {
			b.push_back(vector<int>());
			b.back().push_back(i);
		}
	}
	vector<int> cnt(n, 0);
	for (const auto &i : b) {
		if (i[0] == i.back()) cnt[i[0]]++;
	}
	int at = 0;
	for (int i = 0; i < n; i++)
		if (cnt[at] < cnt[i]) at = i;
	int mx = cnt[at];
	int other = 0;
	for (const auto &i : b) {
		if (i[0] != at && i.back() != at) other++;
	}
	if (other >= mx - 1) {
		cout << (int)b.size() - 1 << '\n';
		return;
	}
	int need = mx - 1 - other;
	vector<int> cnt2(n, 0);
	for (auto &i : a) cnt2[i]++;
	int mx2 = *max_element(cnt2.begin(), cnt2.end());
	if (n - mx2 < mx2 - 1) {
		cout << "-1\n";
		return;
	}
	cout << (int)b.size() - 1 + need << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}