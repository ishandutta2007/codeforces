#include <bits/stdc++.h>
#define pb push_back
#define fi first
#define se second
#define int long long
#ifndef print
#define print(...)
#endif
using namespace std;
mt19937_64 rang(chrono::high_resolution_clock::now().time_since_epoch().count());
int rng(int l) { uniform_int_distribution<int> uid(0, l - 1); return uid(rang); }

int r[2005][2005];
int d[2005][2005];
int t[2005][2005];
int rr[2005][2005];
int dr[2005][2005];
string s[2005];
const int mod = 1e9 + 7;

inline void pluss(int& aa, int b) {
	aa += b;
	if (aa >= mod) aa -= mod;
}

inline void minuss(int& aa, int b) {
	aa -= b;
	if (aa < 0) aa += mod;
}

int32_t main() {
	ios::sync_with_stdio(false); cin.tie(NULL); cout.precision(10); srand(chrono::high_resolution_clock::now().time_since_epoch().count());
	int n, m;
	cin >> n >> m;
	if (n == 1 && m == 1) {
		cout << 1;
		return 0;
	}
	for (int i = 0; i < n; ++i)
		cin >> s[i];
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (s[i][j] == 'R')
				dr[i][j] = rr[i][j] = 1; 
		}
	}
	for (int i = n; i >= 0; --i) {
		for (int j = 0; j <= m; ++j) {
			dr[i][j] += dr[i + 1][j];
		}
	}
	for (int j = m; j >= 0; --j) {
		for (int i = 0; i <= n; ++i) {
			rr[i][j] += rr[i][j + 1];
		}
	}
	d[0][0] = 1;
	r[0][0] = 1;
	d[1][0] = -1;
	r[0][1] = -1;
	int rm, dm;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			if (j == m - 1 && i == n - 1) break; 
			int td = d[i][j];
			int tr = r[i][j];
			// print(td, tr, i, j);
			// print(i + 1, n - dr[i + 1][j] - 1);
			// print(j + 1, m - rr[i][j + 1] - 1);
			pluss(d[i + 1][j], tr);
			pluss(r[i][j + 1], td);
			minuss(d[n - dr[i + 1][j]][j], tr);
			minuss(r[i][m - rr[i][j + 1]], td);
			pluss(d[i + 1][j], d[i][j]);
			pluss(r[i][j + 1], r[i][j]);
		}
	}
	cout << (d[n - 1][m - 1] + r[n - 1][m - 1]) % mod << "\n";
}