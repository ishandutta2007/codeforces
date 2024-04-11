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
const int MAXN = 72;
const int INF = int(1e9);

struct state {
	int a, b, c;

	state( int a, int b, int c ) : a(a), b(b), c(c) {}
};

int dp[MAXN][MAXN][MAXN];
pii prev[MAXN][MAXN][MAXN];
char color[MAXN][MAXN];
int n;

void sort( int& a, int& b, int& c ) {
	if  (b > c)
		swap(b, c);

	if  (a > b)
		swap(a, b);

	if  (b > c)
		swap(b, c);
}

void restore( int a, int b, int c ) {
	sort(a, b, c);

	if  (dp[a][b][c] == 0) {
		return;
	}

	int from = prev[a][b][c].s;
	int to = prev[a][b][c].f;

	if  (to == a) {
		int A = from;
		int B = b;
		int C = c;
		restore(A, B, C);
	} else if  (to == b) {
		int A = a;
		int B = from;
		int C = c;
		restore(A, B, C);
	} else {
		int A = a;
		int B = b;
		int C = from;
		restore(A, B, C);
	}

	printf("%d %d\n", from + 1, to + 1);
}

int main() {
	scanf("%d", &n);

	forn(i, n)
		forn(j, n)
			forn(k, n)
				dp[i][j][k] = INF;

	int a, b, c;
	scanf("%d%d%d\n", &a, &b, &c);
	a--;
	b--;
	c--;
	sort(a, b, c);

	forn(i, n)
		gets(color[i]);

	queue <state> q;
	q.push(state(a, b, c));
	dp[a][b][c] = 0;
	while (!q.empty()) {
		state cur_state = q.front();
		q.pop();

		a = cur_state.a;
		b = cur_state.b;
		c = cur_state.c;
		int cur_dp = dp[a][b][c];

		forn(next, n) {
			if  (next == a || next == b || next == c)
				continue;

			forn(it, 3) {
				if  (color[next][a] == color[b][c]) {
					int A, B, C;
					A = next;
					B = b;
					C = c;

					sort(A, B, C);

					if  (dp[A][B][C] > cur_dp + 1) {
						dp[A][B][C] = cur_dp + 1;
						prev[A][B][C] = mp(next, a);
						q.push(state(A, B, C));
					}
				}

				int tmp = a;
				a = b;
				b = c;
				c = tmp;
			}
		}
	}

	if  (dp[0][1][2] >= INF) {
		puts("-1");
		return 0;
	}

	printf("%d\n", dp[0][1][2]);
	restore(0, 1, 2);	
	return 0;
}