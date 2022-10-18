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

const ld EPS = 1e-9;
const int MAXN = 3e6 + 10;

int cnt[MAXN];
int l[MAXN];
int r[MAXN];
int n;
vi c;

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
#endif
	
	int n, k;
	scanf("%d%d", &n, &k);
	forn(i, n) {
		scanf("%d%d", &l[i], &r[i]);
		l[i] *= 2;
		r[i] *= 2;
		c.pb(l[i]);
		c.pb(r[i]);
		c.pb(l[i] - 1);
	}

	sort(all(c));
	c.resize(unique(all(c)) - c.begin());

	forn(i, n) {
		int pl = lower_bound(all(c), l[i]) - c.begin();
		int pr = lower_bound(all(c), r[i]) - c.begin();
		cnt[pl] += 1;
		cnt[pr + 1] -= 1;
	}

	int sum = 0;
	forn(i, sz(c)) {
		sum += cnt[i];
		cnt[i] = sum;
	}

	int prev = -1;
	vii ans;
	forn(i, sz(c)) {
		// printf("%d ", cnt[i]);
		if  (prev == -1 && cnt[i] >= k) prev = i;
		if  (cnt[i] >= k && (i + 1 == sz(c) || cnt[i + 1] < k)) {
			ans.pb(mp(c[prev], c[i]));
			prev = -1;
		}
	}
	// puts("");

	printf("%d\n", sz(ans));
	for (auto p : ans) {
		printf("%d %d\n", p.fst / 2, p.snd / 2);
	}
	return 0;
}