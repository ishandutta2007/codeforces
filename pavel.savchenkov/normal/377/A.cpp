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

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < (int) n; i++)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = (int) a; i < (int) n; i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgk
#define right yytrwtretywretwreytwreytwr
#define all(A) A.begin(), A.end()

template <typename T>
inline T sqr( T x ) {
	return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = 510;
const int dx[4] = { 1, -1, 0, 0 };
const int dy[4] = { 0, 0, 1, -1 };

char a[MAXN][MAXN];
bool was[MAXN][MAXN];
int n, m;
int k;

bool on( int x, int y ) {
	return 0 <= x && x < n && 0 <= y && y < m;
}

int dfs( int x, int y ) {
	was[x][y] = true;
	int sons = 0;

	forn(i, 4) {
		int X = x + dx[i];
		int Y = y + dy[i];

		if  (on(X, Y) && !was[X][Y] && a[X][Y] == '.') {
			sons += dfs(X, Y);
		}
	}

	if  (sons == 0 && k > 0) {
		a[x][y] = 'X';
		k--;
		return 0;
	}

	return 1;
}

int main() {
	scanf("%d%d%d\n", &n, &m, &k);

	forn(i, n)
		gets(a[i]);

	memset (was, false, sizeof was);

	forn(i, n)
		forn(j, m)
			if  (a[i][j] == '.') {
				dfs(i, j);
				break;
			}

	forn(i, n)
		puts(a[i]);
			
	return 0;
}