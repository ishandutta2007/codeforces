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
	multiset<int> even, odd;
	for (auto &i : a) cin >> i;
	for (int i = 0; i < n; i++) {
		if (i & 1) odd.insert(a[i]);
		else even.insert(a[i]);
	}
	sort(a.begin(), a.end());
	for (int i = 0; i < n; i++) {
		int val = a[i];
		if (i & 1) {
			auto it = odd.find(val);
			if (it == odd.end()) {
				cout << "NO\n";
				return;
			}
			odd.erase(it);
		}
		else {
			auto it = even.find(val);
			if (it == even.end()) {
				cout << "NO\n";
				return;
			}
			even.erase(it);
		}
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}