#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>
#include <fstream>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

#define ws ws_____________________
#define y1 y1_____________________
#define y0 y0_____________________
#define left left_________________
#define right right_______________
#define next next_________________
#define prev prev_________________
#define hash hash_________________

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < int(n); ++i)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef double ld;
// typedef complex<double> cd;

#define FILE_NAME "a"

const ld PI = acos(-1.0);

bool bit(int mask, int i) {
	return (mask >> i) & 1;
}

struct cd {
	ld x, y;

	cd() : x(0), y(0) {}

	cd(ld x, ld y) : x(x), y(y) {}

	cd(ld z) : x(z), y(0) {}

	cd& operator *= (const cd& z) {
		tie(x, y) = mp(x * z.x - y * z.y, x * z.y + y * z.x);
		return *this;
	}

	cd operator * (const cd& z) const {
		cd tmp = z;
		tmp *= *this;
		return tmp;
	}

	cd& operator /= (const ld& z) {
		x /= z;
		y /= z;
		return *this;
	}

	cd& operator += (const cd& z) {
		x += z.x;
		y += z.y;
		return *this;
	}

	cd operator + (const cd& z) const {
		cd tmp = z;
		tmp += *this;
		return tmp;
	}

	cd operator - (const cd& z) const {
		return cd(x - z.x, y - z.y);
	}

	ld real() const {
		return x;
	}

	ld imag() const {
		return y;
	}
};

cd conj(const cd& z) {
	return cd(z.real(), -z.imag());
}

namespace FFT {
	const int B = 12;
	const int N = 1 << B;

	cd roots[N];
	int inv[N];

	cd get_root(int k, int n) {
		return roots[k * (N / n)];
	}

	void precalc() {
		forn(i, N) {
			ld ang = 2 * PI * i / N;
			roots[i] = cd(cos(ang), sin(ang));
		}
	}

	void precalc_inv(int n) {
		int b = 0;
		while ((1 << b) < n) ++b;
		assert((1 << b) == n);
		assert(b <= B);

		inv[0] = 0;
		int hb = -1;
		for (int i = 1; i < n; ++i) {
			if  (bit(i, hb + 1)) {
				++hb;
			}
			inv[i] = inv[i ^ (1 << hb)] ^ (1 << (b - hb - 1));
		}
	}

	void fft(vector<cd>& a, bool rev) {
		forn(i, sz(a)) {
			if  (i < inv[i]) {
				swap(a[i], a[inv[i]]);
			}
		}

		for (int len = 1; len * 2 <= sz(a); len *= 2) {
			for (int i = 0; i < sz(a); i += len * 2) {
				forn(j, len) {
					cd x = a[i + j];
					cd y = a[i + len + j];
					cd r = get_root(j, len * 2);
					if  (rev) {
						r = conj(r);
					}
					a[i + j] = x + r * y;
					a[i + len + j] = x - r * y;
					if  (rev) {
						a[i + j] /= 2;
						a[i + len + j] /= 2;
					}
				}
			}
		}
	}

	void fft_2d(vector<vector<cd>>& a, bool rev) {
		precalc_inv(sz(a[0]));
		for (auto& row : a) {
			fft(row, rev);
		}
		precalc_inv(sz(a));
		forn(j, sz(a.front())) {
			vector<cd> col(sz(a));
			forn(i, sz(a)) {
				col[i]  = a[i][j];
			}
			fft(col, rev);
			forn(i, sz(a)) {
				a[i][j] = col[i];
			}
		}
	}

	vector<vector<cd>> mult(vector<vector<cd>> x, vector<vector<cd>> y) {
		int b_rows = 0;
		while ((1 << b_rows) <= max(sz(x), sz(y))) ++b_rows;
		++b_rows;

		int b_cols = 0;
		while ((1 << b_cols) <= max(sz(x.front()), sz(y.front()))) ++b_cols;
		++b_cols;

		x.resize(1 << b_rows);
		y.resize(1 << b_rows);
		for (auto& row : x) {
			row.resize(1 << b_cols, 0);
		}
		for (auto& row : y) {
			row.resize(1 << b_cols, 0);
		}

		fft_2d(x, 0);
		fft_2d(y, 0);

		forn(i, sz(x)) forn(j, sz(x[i])) {
			x[i][j] *= y[i][j];
		}

		fft_2d(x, 1);

		return x;
	}

	vector<vector<cd>> brut_mult(vector<vector<cd>> x, vector<vector<cd>> y) {
		vector<vector<cd>> res(sz(x) + sz(y));
		forn(i, sz(res)) {
			res[i].resize(sz(x.front()) + sz(y.front()));
		}
		forn(i, sz(x)) forn(j, sz(x[i])) forn(ii, sz(y)) forn(jj, sz(y[ii])) {
			res.at(i + ii).at(j + jj) += x[i][j] * y[ii][jj];
		}
		return res;
	}
};

const int MAXN = 800 + 10;
const int AL = 26;

int n, m;
char a[MAXN][MAXN];
int r, c;
char b[MAXN][MAXN];

bool read() {
	if  (scanf("%d%d\n", &n, &m) < 2) {
		return 0;
	}
	forn(i, n) {
		scanf("%s\n", a[i]);
		for (int j = m; j < MAXN; ++j) {
			a[i][j] = 0;
		}
	}
	scanf("%d%d\n", &r, &c);
	forn(i, r) {
		scanf("%s\n", b[i]);
	}
	return 1;
}

int new_n, new_m;

void expand() {
	new_n = new_m = 0;
	forn(i, n) {
		forn(j, m) {
			for (int ii = i; ii < n + r; ii += n) {
				for (int jj = j; jj < m + c; jj += m) {
					a[ii][jj] = a[i][j];
					new_n = max(new_n, ii + 1);
					new_m = max(new_m, jj + 1);
				}
			}
		}
	}
}

void solve() {
	expand();

	vector<vector<cd>> A(new_n, vector<cd>(new_m, 0));
	forn(i, new_n) forn(j, new_m) {
		int ch = a[i][j] - 'a';
		ld ang = 2 * PI * ch / AL;
		A[i][j] = cd(cos(ang), sin(ang));
	}

	int not_questions = 0;
	vector<vector<cd>> B(r, vector<cd>(c, 0));
	forn(i, r) forn(j, c) {
		if (b[i][j] == '?') {
			continue;
		}
		++not_questions;
		int ch = b[i][j] - 'a';
		ld ang = - 2 * PI * ch / AL;
		B[r - i - 1][c - j - 1] = cd(cos(ang), sin(ang));
	}

	auto C = FFT::mult(A, B);

	forn(i, n) {
		forn(j, m) {
			bool can = 0;
			int cnt = floor(C[i + r - 1][j + c - 1].real() + 1e-5);
			assert(cnt <= not_questions);
			if  (cnt == not_questions) {
				can = 1;
			}
			printf("%d", can);
		}
		puts("");
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	FFT::precalc();

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}