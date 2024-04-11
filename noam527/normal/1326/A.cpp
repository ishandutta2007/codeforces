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

void solve() {
	cin >> n;
	if (n == 1) {
		cout << "-1\n";
		return;
	}
	string s = string(n, '8');
	s[n - 1] = '9';
	if ((n - 1) % 9 == 0)
		s[n - 2] = '9';
	cout << s << endl;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int t;
	cin >> t;
	while (t--) solve();
}