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

#ifdef LOCAL
#define eprintf(args...) fprintf(stderr, args), fflush(stderr)
#else
#define eprintf(...) ;
#endif

#define FILE_NAME "a"

string read_string() {
	static char buf[20];
	scanf("%s\n", buf);
	return buf;
}

int n;
vector<string> S;

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	S.resize(n);
	forn(i, n) {
		S[i] = read_string();
	}
	return 1;
}

int timer;
unordered_map<ull, int> when;
unordered_set<ull> bad;
unordered_set<ull> single;

int get_when(ull h) {
	auto it = when.find(h);
	if  (it == when.end()) {
		return -1;
	}
	return it->snd;
}

void update(ull h) {
	when[h] = timer;
	auto it = single.find(h);
	if  (it != single.end()) {
		bad.insert(h);
	} else {
		single.insert(h);
	}
}

ull mrand() {
	ull x = rand();
	ull y = rand();
	return (x * RAND_MAX) ^ y;
}

ull coef[20];

void precalc() {
	forn(i, 20) {
		coef[i] = mrand();
	}
}

void solve() {
	when.clear();
	single.clear();
	bad.clear();
	timer = 0;

	for (const auto& s : S) {
		++timer;

		forn(i, sz(s)) {
			ull h = 0;
			int len = 0;
			for (int j = i; j < sz(s); ++j) {
				++len;
				if  (len == 9) {
					break;
				}
				h += coef[j - i] * (s[j] - '0' + 1);
				if  (get_when(h) == timer) {
					continue;
				}
				update(h);
			}
		}
	}

	for (const auto& s : S) {
		string best = s;

		forn(i, sz(s)) {
			string cur;
			ull h = 0;
			int len = 0;
			for (int j = i; j < sz(s); ++j) {
				++len;
				if  (len == 9) {
					break;
				}
				h += coef[j - i] * (s[j] - '0' + 1);
				cur += s[j];
				if  (!bad.count(h)) {
					if  (sz(cur) < sz(best)) {
						best = cur;
					}
				}
			}
		}

		printf("%s\n", best.data());
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}