#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
ll w;
vector<pair<int, int>> a;

void solve() {
	cin >> n >> w;
	a.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first;
		a[i].second = i + 1;
	}
	sort(a.begin(), a.end());
	while (a.size() && a.back().first > w) a.pop_back();
	if (!a.size()) {
		cout << "-1\n";
		return;
	}
	ll sum = 0;
	vector<int> take;
	while (a.size() && 2 * sum < w) {
		sum += a.back().first;
		take.push_back(a.back().second);
		a.pop_back();
	}
	if (2 * sum < w) {
		cout << "-1\n";
		return;
	}
	sort(take.begin(), take.end());
	cout << take.size() << '\n';
	for (const auto &i : take) cout << i << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}