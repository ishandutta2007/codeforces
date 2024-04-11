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
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME "a"

const int MAXN = 3e3 + 10;

pii get(const char* t, int n, const string& s) {
	static char q[MAXN * 2];
	forn(i, n) q[i] = t[i];
	q[n] = '#';
	forn(i, sz(s)) q[n + 1 + i] = s[i];

	q[n + 1 + sz(s)] = 0;
	// puts(q);

	int x = 0, y = -1;
	static int p[2 * MAXN];
	p[0] = 0;
	for (int i = 1; i < n + 1 + sz(s); ++i) {
		int j = p[i - 1];
		while (j > 0 && q[i] != q[j]) j = p[j - 1];
		j += (q[i] == q[j]);
		p[i] = j;
		// printf("p[%d] = %d\n", i, j);

		if  (p[i] > 0 && i > n) {
			int Y = i - (n + 1);
			int X = i - (n + 1) - p[i] + 1;
			if  (Y - X > y - x) {
				x = X;
				y = Y;
				assert(0 <= x && x < sz(s));
				assert(0 <= y && y < sz(s));
			}
		}
	}

	// printf("x=%d, y=%d, n=%d\n", x, y, n);
	return mp(x, y);
}

string s, t;

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	getline(cin, s);
	getline(cin, t);

	string rev_s = s;
	reverse(all(rev_s));

	int ptr = 0;
	vii ans;
	while (ptr < sz(t)) {
		pii xy1 = get(t.data() + ptr, sz(t) - ptr, s);
		pii xy2 = get(t.data() + ptr, sz(t) - ptr, rev_s);

		pii xy(-1, -1);
		if  (xy2.snd == -1) {
			xy = xy1;
		} else if  (xy1.snd == -1) {
			xy = xy2;
			xy.fst = sz(s) - 1 - xy.fst;
			xy.snd = sz(s) - 1 - xy.snd;
		} else {
			if  (xy1.snd - xy1.fst > xy2.snd - xy2.fst) {
				xy = xy1;
			} else {
				xy = xy2;
				xy.fst = sz(s) - 1 - xy.fst;
				xy.snd = sz(s) - 1 - xy.snd;
			}
		}

		if  (xy.snd == -1) {
			// cerr << "ptr = " << ptr << endl;
			puts("-1");
			return 0;
		}

		ans.pb(xy);
		ptr += abs(xy.fst - xy.snd) + 1;
	}

	printf("%d\n", sz(ans));
	forn(i, sz(ans)) {
		printf("%d %d\n", ans[i].fst + 1, ans[i].snd + 1);
	}

	return 0;
}