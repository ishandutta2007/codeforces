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
vector<vector<int>> op;

int find(int x) {
	for (int i = 0; i < n; i++)
		if (a[i] == x) return i;
	return -1;
}

void exec(vector<int> s) {
	vector<int> res;
	while (s.size()) {
		int x = s.back();
		s.pop_back();
		for (int i = (int)a.size() - x; i < a.size(); i++)
			res.push_back(a[i]);
		for (int i = 0; i < x; i++) a.pop_back();
	}
	a = res;
}

vector<int> calc(int &type, int len) {
	vector<int> s;
	int i = find(1);
	int j = find(len + 1);
	if (i < j) {
		for (int x = 0; x < i + len; x++) {
			s.push_back(1);
		}
		s.push_back(j - (i + len) + 1);
		if (j < n - 1) s.push_back(n - j - 1);
		type *= -1;
	}
	else {
		if (0 < j) s.push_back(j);
		s.push_back(i - j);
		s.push_back(len);
		if (i + len < n) s.push_back(n - (i + len));
	}
	return s;
}

void solve() {
	cin >> n;
	a.resize(n);
	op.clear();
	for (auto &i : a) cin >> i;
	int type = 1, len = 1;
	while (len < n) {
		vector<int> s;
		if (type == 1) {
			s = calc(type, len);
		}
		else {
			reverse(a.begin(), a.end());
			s = calc(type, len);
			reverse(a.begin(), a.end());
			reverse(s.begin(), s.end());
		}
		len++;
		op.push_back(s);
		exec(s);
	}
	if (find(1) != 0) {
		op.push_back(vector<int>(n, 1));
	}
	cout << op.size() << '\n';
	for (const auto &i : op) {
		cout << i.size() << " ";
		for (const auto &j : i) cout << j << " "; cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//cin >> tst;
	while (tst--) {
		solve();
	}
}