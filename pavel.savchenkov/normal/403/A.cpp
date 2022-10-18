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

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; ++i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define all(C) (C).begin(), (C).end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;

bool g[40][40];

void addE( int a, int b ) {
	g[a][b] = g[b][a] = true;
}

void solve( int n, int p ) {
	memset (g, false, sizeof g);

	int need = 2 * n + p;
	forn(i, n) {
		addE(i, (i + 1) % n);
		need--;
	}

	forn(i, n)
		forn(j, n)
			if  (i != j && !g[i][j] && need > 0) {
				addE(i, j);
				need--;
			}

	forn(i, n)
		forn(j, n)
			if  (i < j && g[i][j])
				printf("%d %d\n", i + 1, j + 1);
}

int main() {
	int t;
	scanf("%d", &t);
	while (t --> 0) {
		int n, p;
		scanf("%d%d", &n, &p);
		solve(n, p);
	}
		
	return 0;
}