#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int ask(vector<int> a, vector<int> b) {
	cout << a.size() << " " << b.size() << " ";
	for (const auto &i : a) cout << i << " ";
	for (const auto &i : b) cout << i << " ";
	cout << endl;
	fflush(stdout);
	int ans;
	cin >> ans;
	return ans;
}

int n;

void solve() {
	cin >> n;
	vector<int> s1 = { n }, s2;
	for (int i = 1; i < n; i++) s2.push_back(i);
	int tot = ask(s1, s2);

	int lo = 1, hi = n - 1, mid;
	while (lo < hi) {
		mid = (lo + hi) / 2;
		s2.clear();
		for (int i = 1; i <= mid; i++) s2.push_back(i);
		if (ask(s1, s2) == tot) hi = mid;
		else lo = mid + 1;
	}
	// lo
	s1.clear();
	s2.clear();
	for (int i = 1; i <= n; i++) {
		if (i == lo) s1.push_back(i);
		else s2.push_back(i);
	}
	int ans = ask(s1, s2);
	cout << "-1 " << ans << endl;
	fflush(stdout);
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}