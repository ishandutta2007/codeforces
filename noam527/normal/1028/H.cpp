#include <bits/stdc++.h>
#define finish(x) return cout << x << endl, 0
typedef long long ll;
typedef long double ldb;
const int md = 1e9 + 7;
const ll inf = 4e18;
const int OO = 0;
const int OOO = 1;
using namespace std;

const int M = 5050505;
int sieve[M] = {};

void prep() {
	for (int i = 2; i * i <= M; i++) {
		if (!sieve[i]) {
			sieve[i] = i;
			for (int j = i * i; j < M; j += i)
				sieve[j] = i;
		}
	}
}

vector<int> factor(int v) {
	vector<int> rtn;
	int p, c;
	while (sieve[v]) {
		p = sieve[v];
		c = 0;
		while (v % p == 0)
			v /= p, c++;
		if (c & 1) rtn.push_back(p);
	}
	if (v > 1) rtn.push_back(v);
	return rtn;
}

void factors(const vector<int> &f, int i, int val, int extra, vector<pair<int, int>> &res) {
	if (i == f.size()) {
		res.emplace_back(val, extra);
		return;
	}
	factors(f, i + 1, val, extra + 1, res);
	factors(f, i + 1, val * f[i], extra, res);
}

int best[M][8];

int n, q;
vector<int> a;
int R[200005][15];

int main() {
	ios::sync_with_stdio(0), cin.tie(0);
	prep();
	for (int i = 0; i < M; i++) for (int j = 0; j < 8; j++) best[i][j] = md;

	cin >> n >> q;
	a.resize(n);
	for (auto &i : a) cin >> i;
	for (int j = 0; j < 15; j++) R[n - 1][j] = md;
	vector<int> f = factor(a[n - 1]);
	vector<pair<int, int>> sub;
	factors(f, 0, 1, 0, sub);
	for (const auto &i : sub)
		best[i.first][i.second] = min(best[i.first][i.second], n - 1);

	for (int i = n - 2; i >= 0; i--) {
		for (int j = 0; j < 15; j++) R[i][j] = R[i + 1][j];
		f = factor(a[i]);
		sub.clear();
		factors(f, 0, 1, 0, sub);
		for (const auto &p : sub) {
			for (int j = 0; j < 8; j++)
				R[i][p.second + j] = min(R[i][p.second + j], best[p.first][j]);
		}
		for (const auto &p : sub)
			best[p.first][p.second] = min(best[p.first][p.second], i);
	}
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		for (int i = 0; i < 15; i++)
			if (R[l][i] <= r) {
				cout << i << '\n';
				break;
			}
	}
}