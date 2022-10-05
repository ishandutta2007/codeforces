#include <bits/stdc++.h>
#define CHECK cout << "ok" << endl
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 1e18;
const int OO = 0;
using namespace std;

int n, m;
string s, t;
int d[2] = {};
int L;

int Z() {
	vector<int> z(m, 0);
	int j = 0, r = 0;
	for (int i = 1; i < m; i++) {
		if (r < i) z[i] = 0;
		else z[i] = min(r - i + 1, z[i - j]);
		
		while (i + z[i] < m && t[z[i]] == t[i + z[i]]) z[i]++;

		if (i + z[i] - 1 > r) {
			j = i;
			r = i + z[i] - 1;
		}
	}
	for (int i = 1; i < m; i++) {
		if (i + z[i] == m) return m - i;
	}
	return 0;
}

bool can(int x) {
	if (OO) {
		cout << "checking " << x << '\n';
	}
	if (x == 0) return true;
	x--;
	int nxt = 0;
	int c[2] = {};
	for (const auto &i : t) {
		c[i - '0']++;
		nxt++;
	}
	while (x > 0) {
		if (nxt > n) return false;
		x--;
		for (int i = L; i < m; i++) {
			c[t[i] - '0']++;
			nxt++;
		}
	}
	if (OO) {
		cout << nxt << " " << c[0] << " " << c[1] << '\n';
	}

	if (c[0] > d[0] || c[1] > d[1]) return false;
	if (d[0] - c[0] + d[1] - c[1] <= n - nxt) return true;
	return false;
}
string make(int x) {
	string rtn;
	rtn.resize(n);

	x--;
	int nxt = 0;
	int c[2] = {};
	for (const auto &i : t) {
		c[i - '0']++;
		rtn[nxt] = i;
		nxt++;
	}
	while (x > 0) {
		x--;
		for (int i = L; i < m; i++) {
			c[t[i] - '0']++;
			rtn[nxt] = t[i];
			nxt++;
		}
	}
	while (c[0] < d[0]) {
		c[0]++;
		rtn[nxt++] = '0';
	}
	while (c[1] < d[1]) {
		c[1]++;
		rtn[nxt++] = '1';
	}
	return rtn;
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	cin >> s >> t;
	n = s.size();
	m = t.size();

	for (auto &i : s) d[i - '0']++;
	L = Z();

	int lo = 0, hi = n, mid;
	while (lo < hi) {
		mid = (lo + hi + 1) / 2;
		if (can(mid)) lo = mid;
		else hi = mid - 1;
	}
	if (lo == 0) finish(s);
	finish(make(lo));
}