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


const int MAXN = 1e6 + 10;

pair<string, string> read() {
	static char t[MAXN];
	gets(t);

	string x, y;
	bool was = false;
	int n = strlen(t);
	forn(i, n) {
		if  (t[i] == '.') {
			was = true;
		} else if  (was) {
			y += t[i];
		} else {
			x += t[i];
		}
	}

	if  (x.empty()) {
		x = "0";
	}

	reverse(all(x));
	while (!x.empty() && x.back() == '0') x.pop_back();
	reverse(all(x));

	while (!y.empty() && y.back() == '0') y.pop_back();

	return mp(x, y);
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	string x, y;
	tie(x, y) = read();

	if  (x.empty()) {
		assert(!y.empty());
		int pw = 1;
		string num;
		forn(i, sz(y)) {
			if  (y[i] != '0') {
				num = y.substr(i, sz(y) - i);
				break;
			}
			++pw;
		}

		assert(!num.empty());
		if  (sz(num) > 1) {
			num = string(1, num[0]) + "." + num.substr(1, sz(num) - 1);
		}

		printf("%sE%d\n", num.data(), -pw);
		return 0;
	}

	int pw = sz(x) - 1;
	string num = x + y;
	if  (sz(num) > 1) {
		num = string(1, num[0]) + "." + num.substr(1, sz(num) - 1);
		while (num.back() == '0') {
			num.pop_back();
		}
		if  (num.back() == '.') {
			num.pop_back();
		}
	}

	if  (pw) {
		printf("%sE%d\n", num.data(), pw);
	} else {
		printf("%s\n", num.data());
	}

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}