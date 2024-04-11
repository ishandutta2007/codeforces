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
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

const ld PI = acos(-1.0);

namespace FFT {
	void fft(vcd& a) {
		int B = 0;
		while ((1 << B) < sz(a)) {
			++B;
		}
		assert((1 << B) == sz(a));

		vi inv(1 << B);
		for (int i = 1; i < (1 << B); ++i) {
			inv[i] = inv[i >> 1] >> 1;
			if  (i & 1) {
				inv[i] ^= 1 << (B - 1);
			}
		}

		forn(i, sz(a)) {
			if  (i < inv[i]) {
				swap(a[i], a[inv[i]]);
			}
		}

		for (int len = 1; len * 2 <= (1 << B); len *= 2) {
			vcd w(len * 2);
			ld ang = 2 * PI / (len * 2);
			w[0] = cd(cos(0), sin(0));
			w[1] = cd(cos(ang), sin(ang));
			for (int i = 2; i < sz(w); ++i) {
				w[i] = w[i / 2] * w[(i + 1) / 2];
			}
			for (int i = 0; i < (1 << B); i += len * 2) {
				forn(j, len) {
					cd x = a[i + j];
					cd y = a[i + len + j];
					cd ww = w[j];
					a[i + j] = x + ww * y;
					a[i + len + j] = x - ww * y;
				}
			}
		}
	}

	void fft_inv(vcd& a) {
		fft(a);
		reverse(a.begin() + 1, a.end());
		for (auto& x : a) {
			x /= sz(a);
		}
	}

	vi mult(vi a, vi b) {
		int s = 0;
		while ((1 << s) < sz(a) || (1 << s) < sz(b)) ++s;
		++s;

		vcd A(1 << s);
		forn(i, sz(a)) {
			A[i] = a[i];
		}
		fft(A);

		vcd B(1 << s);
		forn(i, sz(b)) {
			B[i] = b[i]; 
		}
		fft(B);

		forn(i, sz(A)) {
			A[i] *= B[i];
		}

		fft_inv(A);

		vi res;
		forn(i, sz(A)) {
			ld val = round(A[i].real());
			res.pb(int(val));
		}
		while (!res.empty() && !res.back()) {
			res.pop_back();
		}
		return res;
	}

	vi brut_mult(vi a, vi b) {
		vi res(sz(a) + sz(b));
		forn(i, sz(a)) forn(j, sz(b)) {
			res[i + j] += a[i] * b[j];
		}
		while (!res.empty() && !res.back()) {
			res.pop_back();
		}
		return res;
	}
};

const int MAXN = 5e5 + 10;

#define TEST 0

int n;
char s[MAXN];

bool read() {
#if TEST
	n = MAXN - 20;
	forn(i, n) {
		int id = rand() % 3;
		if  (id == 0) {
			s[i] = 'V';
		} else if  (id == 1) {
			s[i] = 'K';
		} else {
			s[i] = '?';
		}
	}
	s[n] = 0;
#else
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	scanf("%s\n", s);
	assert(int(strlen(s)) == n);
#endif
	return 1;
}



void solve() {
	vi pos_v(n);
	vi pos_k(n);
	forn(i, n) {
		if  (s[i] == 'V') {
			pos_v[i] = 1;
		} else if  (s[i] == 'K') {
			pos_k[i] = 1;
		} else {
			assert(s[i] == '?');
		}
	}
	reverse(all(pos_k));

	vi C = FFT::mult(pos_v, pos_k);

	vi was_diff(n);
	forn(k, sz(C)) {
		if  (!C[k]) {
			continue;
		}
		int diff = k - (n - 1);
		diff = abs(diff);
		assert(diff < n);
		was_diff[diff] = 1;
	}

	vi ans;
	for (int d = 1; d <= n; ++d) {
		bool ok = 1;
		for (int i = d; i < n; i += d) {
			if  (was_diff[i]) {
				ok = 0;
				break;
			}
		}
		if  (ok) {
			ans.pb(d);
		}
	}

	printf("%d\n", sz(ans));
	for (int x : ans) {
		printf("%d ", x);
	}
	puts("");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// {
	// 	vi a{1, 2, 3, 4};
	// 	vi b{5, 6, 7, 8, 9};

	// 	auto br = FFT::brut_mult(a, b);
	// 	for (int x : br) printf("%d ", x);
	// 	puts("");

	// 	auto my = FFT::mult(a, b);
	// 	for (int x : my) printf("%d ", x);
	// 	puts("");
	// 	return 0;
	// }

	int T;
#if TEST
	T = 1;
#else	
	scanf("%d", &T);
#endif	

	forn(t, T) {
		assert(read());
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}