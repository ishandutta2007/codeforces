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

using namespace std;

#define PB push_back
#define F first
#define S second
#define MP make_pair 
#define SZ(C) ((int) (C).size())
#define FORN(i, n) for (int i = 0; i < (int) n; ++i)
#define FORD(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define ALL(C) begin(C), end(C)

#define DEBUG(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef vector <vector<pii> > vvii;

const double EPS = 1e-9;
const int MAXN = int(1e5 + 5);
const int MOD = int(1e9 + 7);

inline int add( int x, int y, int mod ) {
	if  ((x += y) >= mod) {
		x -= mod;
	}
	return x;
}

inline int mul( int x, int y, int mod ) {
	return x * 1ll * y % mod;
}

inline int mpow( int a, int p, int mod ) {
	int res = 1;

	for (; p; p >>= 1, a = mul(a, a, mod)) {
		if  (p & 1) {
			res = mul(res, a, mod);
		}
	}

	return res;
}

char buf[MAXN];

void read( string& s ) {
	gets(buf);
	scanf("\n");

	int len = strlen(buf);
	s.resize(len);

	FORN(i, len) {
		s[i] = buf[i];
	}
}

struct info {
	int len; // % (MOD - 1)
	int rest; // % MOD
};

info last[15];

string s;
string t[MAXN];
int d[MAXN];
int n;

int main() {
/*
	freopen("in.txt", "w", stdout);

	FORN(i, 100000) {
		putchar('4');
	}
	puts("");

	printf("100000\n");
	FORN(i, 100000) {
		printf("4->1\n");
	}

	return 0;
*/
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	read(s);

	scanf("%d\n", &n);

	FORN(i, n) {
		scanf("%d->", &d[i]);
		read(t[i]);
	}

	FORN(d, 10) {
		last[d] = {-1, -1};
	}

	FORD(j, n) {
		info cur = { 0, 0 };

		FORD(i, SZ(t[j])) {
			int cur_d = t[j][i] - '0';

			if  (last[cur_d].len == -1) {
				cur.rest = add(cur.rest, mul(cur_d, mpow(10, cur.len, MOD), MOD), MOD);
				cur.len = add(cur.len, 1, MOD - 1);
		   	} else {
		   		cur.rest = add(cur.rest, mul(last[cur_d].rest, mpow(10, cur.len, MOD), MOD), MOD);
		   		cur.len = add(cur.len, last[cur_d].len, MOD - 1);
		   	}
		}	

		last[d[j]] = cur;
	}

	info cur = { 0, 0 };

	FORD(i, SZ(s)) {
		int cur_d = s[i] - '0';

		if  (last[cur_d].len == -1) {
			cur.rest = add(cur.rest, mul(cur_d, mpow(10, cur.len, MOD), MOD), MOD);
			cur.len = add(cur.len, 1, MOD - 1);
	   	} else {
	   		cur.rest = add(cur.rest, mul(last[cur_d].rest, mpow(10, cur.len, MOD), MOD), MOD);
	   		cur.len = add(cur.len, last[cur_d].len, MOD - 1);
	   	}
	}	

	printf("%d\n", cur.rest);
	return 0;
}