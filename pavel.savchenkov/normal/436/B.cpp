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
const int MAXN = 2000 + 10;

char a[MAXN][MAXN];
int res[MAXN];
int n, m, k;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d%d%d\n", &n, &m, &k);

	forn(i, n) {
		gets(a[i]);
	}

	memset (res, 0, sizeof res);

	forn(i, n)
		forn(j, m)
			if  (a[i][j] == 'U') {
				int len = i + 1;

				if  (len & 1) {
					++res[j];
				}
			} else if  (a[i][j] == 'L') {
				int len = i + 1;
				int jj = j - len + 1;

				if  (jj >= 0) {
					++res[jj];
				}
			} else if  (a[i][j] == 'R') {
				int len = i + 1;
				int jj = j + len - 1;

				if  (jj < m) {
					++res[jj];
				}
			}

	forn(j, m)
		printf("%d ", res[j]);

	return 0;
}