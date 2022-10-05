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
vector<pair<int, int>> q;


void add(int i, int j) {
	q.emplace_back(i, j);
}

void solve_2(const vector<int> &a, int l, int r) {
	if (l == r) return;
	int mid = (l + r) / 2;
	solve_2(a, l, mid);
	solve_2(a, mid + 1, r);
	for (int i = 0; i <= mid - l; i++) {
		add(a[l + i], a[mid + 1 + i]);
	}
}

vector<int> merge(const vector<int> &a, const vector<int> &b) {
	vector<int> rtn;
	for (int i = 0; i < a.size(); i++)
		add(a[i], b[i]);
	for (int i = 0; i < a.size(); i++) {
		rtn.push_back(a[i]);
		rtn.push_back(b[i]);
	}
	return rtn;
}

void steal(vector<int> &to, vector<int> &from) {
	int n = to.size();
	for (int i = 0; i < n; i++) {
		add(to[i], from.back());
		to.push_back(from.back());
		from.pop_back();
	}
}

void solve() {
	cin >> n;
	vector<vector<int>> groups;
	int nxt = 0;
	for (int b = 1; b <= n; b *= 2) {
		if (n & b) {
			vector<int> group;
			for (int i = nxt; i < nxt + b; i++) group.push_back(i);
			solve_2(group, 0, b - 1);
			groups.push_back(group);
			nxt += b;
		}
	}
	reverse(groups.begin(), groups.end());
	while (groups.size() >= 3) {
		int m = groups.size();
		if (groups[m - 2].size() == groups[m - 1].size()) {
			vector<int> res = merge(groups[m - 2], groups[m - 1]);
			groups.pop_back();
			groups.pop_back();
			groups.push_back(res);
		}
		else {
			steal(groups.back(), groups[0]);
		}
	}
	cout << q.size() << '\n';
	for (const auto &i : q) cout << i.first + 1 << " " << i.second + 1 << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
//	cin >> tst;
	while (tst--) solve();
}