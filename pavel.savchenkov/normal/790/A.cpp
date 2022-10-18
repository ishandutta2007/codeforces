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

const int MAXN = 50 + 10;

int n, k;
bool ok[MAXN];

bool read() {
	if  (scanf("%d%d\n", &n, &k) < 2) {
		return 0;
	}
	forn(i, n - k + 1) {
		string s;
		cin >> s;
		ok[i] = (s == "YES");
		assert(s == "YES" || s == "NO");
	}
	return 1;
}

int ans[MAXN];
string names[MAXN];

void solve() {
	forn(i, n) {
		ans[i] = i;
	}

	forn(i, n - k + 1) {
		if  (!ok[i]) {
			ans[i + k - 1] = ans[i];
		}
	}

	forn(i, n) {
		const int S = 10;
		names[i].resize(S);
		forn(j, S) {
			names[i][j] = 'a' + rand() % 26;
		}
		names[i][0] = toupper(names[i][0]);
	}

	forn(i, n) {
		printf("%s ", names[ans[i]].data());
	}
	puts("");
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