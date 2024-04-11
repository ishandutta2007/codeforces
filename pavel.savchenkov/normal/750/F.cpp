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

#define TEST 0

vi rev(vi v) {
	reverse(all(v));
	return v;
}

struct Tester {
	vvi g;
	int h;
	int n;
	int ans;
	int cnt;

	Tester() {
		h = rand() % 6 + 2;
		n = (1 << h) - 1;
		g.resize(n + 1);
		vi func = vi(n + 1);
		for (int i = 1; i <= n; ++i) {
			func[i] = i;
		}
		random_shuffle(func.begin() + 1, func.end());
		for (int i = 2; i <= n; ++i) {
			g[func[i / 2]].pb(func[i]);
			g[func[i]].pb(func[i / 2]);
		}
		ans = func[1];
		for (int i = 1; i <= n; ++i) {
			random_shuffle(all(g[i]));
		}
		cnt = 0;

	#if TEST
		cout << "input: h = " << h << ", n = " << n << ", root = " << ans << endl;
		for (int i = 1; i <= n; ++i) {
			for (int to : g[i]) {
				if  (i < to) {
					cout << i << " -> " << to << endl;
				}
			}
		}
	#endif
	}

	vi ask(int v) {
		++cnt;
		if  (cnt == 17) {
			cout << "Too many questions" << endl;
			exit(1);
		}
		cout << "ask " << v << endl;
		return g[v];
	}
};

struct Solver {
	vvi g;
	int h;
	int n;
	int was;

	Tester tester;

	bool read() {
	#if !TEST
		if  (!(cin >> h)) {
			return 0;
		}
		if  (!h) {
			exit(0);
		}
		n = (1 << h) - 1;
		g.resize(n + 1);
		return 1;
	#else
		h = tester.h;
		n = tester.n;
		g.resize(n + 1);
		return 1;
	#endif
	}

	void ask(int v) {
		if  (!g[v].empty()) {
			return;
		}
		++was;
	#if !TEST
		cout << "? " << v << endl;
		int k;
		cin >> k;
		if  (!k) {
			exit(0);
		}
		g[v].resize(k);
		forn(i, k) {
			cin >> g[v][i];
		}
		if (k == 2) {
			print(v);
		}
	#else
		g[v] = tester.ask(v);
		if  (sz(g[v]) == 2) {
			print(v);
		}
	#endif
	}

	void print(int v) {
	#if !TEST
		cout << "! " << v << endl;
		throw std::exception();
	#else
		if  (v == tester.ans) {
			cout << "SUCCESS: " << v << " == " << tester.ans << ", h = " << tester.h << endl;
		} else {
			cout << "FAIL, h = " << tester.h << ", my = " << v << ", ans = " << tester.ans << endl;
			exit(1);
		}
		throw std::exception();
	#endif
	}

	void solve() {		
		assert(read());
		was = 0;

		try {
			int v = 1;
			vi vs = get_from(v);
			{
				vi vs2 = get_from(v);
				vs2 = rev(vs2);
				vs2.pop_back();
				for (int x : vs) {
					vs2.pb(x);
				}
				vs = vs2;
			}
			go(vs);
		} catch (...) {
			return;
		}
		assert(0);
	}

	vi get_from(int v) {
		ask(v);
		for (int u : g[v]) {
			if  (g[u].empty()) {
				vi rec = get_from(u);
				rec = rev(rec);
				rec.pb(v);
				return rev(rec);
			}
		}
		assert(sz(g[v]) == 1);
		return {v};
	}

	void go(vi vs) {
		assert(sz(vs) >= 3);
		assert(sz(vs) & 1);
		int height = sz(vs) / 2;
		if  (height >= 3) {
			int rr = vs[height];
			int r = -1;
			assert(!g[rr].empty());
			for (int cand : g[rr]) {
				if  (cand != vs[height - 1] && cand != vs[height + 1]) {
					r = cand;
					break;
				}
			}
			assert(r != -1);

			ask(r); // 11
			vi nei;
			for (int cand : g[r]) {
				if  (cand != rr) {
					nei.pb(cand);
				}
			}
			assert(sz(nei) == 2);
			for (int x : nei) { // 12 13
				ask(x);
			}
			for (int cand : g[nei[0]]) {
				ask(cand); // 14 15
			}

			bool first = 1;
			for (int cand : g[nei[1]]) {
				if  (!g[cand].empty()) {
					continue;
				}
				if  (first) {
					ask(cand);
				} else {
					print(cand);
				}
				first = 0;
			}
			assert(0);
		}

		int r = vs[height];
		for (int cand : g[r]) {
			if  (cand != vs[height - 1] && cand != vs[height + 1]) {
				vi cur = get_from(cand);
				vs.resize(height + 1);
				for (int x : cur) {
					vs.pb(x);
				}
				go(vs);
				assert(0);
			}
		}
		assert(0);
	}

};

int main() {
#ifdef LOCAL
	// freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	int t;
	cin >> t;
	forn(it, t) {
		Solver().solve();
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}