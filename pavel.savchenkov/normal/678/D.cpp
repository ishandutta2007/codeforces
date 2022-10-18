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
const int MOD = 1e9 + 7;

void add(int& x, int y) {
	((x += y) >= MOD) && (x -= MOD);
}

int mul(int x, int y) {
	return x * 1ll * y % MOD;
}

struct Matr {
	vvi a;

	Matr(int n = 0) {
		a.assign(n, vi(n, 0));
	}

	vi& operator[](int i) {
		return a[i];
	}

	const vi& operator[](int i) const {
		return a[i];
	}

	Matr& operator *= (const Matr& other) {
		const int n = sz(a);
		vvi c(n, vi(n, 0));
		forn(i, n) forn(j, n) {
			forn(k, n) {
				add(c[i][j], mul(a[i][k], other[k][j]));
			}
		}
		a.swap(c);
		return *this;
	}
};

int a, b, x;
ll n;

Matr mpow(Matr a, ll p) {
	const int n = sz(a.a);
	Matr res(n);
	forn(i, n) res[i][i] = 1;
	for (; p > 0; a *= a, p /= 2) {
		if  (p & 1) {
			res *= a;
		}
	}
	return res;
}

int solve() {
	Matr z(2);
	z[0][0] = a;
	z[0][1] = b;
	z[1][1] = 1;

	z = mpow(z, n);

	int ans = mul(z[0][0], x);
	add(ans, z[0][1]);
	return ans;
}

int main() {
#ifdef LOCAL
	freopen(FILE_NAME ".in", "r", stdin);
	// freopen(FILE_NAME ".out", "w", stdout);
#endif

	cin >> a >> b >> n >> x;

	cout << solve() << endl;

#ifdef LOCAL
	printf("Time: %.2f\n", (double) clock() / CLOCKS_PER_SEC);
#endif
	return 0;
}