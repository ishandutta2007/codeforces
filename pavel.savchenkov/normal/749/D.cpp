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

int n;
int a[MAXN];
int b[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return 0;
	}
	forn(i, n) {
		scanf("%d%d", &a[i], &b[i]);
		--a[i];
	}
	return 1;
}

int min_pos[MAXN];
int max_pos[MAXN];
vi poses[MAXN];

void solve(set<pii>& s) {
	if  (s.empty()) {
		puts("0 0");
		return;
	}

	int id_best = s.rbegin()->snd;
	printf("%d ", id_best + 1);
	if  (sz(s) == 1) {
		printf("%d\n", b[min_pos[id_best]]);
		return;
	}

	s.erase(*s.rbegin());
	int second = s.rbegin()->snd;
	s.insert(mp(max_pos[id_best], id_best));

	// printf("best=%d, second=%d\n", id_best + 1, second + 1);

	int p = max_pos[second];
	int nxt = upper_bound(all(poses[id_best]), p) - poses[id_best].begin();
	assert(nxt < sz(poses[id_best]));
	nxt = poses[id_best][nxt];
	// printf("p=%d, nxt=%d\n", p, nxt);
	printf("%d\n", b[nxt]);
}

void solve() {
	memset (min_pos, -1, sizeof min_pos);
	forn(i, n) {
		int id = a[i];
		if  (min_pos[id] == -1) {
			min_pos[id] = i;
		}
		max_pos[id] = i;
		poses[id].pb(i);
	}

	set<pii> s;
	forn(i, n) {
		if  (min_pos[i] != -1) {
			s.insert(mp(max_pos[i], i));
		}
	}

	int q;
	scanf("%d", &q);
	forn(it, q) {
		int k;
		scanf("%d", &k);
		vi who(k);
		forn(i, k) {
			scanf("%d", &who[i]);
			--who[i];
		}

		for (int i : who) {
			if (min_pos[i] != -1) {
				s.erase(mp(max_pos[i], i));
			}
		}

		solve(s);

		for (int i : who) {
			if  (min_pos[i] != -1) {
				s.insert(mp(max_pos[i], i));
			}
		}
	}
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