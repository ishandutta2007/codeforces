#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
vector<int> a;

void solve() {
	cin >> n;
	a.resize(n);
	int sump = 0, sumn = 0;
	for (auto &i : a) {
		cin >> i;
		if (i > 0) sump += i;
		else sumn += -i;
	}
	if (sump == sumn) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	if (sump > sumn) {
		sort(a.rbegin(), a.rend());
	}
	else {
		sort(a.begin(), a.end());
	}
	for (const auto &i : a) cout << i << " "; cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) {
		solve();
	}
}