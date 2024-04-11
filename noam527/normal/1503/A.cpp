#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
string s;

void solve() {
	cin >> n >> s;
	string a = "", b = "";
	int cnt[2] = {};
	for (auto c : s) cnt[c - '0']++;
	if (cnt[0] % 2 != 0 || s[0] == '0') {
		cout << "NO\n";
		return;
	}
	int seen = 0;
	int nxt = 0;
	for (auto c : s) {
		if (c == '1') {
			if (seen < cnt[1] / 2) {
				a.push_back('(');
				b.push_back('(');
			}
			else {
				a.push_back(')');
				b.push_back(')');
			}
			seen++;
		}
		else {
			if (nxt) {
				a.push_back(')');
				b.push_back('(');
			}
			else {
				a.push_back('(');
				b.push_back(')');
			}
			nxt ^= 1;
		}
	}
	int x = 0;
	for (auto c : a) {
		if (c == '(') x++;
		else x--;
		if (x < 0) {
			cout << "NO\n";
			return;
		}
	}
	if (x != 0) {
		cout << "NO\n";
		return;
	}
	for (auto c : b) {
		if (c == '(') x++;
		else x--;
		if (x < 0) {
			cout << "NO\n";
			return;
		}
	}
	if (x != 0) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n" << a << '\n' << b << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}