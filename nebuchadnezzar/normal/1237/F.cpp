// Created by Nikolay Budin

#ifdef DEBUG
#  define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define ff first
#define ss second
#define szof(x) ((int)x.size())
#ifndef LOCAL
#  define cerr __get_ce
#endif

using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef unsigned long long ull;
int const INF = (int)1e9 + 1e3;
ll const INFL = (ll)1e18 + 1e6;
#ifdef LOCAL
	mt19937 tw(9450189);
#else
	mt19937 tw(chrono::high_resolution_clock::now().time_since_epoch().count());
#endif
uniform_int_distribution<ll> ll_distr;
ll rnd(ll a, ll b) { return ll_distr(tw) % (b - a + 1) + a; }

const int MOD = 998244353;

void add(int& a, int b) {
	a += b;
	if (a >= MOD) {
		a -= MOD;
	}
}

int sum(int a, int b) {
	add(a, b);
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % MOD;
}

int mpow(int a, int b) {
	int ret = 1;
	while (b) {
		if (b & 1) {
			ret = mult(ret, a);
		}
		a = mult(a, a);
		b >>= 1;
	}
	return ret;
}

int inv(int num) {
	return mpow(num, MOD - 2);
}

vector<int> factorial, inv_factorial;

int cnk(int n, int k) {
	if (k < 0 || k > n) {
		return 0;
	}
	return mult(factorial[n], mult(inv_factorial[n - k], inv_factorial[k]));
}

const int MAXN = 3605;
// const int MAXN = 500;
vector<vector<int>> dp2;
// vector<vector<vector<int>>> matr(MAXN);

// void calc_matr(int i) {
// 	if (szof(matr[i])) {
// 		return;
// 	}
// 	matr[i] = vector<vector<int>>(i / 2 + 1, vector<int>(i + 1));
// 	for (int a = 0; a <= i / 2; ++a) {
// 		for (int b = 0; b + a * 2 <= i; ++b) {
// 			matr[i][a][b] = mult(dp2[i][a], cnk(i - a * 2, b));
// 		}
// 	}
// }

const int bp = 13;
const int sz = 1 << bp;
int roots[sz];
int perm[sz];

// int arra[MAXN][sz];
// int arrb[MAXN][sz];
// int arrc[sz];
// int arrd[sz];
int arra[sz];
int arrb[sz];

void fft(int *arr, int cbp) {
	int csz = 1 << cbp;
	for (int i = 0; i < csz; ++i) {
		if (perm[i] >> (bp - cbp) > i) {
			swap(arr[i], arr[perm[i] >> (bp - cbp)]);
		}
	}
	for (int i = 1, root_shift = sz / 2; i < csz; i *= 2, root_shift /= 2) {
		for (int j = 0; j < csz; j += i * 2) {
			for (int k = 0, root_pos = 0; k < i; ++k, root_pos += root_shift) {
				int b = mult(arr[j + i + k], roots[root_pos]);
				arr[j + i + k] = sum(arr[j + k], MOD - b);
				add(arr[j + k], b);
			}
		}
	}
}

