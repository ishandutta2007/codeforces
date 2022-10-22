#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n, m, a[100][100];
vector<vector<pair<int, int>>> ans;

void print() {
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
	cout << "\n";
}

void Add(vector<pair<int, int>> v) {
	assert(v.size() == 3);
	ans.push_back(v);
	for (pair<int, int> p : v) a[p.first][p.second] ^= 1;
	//print();
}

void remove1(int i, int j) { // removes the left part of a 2 by 2 square
	if (a[i][j] == 0 && a[i + 1][j] == 0) return;
	vector<pair<int, int>> cur;
	if (a[i][j] == 1) cur.emplace_back(i, j);
	if (a[i + 1][j] == 1) cur.emplace_back(i + 1, j);
	if (cur.size() < 3) cur.emplace_back(i, j + 1);
	if (cur.size() < 3) cur.emplace_back(i + 1, j + 1);
	Add(cur);
}

void remove2(int i, int j) {
	if (a[i][j] == 0 && a[i][j + 1] == 0) return;
	vector<pair<int, int>> cur;
	if (a[i][j] == 1) cur.emplace_back(i, j);
	if (a[i][j + 1] == 1) cur.emplace_back(i, j + 1);
	if (cur.size() < 3) cur.emplace_back(i + 1, j);
	if (cur.size() < 3) cur.emplace_back(i + 1, j + 1);
	Add(cur);
}

void solve() {
	ans.clear();
	cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		string s; cin >> s;
		for (int j = 0; j < m; ++j) a[i][j] = s[j] - '0';
	}
	for (int i = 0; i + 1 < n; i += 2) for (int j = 0; j + 2 < m; ++j) remove1(i, j);
	if (n % 2 == 1) for (int i = 0; i + 2 < m; ++i) remove1(n - 2, i);
	for (int i = 0; i + 2 < n; ++i) remove2(i, m - 2);
	//solve the square from [n - 2, n - 1] by [m - 2, m - 1]
	while(1) {
		vector<pair<int, int>> ones;
		if (a[n - 2][m - 2] == 1) ones.emplace_back(n - 2, m - 2);
		if (a[n - 2][m - 1] == 1) ones.emplace_back(n - 2, m - 1);
		if (a[n - 1][m - 2] == 1) ones.emplace_back(n - 1, m - 2);
		if (a[n - 1][m - 1] == 1) ones.emplace_back(n - 1, m - 1);
		auto check = [&](pair<int, int> p) {
			return find(ones.begin(), ones.end(), p) == ones.end();
		};
		vector<pair<int, int>> cur = ones;
		if (ones.size() == 0) break;
		else if (ones.size() <= 2) {
			if (check({n - 2, m - 2})) cur.emplace_back(n - 2, m - 2);
			if (check({n - 2, m - 1})) cur.emplace_back(n - 2, m - 1);
			if (check({n - 1, m - 2})) cur.emplace_back(n - 1, m - 2);
			if (check({n - 1, m - 1})) cur.emplace_back(n - 1, m - 1);
			if (ones.size() == 1) cur.pop_back();
			else {assert(ones.size() == 2); cur.erase(cur.begin());}
		}
		else if (ones.size() == 3);
		else if (ones.size() == 4) cur.pop_back();
		else assert(0);
		Add(cur);
	}
	assert(ans.size() <= n * m);
	cout << ans.size() << "\n";
	for (vector<pair<int, int>> x : ans) {
		for (pair<int, int> p : x) cout << p.first + 1 << " " << p.second + 1 << " ";
		cout << "\n";
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;
	while(t--) solve();
	return 0;
}