#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n;
string s;

void solve() {
	cin >> n >> s;
	bool found1 = false, found2 = false;
	for (auto &i : s) {
		if (i == '<') found1 = true;
		if (i == '>') found2 = true;
	}
	if (!found1 || !found2) {
		cout << n << '\n';
		return;
	}
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (s[i] == '-' || s[(i + n - 1) % n] == '-') cnt++;
	}
	cout << cnt << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}