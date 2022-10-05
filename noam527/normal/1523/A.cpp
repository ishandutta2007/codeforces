#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n, m;
string s;
vector<int> l, r;

void solve() {
	cin >> n >> m >> s;
	l.resize(n);
	r.resize(n);
	l[0] = (s[0] == '0' ? md : 0);
	for (int i = 1; i < n; i++)
		if (s[i] == '1')
			l[i] = 0;
		else
			l[i] = 1 + l[i - 1];
	r[n - 1] = (s[n - 1] == '0' ? md : 0);
	for (int i = n - 2; i >= 0; i--) {
		if (s[i] == '1')
			r[i] = 0;
		else
			r[i] = 1 + r[i + 1];
	}
	for (int i = 0; i < n; i++) {
		if (min(l[i], r[i]) <= m && (l[i] == 0 || l[i] != r[i]))
			cout << "1";
		else
			cout << "0";
	}
	cout << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}