/*
vector<vector<int>> mult(vector<vector<int>> const& a, vector<vector<int>> const& b) {
	// vector<vector<int>> ret(szof(a) + szof(b) - 1, vector<int>(szof(a[0]) + szof(b[0]) - 1));
	// for (int x1 = 0; x1 < szof(a); ++x1) {
	// 	for (int y1 = 0; y1 < szof(a[x1]); ++y1) {
	// 		for (int x2 = 0; x2 < szof(b); ++x2) {
	// 			for (int y2 = 0; y2 < szof(b[x2]); ++y2) {
	// 				add(ret[x1 + x2][y1 + y2], mult(a[x1][y1], b[x2][y2]));
	// 			}
	// 		}
	// 	}
	// }
	int ph = 0;
	while (1 << ph < szof(a) + szof(b) - 1) {
		++ph;
	}
	int pw = 0;
	while (1 << pw < szof(a[0]) + szof(b[0]) - 1) {
		++pw;
	}
	for (int i = 0; i < szof(a); ++i) {
		for (int j = 0; j < szof(a[i]); ++j) {
			arra[i][j] = a[i][j];
		}
		fill(arra[i] + szof(a[i]), arra[i] + (1 << pw), 0);
		fft(arra[i], pw);
	}
	for (int i = 0; i < szof(b); ++i) {
		for (int j = 0; j < szof(b[i]); ++j) {
			arrb[i][j] = b[i][j];
		}
		fill(arrb[i] + szof(b[i]), arrb[i] + (1 << pw), 0);
		fft(arrb[i], pw);
	}

	for (int i = 0; i < 1 << pw; ++i) {
		for (int j = 0; j < szof(a); ++j) {
			arrc[j] = arra[j][i];
		}
		fill(arrc + szof(a), arrc + (1 << ph), 0);
		fft(arrc, ph);
		for (int j = 0; j < szof(b); ++j) {
			arrd[j] = arrb[j][i];
		}
		fill(arrd + szof(b), arrd + (1 << ph), 0);
		fft(arrd, ph);
		for (int j = 0; j < 1 << ph; ++j) {
			arrc[j] = mult(arrc[j], arrd[j]);
		}
		fft(arrc, ph);
		reverse(arrc + 1, arrc + (1 << ph));
		int tmp = inv(1 << ph);
		for (int j = 0; j < szof(a) + szof(b) - 1; ++j) {
			arra[j][i] = mult(arrc[j], tmp);
		}
	}

	vector<vector<int>> ret(szof(a) + szof(b) - 1, vector<int>(szof(a[0]) + szof(b[0]) - 1));

	for (int i = 0; i < szof(a) + szof(b) - 1; ++i) {
		fft(arra[i], pw);
		reverse(arra[i] + 1, arra[i] + (1 << pw));
		int tmp = inv(1 << pw);
		for (int j = 0; j < szof(a[0]) + szof(b[0]) - 1; ++j) {
			ret[i][j] = mult(arra[i][j], tmp);
		}
	}
	return ret;
}
*/

vector<int> mult(vector<int> const& a, vector<int> const& b) {
	int cbp = 0;
	while (1 << cbp < szof(a) + szof(b) - 1) {
		++cbp;
	}
	for (int i = 0; i < szof(a); ++i) {
		arra[i] = a[i];
	}
	fill(arra + szof(a), arra + (1 << cbp), 0);
	fft(arra, cbp);
	for (int i = 0; i < szof(b); ++i) {
		arrb[i] = b[i];
	}
	fill(arrb + szof(b), arrb + (1 << cbp), 0);
	fft(arrb, cbp);
	for (int i = 0; i < 1 << cbp; ++i) {
		arra[i] = mult(arra[i], arrb[i]);
	}
	fft(arra, cbp);
	reverse(arra + 1, arra + (1 << cbp));
	vector<int> ret(szof(a) + szof(b) - 1);
	int tmp = inv(1 << cbp);
	for (int i = 0; i < szof(a) + szof(b) - 1; ++i) {
		ret[i] = mult(arra[i], tmp);
	}
	return ret;
}

vector<int> calc(vector<bool> const& forbid) {
	vector<int> lens;
	int from = 0;
	for (int i = 0; i <= szof(forbid); ++i) {
		if (i == szof(forbid) || forbid[i]) {
			if (from < i) {
				lens.push_back(i - from);
			}
			from = i + 1;
		}
	}
	sort(lens.begin(), lens.end());
	if (szof(lens) == 1) {
		return dp2[lens.front()];
	}
	if (szof(lens) == 0) {
		return {1};
	}
	vector<vector<int>> vars;
	for (int l : lens) {
		vars.push_back(dp2[l]);
	}
	vector<vector<int>> vars2;
	int cnt = 0, cnt2 = 0;
	while (cnt < szof(vars) || cnt2 < szof(vars2) - 1) {
		// cerr << cnt << " " << cnt2 << " " << szof(vars) << " " << szof(vars2) << endl;
		if (cnt == szof(vars) || (cnt2 <= szof(vars2) - 2 && szof(vars2[cnt2 + 1]) <= szof(vars[cnt]))) {
			vars2.push_back(mult(vars2[cnt2], vars2[cnt2 + 1]));
			cnt2 += 2;
		} else if (cnt == szof(vars) - 1 || (cnt2 <= szof(vars2) - 1 && szof(vars2[cnt2]) <= szof(vars[cnt + 1]))) {
			vars2.push_back(mult(vars[cnt], vars2[cnt2]));
			++cnt; ++cnt2;
		} else {
			vars2.push_back(mult(vars[cnt], vars[cnt + 1]));
			cnt += 2;
		}
	}
	return vars2.back();
}

