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

const int MOD[2] = { (int) 1e9 + 7, (int) 1e9 + 17 };

void add(int& x, int y, int mod) {
	((x += y) >= mod) && (x -= mod);
}  

int mul(int x, int y, int mod) {
	return x * 1ll * y % mod;
}

struct Hash {
	static const int S = 2;

	int v[S];

	Hash(int x = 0) {
		forn(i, S) v[i] = x;
	}

	Hash& operator += (const Hash& other) {
		forn(i, S) add(v[i], other.v[i], MOD[i]);
		return *this;
	}

	Hash& operator *= (const Hash& other) {
		forn(i, S) v[i] = mul(v[i], other.v[i], MOD[i]);
		return *this;
	}

	bool operator < (const Hash& other) const {
		forn(i, S) {
			if  (v[i] != other.v[i]) {
				return v[i] < other.v[i];
			}
		}
		return false;
	}

	bool operator == (const Hash& other) const {
		forn(i, S) {
			if  (v[i] != other.v[i]) {
				return false;
			}
		}
		return true;
	}
};


struct Hasher {
	ull operator()(const Hash& h) const {
		return h.v[0] * 1ll * MOD[1] + MOD[0];
	}
};

const int MAXN = 1e5 + 10;
const int PP = 239;
const int MAXLEN = MAXN * 23;

Hash P[MAXLEN];
string host[MAXN];
string path[MAXN];
int n;

void precalc() {
	P[0] = 1;
	for (int i = 1; i < MAXLEN; ++i) {
		P[i] = P[i - 1];
		P[i] *= PP;
	}
}

string get_line() {
	static char buf[1000];
	gets(buf);
	return string(buf);
}

void parse(string s, string& h, string& p) {
	s = s.substr(7, sz(s) - 7);
	h.clear();
	p.clear();
	bool is_h = true;
	for (char c : s) {
		if  (c == '/') {
			is_h = false;
		}
		(is_h ? h : p) += c;
	}
}

bool read() {
	if  (scanf("%d\n", &n) < 1) {
		return false;
	}
	forn(i, n) {
		string s = get_line();
		parse(s, host[i], path[i]);
	}
	return true;
}

unordered_map<string, vector<string>> paths;
unordered_map<Hash, vector<string>, Hasher> hosts;

Hash calc_hash(const vector<string>& v) {
	string s;
	forn(i, sz(v)) {
		s += "$" + v[i];
	}
	Hash h(0);
	forn(i, sz(s)) {
		Hash cur = s[i];
		cur *= P[i];
		h += cur;
	}
	return h;
}

void solve() {
	forn(i, n) {
		paths[host[i]].pb(path[i]);
	}

	for (auto& it : paths) {
		sort(all(it.snd));
		it.snd.resize(unique(all(it.snd)) - it.snd.begin());
		hosts[calc_hash(it.snd)].pb(it.fst);
	}

	vector<vector<string>> ans;
	for (auto& it : hosts) {
		sort(all(it.snd));
		it.snd.resize(unique(all(it.snd)) - it.snd.begin());
		if  (sz(it.snd) > 1) {
			ans.pb(it.snd);
		}
	}

	printf("%d\n", sz(ans));
	for (auto& cur : ans) {
		for (auto& h : cur) {
			h = "http://" + h;
			printf("%s ", h.c_str());
		}
		puts("");
	}
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	precalc();

	while (read()) {
		solve();
	}

	return 0;
}