#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
using namespace std;

int n;
string s[3];

string build(char sm, const string &a, const string &b) {
	int p0 = 0, p1 = 0;
	string res = "";
	while (p0 < 2 * n && p1 < 2 * n) {
		if (a[p0] == sm) {
			if (b[p1] == sm) {
				res.push_back(sm);
				p0++, p1++;
			}
			else {
				res.push_back(sm);
				p0++;
			}
		}
		else {
			if (b[p1] == sm) {
				res.push_back(sm);
				p1++;
			}
			else {
				res.push_back(sm ^ 1);
				p0++, p1++;
			}
		}
	}
	while (p0 < 2 * n) {
		res.push_back(a[p0++]);
	}
	while (p1 < 2 * n) {
		res.push_back(b[p1++]);
	}
	while (res.size() < 3 * n) res.push_back('0');
	return res;
}

void solve() {
	cin >> n >> s[0] >> s[1] >> s[2];
	int c[3][2] = {};
	for (int i = 0; i < 3; i++) {
		for (auto j : s[i])
			c[i][j - '0']++;
	}
	string res = "";
	for (int i = 0; i < 3; i++) for (int j = i + 1; j < 3; j++) {
		if (c[i][0] <= n && c[j][0] <= n) {
			cout << build('0', s[i], s[j]) << '\n';
			return;
		}
		if (c[i][1] <= n && c[j][1] <= n) {
			cout << build('1', s[i], s[j]) << '\n';
			return;
		}
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}