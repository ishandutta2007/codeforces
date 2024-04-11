#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = (int)1e9 + 7;
const ll inf = 2e18;
const int OO = 1;
using namespace std;

int n, q;
vector<int> a;

void solve() {
	cin >> n >> q;
	a.resize(n);
	for (auto &i : a) cin >> i;
	string s(n, '0');
	int cur = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (cur >= a[i])
			s[i] = '1';
		else if (cur < q) {
			cur++;
			s[i] = '1';
		}
	}
	cout << s << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}