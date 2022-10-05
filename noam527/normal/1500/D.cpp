#include <bits/stdc++.h>
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 3e18;
const int OO = 0;
using namespace std;

const int N = 1505;

struct item {
	int i, j, d, col;
	item() {}
	item(int ii, int jj, int dd, int cc) {
		i = ii;
		j = jj;
		d = dd;
		col = cc;
	}
};

int n, q;
int a[N][N];
vector<pair<int, int>> b[N][N];

bool found(int i, int j, int col) {
	for (const auto &x : b[i][j]) {
		if (x.second == col) return true;
	}
	return false;
}

int aux[N * N] = {};

void addvector(vector<pair<int, int>> &A, const vector<pair<int, int>> &B) {
	for (const auto &x : B) A.emplace_back(x.first + 1, x.second);
}

void work(int i, int j) {
	vector<pair<int, int>> opt;
	opt.reserve(35);
	opt.emplace_back(0, a[i][j]);
	if (i + 1 < n) addvector(opt, b[i + 1][j]);
	if (j + 1 < n) addvector(opt, b[i][j + 1]);
	if (i + 1 < n && j + 1 < n) addvector(opt, b[i + 1][j + 1]);
	sort(opt.begin(), opt.end());
	for (const auto &x : opt) {
		if (aux[x.second]) continue;
		aux[x.second] = 1;
		b[i][j].push_back(x);
		if (b[i][j].size() == q) break;
	}
	for (const auto &x : opt)
		aux[x.second] = 0;
}

void solve() {
	cin >> n >> q;
	q++;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) cin >> a[i][j];

	for (int i = n - 1; i >= 0; i--) for (int j = n - 1; j >= 0; j--)
		work(i, j);

	/*
	queue<item> qu;
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		qu.push(item(i, j, 0, a[i][j]));
	}
	while (qu.size()) {
		item x = qu.front();
		if (OO) {
			cout << "in queue: " << x.i << " " << x.j << " " << x.d << " " << x.col << '\n';
		}
		qu.pop();
		if (b[x.i][x.j].size() == q || found(x.i, x.j, x.col)) continue;
		b[x.i][x.j].emplace_back(x.d, x.col);
		if (x.i > 0) {
			if (b[x.i - 1][x.j].size() < q && !found(x.i - 1, x.j, x.col))
				qu.push(item(x.i - 1, x.j, x.d + 1, x.col));
			if (x.j > 0) {
				if (b[x.i - 1][x.j - 1].size() < q && !found(x.i - 1, x.j - 1, x.col))
					qu.push(item(x.i - 1, x.j - 1, x.d + 1, x.col));
			}
		}
		if (x.j > 0) {
			if (b[x.i][x.j - 1].size() < q && !found(x.i, x.j - 1, x.col))
				qu.push(item(x.i, x.j - 1, x.d + 1, x.col));
		}
	}
	*/
	if (OO) {
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
			cout << i << " " << j << ":\n";
			//for (const auto &x : b[i][j]) cout << x.d << " " << x.col << '\n';
		}
	}
	vector<int> ans(n + 1, 0);
	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
		int best = min(n - i, n - j);
		if (b[i][j].size() == q)
			best = min(best, b[i][j][q - 1].first);
		ans[best]++;
	}
	for (int i = n - 1; i >= 0; i--) ans[i] += ans[i + 1];
	for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
}

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	int tst = 1;
	//	cin >> tst;
	while (tst--) solve();
}