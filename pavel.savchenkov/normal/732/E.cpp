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
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 2e5 + 10;

int n, m;
int s[MAXN];
int p[MAXN];

bool read() {
	if  (scanf("%d%d", &n, &m) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &p[i]);
	}
	forn(i, m) {
		scanf("%d", &s[i]);
	}
	return true;
}

map<int, set<int>> poses_p;
int a[MAXN];
int b[MAXN];

void solve() {
	poses_p.clear();
	forn(i, n) {
		poses_p[p[i]].insert(i);
	}

	vi order(m);
	iota(all(order), 0);
	sort(all(order), [&](int i, int j) { return s[i] < s[j]; });

	memset (b, -1, sizeof b);
	int c = 0;
	ll u = 0;
	for (int i : order) {
		a[i] = 0;
		int it = 0;
		while (1) {
			if  (poses_p.count(s[i]) && !poses_p[s[i]].empty()) {
				int j = *poses_p[s[i]].begin();
				poses_p[s[i]].erase(j);
				a[i] = it;
				b[j] = i;
				++c;
				u += it;
				break;
			}
			++it;
			if  (s[i] == 1) {
				break;
			}
			s[i] = (s[i] + 1) / 2;
		}
	}

	printf("%d %lld\n", c, u);
	forn(i, m) {
		printf("%d ", a[i]);
	}
	puts("");
	forn(i, n) {
		printf("%d ", b[i] + 1);
	}
	puts("");
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}