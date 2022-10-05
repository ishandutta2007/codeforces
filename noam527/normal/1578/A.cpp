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
	for (auto &i : a) cin >> i;
	while (a.size()) {
		int nxt = a.size() - 1;
		while (nxt >= 0 && a[nxt] % (nxt + 2) == 0) nxt--;
		if (nxt == -1) {
			cout << "NO\n";
			return;
		}
		a.erase(a.begin() + nxt);
	}
	cout << "YES\n";
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}