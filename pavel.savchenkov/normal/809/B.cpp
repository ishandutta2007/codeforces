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

#define TEST 0

int n, k;

#if TEST
vector<bool> on;
#endif

bool read() {
#if !TEST
	cin >> n >> k;
#else
	n = 2 + rand() % 100;
	k = 2 + rand() % (n - 1);

	printf("n=%d, k=%d\n", n, k);

	on.assign(n, 0);
	vi perm(n);
	iota(all(perm), 0);
	random_shuffle(all(perm));
	forn(it, k) {
		on[perm[it]] = 1;
	}
	// forn(i, n) {
	// 	printf("%d ", on[i] ? 1 : 0);
	// }
	// puts("");
#endif	
	return 1;
}

#if TEST
int dist(int x) {
	int ans = n;
	forn(i, n) {
		if  (on[i]) {
			ans = min(ans, abs(x - i));
		}
	}
	return ans;
}
#endif

int iters;

bool is_second_closer(int x, int y) {
#if !TEST	
	cout << 1 << " " << x + 1 << " " << y + 1 << endl;
	string res;
	cin >> res;
	return (res == "NIE");
#else
	++iters;
	assert(iters <= 60);

	int dx = dist(x);
	int dy = dist(y);
	return dy < dx;
#endif
}

int find_one(int l, int r, bool random) {
	if  (l > r) {
		return -1;
	}

	if  (l == r) {
		return l;
	}

	int m = random ? (l + rand() % (r - l + 1)) : ((l + r) >> 1);
	if  (m == r) {
		--m;
	} 

	bool is_closer = is_second_closer(m, m + 1);
	if  (is_closer) {
		return find_one(m + 1, r, random);
	}
	return find_one(l, m, random);
}

void solve() {
	iters = 0;

	int pos = find_one(0, n - 1, false);

	forn(it, 1000) {
		int pos2 = -1;

		if  (it & 1) {
			pos2 = find_one(0, pos - 1, false);
		} else {
			pos2 = find_one(pos + 1, n - 1, false);
		}
	
	#if TEST
		printf("pos=%d, pos2=%d\n", pos, pos2);
	#endif

		if  (pos2 == -1 || pos2 == pos || is_second_closer(pos2, pos)) {
			continue;
		}

		// pos = 0;
		// pos2 = 1;

#if !TEST
		cout << 2 << " " << pos + 1 << " " << pos2 + 1 << endl;
#else
		printf("pos=%d, pos2=%d\n", pos, pos2);
		assert(on[pos]);
		assert(on[pos2]);
		printf("OK n=%d, k=%d\n", n, k);
#endif

		break;
	}
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

#if TEST
	while (1) {
		read();
		solve();
	}
	return 0;
#endif

	read();
	solve();

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}