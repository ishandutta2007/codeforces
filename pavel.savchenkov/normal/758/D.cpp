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

const int MAXN = 100;

int n;
char k[MAXN];

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return 0;
	}
	scanf("%s", k);
	return 1;
}

struct Num {
	vi d;

	Num() {}

	void push_front(int x) {
		reverse(all(d));
		d.pb(x);
		reverse(all(d));
	}

	int len() const {
		return sz(d);
	}

	bool inf() const {
		return d.empty();
	}

	bool operator < (const Num& other) const {
		if  (inf()) {
			return 0;
		}
		if  (other.inf()) {
			return 1;
		}
		if  (len() != other.len()) {
			return len() < other.len();
		}	
		return d < other.d;
	}

	void print() const {
		ll num = 0;
		for (int x : d) {
			num = num * n + x;
		}
		cout << num << endl;
	}
};

int to_num(int l, int r) {
	if  (r - l > 15) {
		return -1;
	}

	if  (k[l] == '0' && r > l) {
		return -1;
	}

	ll num = 0;
	for (int i = l; i <= r; ++i) {
		num = num * 10 + (k[i] - '0');
	}

	if  (num >= n) {
		return -1;
	}
	return num;
}

Num dp[MAXN];

void solve() {
	int len = (int) strlen(k);

	dp[len] = Num();
	ford(i, len) {
		for (int j = i; j < len && to_num(i, j) != -1; ++j) {
			Num cur = dp[j + 1];
			cur.push_front(to_num(i, j));
			dp[i] = min(dp[i], cur);
		}
	}

	dp[0].print();
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