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

#define FILE_NAME "a"

const int A = 26;
const int MAXN = 3e5 + 10;

vi read_str() {
	static char s[MAXN];
	scanf("%s\n", s);
	vi cnt(A, 0);
	for (int i = 0; s[i]; ++i) {
		++cnt[s[i] - 'a'];
	}
	return cnt;
}

vi cnt_a;
vi cnt_b;
int n;

bool read() {
	cnt_a = read_str();
	cnt_b = read_str();
	n = accumulate(all(cnt_a), 0);
	return 1;
}

char ans[MAXN];

int get_mn(const vi& cnt) {
	int mn = 0;
	while (mn < A && !cnt[mn]) {
		++mn;
	}
	assert(mn < A);
	return mn;
}

int get_mx(const vi& cnt) {
	int mx = A - 1;
	while (mx >= 0 && !cnt[mx]) {
		--mx;
	}
	assert(mx >= 0);
	return mx;
}

void solve() {
	{
		const int moves = (n + 1) / 2;
		int sum = n;
		ford(c, A) {
			while (sum > moves && cnt_a[c]) {
				--cnt_a[c];
				--sum;
			}
		}
	}

	{
		const int moves = n / 2;
		int sum = n;
		forn(c, A) {
			while (sum > moves && cnt_b[c]) {
				--cnt_b[c];
				--sum;
			}
		}
	}

	int l = 0;
	int r = n - 1;
	memset (ans, 0, sizeof ans);
	forn(it, n) {
		if  (it & 1) {
			int mx = get_mx(cnt_b);

			bool have_less = 0;
			forn(c, mx) {
				if  (cnt_a[c]) {
					have_less = 1;
					break;
				}
			}

			if  (have_less) {
				ans[l++] = 'a' + mx;
			} else {
				mx = get_mn(cnt_b);
				ans[r--] = 'a' + mx;
			}
			--cnt_b[mx];
		} else {
			int mn = get_mn(cnt_a);

			bool have_gr = 0;
			for (int c = mn + 1; c < A; ++c) {
				if  (cnt_b[c]) {
					have_gr = 1;
					break;
				}
			}

			if  (have_gr) {
				ans[l++] = 'a' + mn;
			} else {
				mn = get_mx(cnt_a);
				ans[r--] = 'a' + mn;
			}
			--cnt_a[mn];
		}
	}

	puts(ans);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();

		break;
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}