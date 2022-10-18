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
const int MAXN = 1e5 + 10;

int h[MAXN];
int n;
int final_pos[MAXN];

int main() {
//	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);

	cin >> n;
	forn(i, n) scanf("%d", &h[i]);

	vi sh(n);
	forn(i, n) sh[i] = h[i];
	sort(all(sh));

	map<int, int> seen;
	forn(i, n) {
		int pos = lower_bound(all(sh), h[i]) - sh.begin();
		pos += seen[h[i]];
		seen[h[i]] += 1;
		final_pos[i] = pos;
	}

	int last_end = -1;
	int mn = 2e9;
	int mx = -2e9;
	int cnt = 0;
	forn(i, n) {
		mn = min(mn, final_pos[i]);
		mx = max(mx, final_pos[i]);
		if  (mn == last_end + 1 && mx == i) {
			++cnt;
			mn = 2e9;
			mx = -2e9;
			last_end = i;
		}
	}

	printf("%d\n", cnt);
	return 0;
}