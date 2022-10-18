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


const int MAXN = 1e5 + 10;

set<pair<char, char>> eq;

void add(char c1, char c2) {
	eq.insert(mp(c1, c2));
	eq.insert(mp(c2, c1));
}

bool check(char c1, char c2) {
	return eq.count(mp(c1, c2));
} 

bool pal(const string& s) {
	if  (sz(s) % 2 == 1) {
		if  (!check(s[sz(s) / 2], s[sz(s) / 2])) {
			return false;
		}
	}
	forn(i, sz(s)) {
		if  (!check(s[i], s[sz(s) - i - 1])) {
			return false;
		}
	}
	return true;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	add('A', 'A');
	add('O', 'O');
	add('o', 'o');
	add('H', 'H');
	add('I', 'I');
	add('M', 'M');
	add('T', 'T');
	add('U', 'U');
	add('V', 'V');
	add('v', 'v');
	add('W', 'W');
	add('w', 'w');
	add('X', 'X');
	add('x', 'x');
	add('Y', 'Y');
	add('d', 'b');
	add('p', 'q');

	string s;
	cin >> s;

	puts(pal(s) ? "TAK" : "NIE");

#ifdef LOCAL
	cerr.precision(5);
	cerr << "Time: " << fixed << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
	return 0;
}