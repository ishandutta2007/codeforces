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


bool prime(int x) {
	for (int i = 2; i * i <= x; ++i) {
		if  (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool div(int i) {
	if  (i < 2 || i > 100) {
		return false;
	}
	static int cnt = 0;
	++cnt;
	if  (cnt == 21) {
		return false;
	}
	cout << i << endl;
	string res;
	cin >> res;
	return res == "yes";
}

int main() {
#ifdef LOCAL
	// freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif


	for (int i = 2; i * i <= 100; ++i) {
		if  (!prime(i)) {
			continue;
		}

		if  (div(i)) {
			bool pr = true;
			for (int j = i + 1; j * i <= 100; ++j) {
				if  (!prime(j)) {
					continue;
				}
				if  (div(j)) {
					pr = false;
					break;
				}
			}
			if  (div(i * i)) {
				pr = false;
			}
			cout << ((pr ? "prime" : "composite")) << endl;
			return 0;
		}
	}

	cout << "prime" << endl;

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}