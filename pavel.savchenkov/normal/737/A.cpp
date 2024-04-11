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
typedef vector<vi> vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;

#define FILE_NAME "a"

const int MAXN = 2e5 + 10;
const ll INF = 1e18;

int n, k, s, t;

struct Car {
	int c, v;

	void read() {
		scanf("%d%d", &c, &v);
	}

	bool operator < (const Car& other) const {
		return c < other.c;
	}
};

vector<Car> cars;
int g[MAXN];

bool read() {
	if  (scanf("%d%d%d%d", &n, &k, &s, &t) < 4) {
		return 0;
	}
	cars.resize(n);
	forn(i, n) {
		cars[i].read();
	}
	forn(i, k) {
		scanf("%d", &g[i]);
	}
	return 1;
}

ll calc(int len, int V) {
	if  (len > V) {
		return INF;
	}
	int y = max(0, min(V - len, len));
	int x = len - y;
	return 2 * x + y;
}

bool can(int V) {
	ll sum = 0;
	forn(i, k - 1) {
		sum += calc(g[i + 1] - g[i], V);
		if  (sum > t) {
			return 0;
		}
	}
	return 1;
}

int mx_v[MAXN];

int solve() {
	g[k++] = 0;
	g[k++] = s;
	sort(g, g + k);

	sort(all(cars));

	forn(i, sz(cars)) {
		mx_v[i] = cars[i].v;
		if  (i > 0 && mx_v[i] < mx_v[i - 1]) {
			mx_v[i] = mx_v[i - 1];
		}
	}

	int L = -1;
	int R = sz(cars);
	while (L != R - 1) {
		int M = (L + R) / 2;
		if  (can(mx_v[M])) {
			R = M;
			// printf("can %d\n", mx_v[M]);
		} else {
			L = M;
		}
	}

	if  (R == sz(cars)) {
		return -1;
	}

	return cars[R].c;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		printf("%d\n", solve());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}