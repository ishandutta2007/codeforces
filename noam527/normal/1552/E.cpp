#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, k;
vector<int> a;
vector<pair<int, int>> b;

void work(int l, int r) {
	set<int> left;
	for (int i = l; i <= r; i++) left.insert(i);
	map<int, int> seen;
	for (int i = 0; i < a.size(); i++) {
		if (!left.count(a[i])) continue;
		if (!seen.count(a[i])) {
			seen[a[i]] = i;
			continue;
		}
		b[a[i] - 1] = { seen[a[i]] + 1, i + 1 };
		left.erase(a[i]);
		seen.clear();
	}
}

void solve() {
	cin >> n >> k;
	a.resize(n * k);
	b.resize(n);
	for (auto &i : a) cin >> i;
	for (int l = 1; l <= n; l += k - 1)
		work(l, l + k - 2);
	for (const auto &i : b) cout << i.first << " " << i.second << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	//srand(time(NULL));
	int tst = 1;
	//cin >> tst;
	while (tst--) solve();
}