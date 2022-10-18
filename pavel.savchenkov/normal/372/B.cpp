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
const int MAXN = 42;

char t[MAXN][MAXN];
int sum[MAXN][MAXN];
int ans[MAXN][MAXN][MAXN][MAXN];
int border_vert[MAXN][MAXN][MAXN][MAXN];
int border_gor[MAXN][MAXN][MAXN][MAXN];
int n, m, q;

int get_sum( int a, int b, int c, int d ) {
	return sum[c + 1][d + 1] - sum[c + 1][b] - sum[a][d + 1] + sum[a][b];
}

int main() {
	scanf("%d%d%d\n", &n, &m, &q);
	forn(i, n) {
		gets(t[i]);

		forn(j, m) {
			sum[i + 1][j + 1] = sum[i + 1][j] + sum[i][j + 1] - sum[i][j] + int(t[i][j] - '0');
//			printf("sum(%d, %d) = %d\n", i + 1, j + 1, sum[i + 1][j + 1]);
		}
	}

	for (int S = 1; S <= n * m; S++)
		forn(a, n)
			for (int c = a; c < n; c++)
				if  (S % (c - a + 1) == 0) {
					int SS = S / (c - a + 1);

					forn(b, m) {
						int d = SS + b - 1;

						if  (d < b || d >= m) {
							continue;
						}

						assert(S == (c - a + 1) * (d - b + 1));

//						printf("%d %d %d %d S = %d\n", a, b, c, d, S);

						if  (b + 1 <= d)
							border_gor[a][b][c][d] = border_gor[a][b + 1][c][d] + border_gor[a][b][c][d - 1] - ((b + 1 <= d - 1) ? border_gor[a][b + 1][c][d - 1] : 0);
						else
							border_gor[a][b][c][d] = 0;

						if  (a + 1 <= c)
							border_vert[a][b][c][d] = border_vert[a + 1][b][c][d] + border_vert[a][b][c - 1][d] - ((a + 1 <= c - 1) ? border_vert[a + 1][b][c - 1][d] : 0);
						else
							border_vert[a][b][c][d] = 0;

						border_vert[a][b][c][d] += get_sum(a, b, c, d) == 0;
						border_gor[a][b][c][d] += get_sum(a, b, c, d) == 0;

						if  (c - a >= 1) {
							ans[a][b][c][d] = ans[a][b][c - 1][d] + ans[a + 1][b][c][d] - ((a + 1 <= c - 1) ? ans[a + 1][b][c - 1][d] : 0);
							ans[a][b][c][d] += border_gor[a][b][c][d];		
						} else if (d - b >= 1) {
							ans[a][b][c][d] = ans[a][b + 1][c][d] + ans[a][b][c][d - 1] - ((b + 1 <= d - 1) ? ans[a][b + 1][c][d - 1] : 0);
							ans[a][b][c][d] += border_vert[a][b][c][d];		
						} else {
							ans[a][b][c][d] = get_sum(a, b, c, d) == 0;
						}
					}
				}

	while (q --> 0) {
		int a, b, c, d;
		scanf("%d%d%d%d", &a, &b, &c, &d);
	    a--;
	    b--;
	    c--;
	    d--;

	    printf("%d\n", ans[a][b][c][d]);
	}
		
	return 0;
}