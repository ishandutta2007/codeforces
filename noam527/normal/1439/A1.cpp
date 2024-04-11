#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 1;
const int OOO = 1;
using namespace std;

int n, m;
vector<vector<int>> a;
vector<vector<int>> op;

void apply(vector<int> &add) {
	op.push_back(add);
	for (int i = 0; i < add.size(); i += 2) {
		a[add[i]][add[i + 1]] ^= 1;
	}
}
void apply(vector<pair<int, int>> &add) {
	vector<int> vals;
	for (int i = 0; i < add.size(); i++) {
		vals.push_back(add[i].first);
		vals.push_back(add[i].second);
	}
	apply(vals);
}
void solve(int i, int j) {
	vector<pair<int, int>> all;
	for (int x = 0; x <= 1; x++)
		for (int y = 0; y <= 1; y++)
			all.push_back({ x, y });
	vector<pair<int, int>> pos;
	int at[2][2] = {};
	for (int x = 0; x <= 1; x++)
		for (int y = 0; y <= 1; y++)
			if (a[i + x][j + y])
				pos.push_back({ i + x, j + y }), at[x][y] = 1;
	if (pos.size() == 0) return;
	vector<pair<int, int>> add;
	if (pos.size() == 1) {
		add.push_back(pos[0]);
		for (const auto &p : all)
			if (at[p.first][p.second] == 0 && add.size() < 3)
				add.push_back({ i + p.first, j + p.second });
		apply(add);
		solve(i, j);
		return;
	}
	if (pos.size() == 2) {
		add.push_back(pos[0]);
		for (const auto &p : all)
			if (at[p.first][p.second] == 0 && add.size() < 3)
				add.push_back({ i + p.first, j + p.second });
		apply(add);
		solve(i, j);
		return;
	}
	if (pos.size() == 3) {
		apply(pos);
		solve(i, j);
		return;
	}
	pos.pop_back();
	apply(pos);
	solve(i, j);
}

void solve() {
	op.clear();
	cin >> n >> m;
	a.resize(n);
	for (auto &i : a) {
		string s;
		cin >> s;
		i.resize(m);
		for (int j = 0; j < m; j++)
			i[j] = s[j] - '0';
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j + 1 < m; j++) {
			if (a[i][j] == 0 && a[i][j + 1] == 0) continue;
			vector<int> add;
			if (a[i][j] == 1)
				add.push_back(i), add.push_back(j);
			if (a[i][j + 1] == 1)
				add.push_back(i), add.push_back(j + 1);
			if (add.size() < 6)
				add.push_back(i + 1), add.push_back(j);
			if (add.size() < 6)
				add.push_back(i + 1), add.push_back(j + 1);
			apply(add);
		}
	}
	for (int j = 0; j + 2 < m; j++) {
		if (a[n - 2][j] == 0 && a[n - 1][j] == 0) continue;
		vector<int> add;
		if (a[n - 2][j] == 1)
			add.push_back(n - 2), add.push_back(j);
		if (a[n - 1][j] == 1)
			add.push_back(n - 1), add.push_back(j);
		if (add.size() < 6)
			add.push_back(n - 2), add.push_back(j + 1);
		if (add.size() < 6)
			add.push_back(n - 1), add.push_back(j + 1);
		apply(add);
	}
	solve(n - 2, m - 2);
	cout << op.size() << '\n';
	for (const auto &i : op) {
		for (const auto &j : i) cout << 1 + j << " "; cout << '\n';
	}
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	cin >> tst;
	while (tst--) solve();
}