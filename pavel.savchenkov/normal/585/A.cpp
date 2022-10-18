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


const int MAXN = 4e3 + 10;

int n;
int v[MAXN];
int p[MAXN];
int d[MAXN];
bool alive[MAXN];

bool read() {
	if  (scanf("%d", &n) < 1) {
		return false;
	}
	forn(i, n) {
		scanf("%d%d%d", &v[i], &d[i], &p[i]);
	}
	return true;
}

vi solve() {
	memset (alive, true, sizeof alive);
	vi res;
	forn(i, n) {
		if  (!alive[i]) {
			continue;
		}
		res.pb(i + 1);
		
		int dec = v[i];
		for (int j = i + 1; j < n; ++j) {
			if  (!alive[j]) {
				continue;
			}
			p[j] = max(p[j] - dec, -1);
			dec = max(0, dec - 1);
		}

		while (1) {
			bool was = false;
			for (int j = i + 1; j < n; ++j) {
				if  (!alive[j]) {
					continue;
				}
				if  (p[j] < 0) {
					for (int k = j + 1; k < n; ++k) {
						p[k] = max(p[k] - d[j], -1);
					}
					alive[j] = false;
					was = true;
					break;
				}
			}
			if  (!was) {
				break;
			}
		}
	}
	return res;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif


	while (read()) {
		auto res = solve();
		printf("%d\n", sz(res));
		for (int x : res) {
			printf("%d ", x);
		}
		puts("");
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}