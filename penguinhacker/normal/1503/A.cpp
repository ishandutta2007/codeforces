#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
string s;

void solve() {
	cin >> n >> s;
	int tot = count(s.begin(), s.end(), '0');
	if (tot & 1) {
		cout << "NO\n";
		return;
	}
	int cur = 0;
	string a(n, '.'), b(n, '.');
	for (int i = 0; i < n; ++i)
		if (s[i] == '0') {
			if (cur % 2 == 0)
				a[i] = '(', b[i] = ')';
			else
				a[i] = ')', b[i] = '(';
			++cur;
		}
	int left = n / 2 - tot / 2;
	for (int i = 0; i < n; ++i)
		if (a[i] == '.') {
			if (left)
				--left, a[i] = b[i] = '(';
			else
				a[i] = b[i] = ')';
		}
	//cout << a << "\n" << b << "\n";
	int d1 = 0, d2 = 0;
	for (int i = 0; i < n; ++i) {
		d1 += a[i] == '(' ? 1 : -1;
		d2 += b[i] == '(' ? 1 : -1;
		if (d1 < 0 || d2 < 0) {
			cout << "NO\n";
			return;
		}
	}
	assert(d1 == 0 && d2 == 0);
	cout << "YES\n" << a << "\n" << b << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--)
		solve();
	return 0;
}