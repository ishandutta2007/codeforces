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

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
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


const int MAXN = 200 + 10;
const int A = 26;

struct Node {
	Node* to[A];
	int id;

	Node() {
		memset (to, 0, sizeof to);
		id = -1;
	}
};

Node* root;

void push_string(Node* v, const string& s, int id) {
	for (char c : s) {
		if  (!v->to[c - 'a']) {
			v->to[c - 'a'] = new Node();
		}
		v = v->to[c - 'a'];
	}
	v->id = id;
}

pii deep(Node* v, const string& s) {
	int depth = 0;
	pii best(-1, 0);
	for (char c : s) {
		if  (!v->to[c - 'a']) {
			return best;
		}
		v = v->to[c - 'a'];
		++depth;
		if  (v->id != -1) {
			best = mp(v->id, depth);
		}
	}
	return best;
}

int a[MAXN];
string s[MAXN];
int n;
ll l;

bool read() {
	if  (scanf("%d%lld", &n, &l) < 2) {
		return false;
	}
	forn(i, n) {
		scanf("%d", &a[i]);
	}
	scanf("\n");
	forn(i, n) {
		static char buf[MAXN];
		gets(buf);
		s[i] = string(buf);
	}
	return true;
}


vector<string> str;
vi cost;

void mult(ll a[MAXN][MAXN], ll b[MAXN][MAXN], ll c[MAXN][MAXN]) {
	static ll res[MAXN][MAXN];
	forn(i, MAXN) forn(j, MAXN) {
		res[i][j] = -1;
		forn(k, MAXN) {
			if  (a[i][k] != -1 && b[k][j] != -1) {
				res[i][j] = max(res[i][j], a[i][k] + b[k][j]);
			}
		}
	}
	forn(i, MAXN) forn(j, MAXN) c[i][j] = res[i][j];
}

void mpow(ll c[MAXN][MAXN], ll res[MAXN][MAXN], ll p) {
	forn(i, MAXN) forn(j, MAXN) {
		res[i][j] = c[i][j];
	}
	--p;
	// forn(it, p) {
	// 	mult(res, c, res);
	// }
	// return;

	for (; p > 0; p /= 2, mult(c, c, c)) {
		if  (p & 1) {
			mult(res, c, res);
		}
	}
}

ll solve() {
	root = new Node();
	forn(i, n) {
		for (int pref = 1; pref <= sz(s[i]); ++pref) {
			string sub = s[i].substr(0, pref);
			reverse(all(sub));
			push_string(root, sub, i);
		}
	} 

	forn(i, n) {
		for (int pref = 1; pref <= sz(s[i]); ++pref) {
			str.pb(s[i].substr(0, pref));
		}
	}
	str.pb("");

	sort(all(str));
	str.resize(unique(all(str)) - str.begin());
	cost.assign(sz(str), 0);

	forn(i, sz(str)) {
		reverse(all(str[i]));

		forn(j, n) {
			if  (sz(s[j]) > sz(str[i])) {
				continue;
			}

			reverse(all(s[j]));

			bool eq = true;
			forn(k, sz(s[j])) {
				if  (s[j][k] != str[i][k]) {
					eq = false;
					break;
				}
			}
			if  (!eq) {
				reverse(all(s[j]));
				continue;
			}

			cost[i] += a[j];

			reverse(all(s[j]));
		}

		reverse(all(str[i]));
	}

	// forn(i, n) {
	// 	printf("s = %s\n", s[i].data());
	// }

	// forn(i, sz(str)) {
	// 	printf("str = %s, cost = %d\n", str[i].data(), cost[i]);
	// }

	static ll C[MAXN][MAXN];
	forn(i, MAXN) forn(j, MAXN) {
		C[i][j] = -1;
	}
	forn(i, sz(str)) {
		forn(c, A) {
			string nstr = str[i];
			nstr += ('a' + c);
			int id, len;
			reverse(all(nstr));
			tie(id, len) = deep(root, nstr);
			reverse(all(nstr));
			if  (id == -1) {
				continue;
			}
			// printf("nstr = %s, id=%d, len=%d\n", nstr.data(), id, len);
			string to = s[id].substr(0, len);
			int j = lower_bound(all(str), to) - str.begin();
			if  (C[i][j] == -1) {
				C[i][j] = 0;
			}
			C[i][j] += cost[j];
		}
	}

	// forn(i, sz(str)) forn(j, sz(str)) {
	// 	if  (C[i][j] >= 0) {
	// 		printf("%s -> %s, C = %lld\n", str[i].data(), str[j].data(), C[i][j]);
	// 	}
	// }

	// forn(i, sz(str)) {
	// 	forn(j, sz(str)) {
	// 		printf("%lld ", C[i][j]);
	// 	}
	// 	puts("");
	// }

	static ll res[MAXN][MAXN];
	mpow(C, res, l);

	// printf("res after:\n");
	// forn(i, sz(str)) {
	// 	forn(j, sz(str)) {
	// 		printf("%lld ", res[i][j]);
	// 	}
	// 	puts("");
	// }

	ll ans = 0;
	forn(i, sz(str)) {
		ans = max(ans, res[0][i]);
	}

	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	while (read()) {
		cout << solve() << '\n';
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}