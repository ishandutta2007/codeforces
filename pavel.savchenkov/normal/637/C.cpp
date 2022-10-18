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

void gen() {
	ofstream os(FILE_NAME ".in");
	int n = 1000;
	os << n << endl;
	forn(i, n) {
		forn(it, 6) {
			char c = '0' + rand() % 10;
			os << c;
		}
		os << endl;
	}
}

int main() {
#ifdef DEBUG
	// freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	// gen();
	// return 0;

	int n;
	scanf("%d\n", &n);

	if  (n == 1) {
		puts("6");
		return 0;
	}
	
	vector<string> s(n);
	forn(i, n) {
		char buf[10];
		gets(buf);
		s[i] = string(buf);
	}

	int mx = 0;
	forn(i, n) for (int j = i + 1; j < n; ++j) {
		int cur = 0;
		forn(c, 6) {
			cur += (s[i][c] == s[j][c]);
		}
		mx = max(mx, cur);
	}

	// 0 -> 2, 1 -> 2, 2 -> 1,  3 -> 1, 4 -> 0, 5-> 0
	int ans = (5 - mx) / 2;
	printf("%d\n", ans);
	
	return 0;
}