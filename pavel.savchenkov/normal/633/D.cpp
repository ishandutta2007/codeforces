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

int n;
vi a;

int brut() {
	unordered_map<int, int> cnt;

	for (int x : a) {
		++cnt[x];
	}

	set<pii> was;
	int ans = 2;
	forn(i, n) forn(j, n) {
		if  (i == j) {
			continue;
		}
		unordered_map<int, int> cur_cnt;
		int x = a[i];
		int y = a[j];
		pii C = mp(x, y);
		if  (was.count(C)) {
			continue;
		}
		was.insert(C);
		if  (!x && !y) {
			continue;
		}
		++cur_cnt[x];
		++cur_cnt[y];
		int len = 2;
		while (1) {
			int z = x + y;
			++cur_cnt[z];
			if  (cur_cnt[z] > cnt[z]) {
				break;
			}
			++len;
			x = y;
			y = z;
		}
		ans = max(ans, len);
	}

	ans = max(ans, cnt[0]);
	return ans;
}

int main() {
#ifdef DEBUG
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	scanf("%d", &n);
	a.resize(n);
	forn(i, n) {
		scanf("%d", &a[i]);
	}

	sort(all(a));
	
	cout << brut() << endl;

	return 0;
}