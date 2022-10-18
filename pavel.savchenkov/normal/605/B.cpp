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

int main() {
//	freopen(FILE_NAME ".in", "r", stdin);
//	freopen(FILE_NAME ".out", "w", stdout);
  
  	int n, m;
  	scanf("%d%d", &n, &m);
  	vii in;
  	vii out;
  	forn(i, m) {
  		int a, b;
  		scanf("%d%d", &a, &b);
  		if  (b == 1) {
  			in.pb(mp(a, i));
  		} else {
  			out.pb(mp(a, i));
  		}
  	}

  	sort(all(in));
  	sort(all(out));

	vii ans(m);
	forn(i, n - 1) {
		ans[in[i].snd] = mp(i, i + 1);
	}  	

	int ptr = 0;
	for (int i = 1; i < n && ptr < sz(out); ++i) {
		for (int j = 0; j + 1 < i && ptr < sz(out); ++j) {
			int we = in[i - 1].fst;
			int they = out[ptr].fst;
			if  (they < we) {
				puts("-1");
				return 0;
			}
			ans[out[ptr].snd] = mp(i, j);
			++ptr;
		}
	}

	forn(i, m) {
		printf("%d %d\n", ans[i].fst + 1, ans[i].snd + 1);
	}

	return 0;
}