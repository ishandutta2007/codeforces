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
const int MAXN = int(1e3) + 10;

int a[MAXN][MAXN];
int dp_down_left[MAXN][MAXN];
int dp_down_right[MAXN][MAXN];
int dp_up_left[MAXN][MAXN];
int dp_up_right[MAXN][MAXN];
int n, m;
 
int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d%d", &n, &m);
	forn(i, n)
		forn(j, m)
				scanf("%d", &a[i][j]);

	forn(i, n)
		forn(j, m) {
			dp_down_left[i][j] = 0;

			if  (j) {
				dp_down_left[i][j] = max(dp_down_left[i][j], dp_down_left[i][j - 1]);	
			}

			if  (i) {
				dp_down_left[i][j] = max(dp_down_left[i][j], dp_down_left[i - 1][j]);
			}

			dp_down_left[i][j] += a[i][j];
		}

	ford(i, n)
		ford(j, m) {
			dp_down_right[i][j] = 0;

			if  (j < m - 1) {
				dp_down_right[i][j] = max(dp_down_right[i][j], dp_down_right[i][j + 1]);	
			}

			if  (i < n - 1) {
				dp_down_right[i][j] = max(dp_down_right[i][j], dp_down_right[i + 1][j]);
			}

			dp_down_right[i][j] += a[i][j];
		}

	ford(i, n)
		forn(j, m) {
			dp_up_left[i][j] = 0;

			if  (j) {
				dp_up_left[i][j] = max(dp_up_left[i][j], dp_up_left[i][j - 1]);
			}

			if  (i < n - 1) {
				dp_up_left[i][j] = max(dp_up_left[i][j], dp_up_left[i + 1][j]);
			}

			dp_up_left[i][j] += a[i][j];
		}

	forn(i, n)
		ford(j, m) {
			dp_up_right[i][j] = 0;

			if  (j < m - 1) {
				dp_up_right[i][j] = max(dp_up_right[i][j], dp_up_right[i][j + 1]);
			}

			if  (i) {
				dp_up_right[i][j] = max(dp_up_right[i][j], dp_up_right[i - 1][j]);
			}

			dp_up_right[i][j] += a[i][j];
		}

	int ans = 0;
	forn(i, n)
		forn(j, m) {
			if  (j && i < n - 1 && i && j < m - 1) {
				ans = max(ans, dp_down_left[i][j - 1] + dp_up_left[i + 1][j] + dp_down_right[i][j + 1] + dp_up_right[i - 1][j]);
			}

			if  (j && i < n - 1 && i && j < m - 1) {
				ans = max(ans, dp_down_left[i - 1][j] + dp_up_left[i][j - 1] + dp_down_right[i + 1][j] + dp_up_right[i][j + 1]);
			}
		}

	printf("%d\n", ans);
	return 0;
}