void solve() {
	int h, w, n;
	cin >> h >> w >> n;
	vector<bool> forbid_h(h), forbid_w(w);
	for (int i = 0; i < n * 2; ++i) {
		int x, y;
		cin >> x >> y;
		--x; --y;
		forbid_h[x] = true;
		forbid_w[y] = true;
	}

	auto dp_h = calc(forbid_h);
	auto dp_w = calc(forbid_w);

	int free_h = 0, free_w = 0;
	for (int i = 0; i < h; ++i) {
		if (!forbid_h[i]) {
			++free_h;
		}
	}
	for (int i = 0; i < w; ++i) {
		if (!forbid_w[i]) {
			++free_w;
		}
	}

	int ans = 0;
	for (int a = 0; a < szof(dp_h); ++a) {
		for (int b = 0; b < szof(dp_w); ++b) {
			add(ans, mult(mult(mult(dp_h[a], cnk(free_h - a * 2, b)), mult(dp_w[b], cnk(free_w - b * 2, a))), mult(factorial[a], factorial[b])));
		}
	}

	cout << ans << "\n";
}


int main() {
#ifdef LOCAL
	auto start_time = clock();
	cerr << setprecision(3) << fixed;
#endif
	cout << setprecision(15) << fixed;
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int root = 0;
	for (int i = 1; ; ++i) {
		if (mpow(i, sz / 2) == MOD - 1) {
			root = i;
			break;
		}
	}
	// cerr << root << endl;
	roots[0] = 1;
	perm[0] = 0;
	for (int i = 1; i < sz; ++i) {
		roots[i] = mult(roots[i - 1], root);
		perm[i] = (perm[i >> 1] >> 1) | ((i & 1) << (bp - 1));
	}

	// vector<vector<int>> a = {{1, 2, 3}};
	// vector<vector<int>> b = {{3, 4, 5}};
	// auto res = mult(a, b);
	// for (int i = 0; i < szof(res); ++i) {
	// 	for (int j = 0; j < szof(res[i]); ++j) {
	// 		cerr << res[i][j] << " ";
	// 	}
	// 	cerr << endl;
	// }

	// return 0;

	factorial.push_back(1);
	for (int i = 1; i < MAXN + 5; ++i) {
		factorial.push_back(mult(factorial.back(), i));
	}
	inv_factorial.push_back(inv(factorial.back()));
	for (int i = MAXN + 4; i > 0; --i) {
		inv_factorial.push_back(mult(inv_factorial.back(), i));
	}
	reverse(inv_factorial.begin(), inv_factorial.end());
	assert(szof(factorial) == szof(inv_factorial));

	dp2.push_back({1});
	for (int i = 1; i < MAXN; ++i) {
		dp2.push_back(dp2.back());
		if (i / 2 == szof(dp2[i])) {
			dp2[i].push_back(0);
		}
		for (int j = i / 2; j > 0; --j) {
			add(dp2[i][j], dp2[i - 2][j - 1]);
		}
	}

	int test_count = 1;
	// cin >> test_count;
	for (int test = 1; test <= test_count; ++test) {
		solve();
	}
	
#ifdef LOCAL
	auto end_time = clock();
	cerr << "Execution time: " << (end_time - start_time) * (int)1e3 / CLOCKS_PER_SEC << " ms\n";
#endif
}