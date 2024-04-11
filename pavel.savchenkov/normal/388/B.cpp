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
const int MAXN = int(1e3) + 10;

bool g[MAXN][MAXN];
int cnt;

void addE( int v, int u ) {
	g[v][u] = g[u][v] = true;
}

int build( int v, int k ) {
	if  (k == 0) {
		return 0;
	}

	if  (k & 1) {
		if  (k == 1) {
			addE(v, 1);
			return 1;
		}

		int v1 = cnt++;
		int v2 = cnt++;
		int v3 = cnt++;
		addE(v, v1);
		addE(v, v2);
		addE(v1, v3);
		addE(v2, v3);

		int len = build(v3, k / 2);
		len += 2;

		int prev = v;
		forn(i, len)
			if  (i == len - 1)
				addE(prev, 1);
			else {
				addE(prev, cnt++);
				prev = cnt - 1;
			}

		return len;
	} else {
		int v1 = cnt++;
		int v2 = cnt++;
		int v3 = (k == 2) ? (1) : (cnt++);
		addE(v, v1);
		addE(v, v2);
		addE(v1, v3);
		addE(v2, v3);

		if  (k == 2) {
			return 2;
	  	}

		int len = build(v3, k / 2);
		return len + 2;	
	}
}

int dp[MAXN];
bool was[MAXN];

int calc() {
	memset (dp, 0, sizeof dp);
	memset (was, false, sizeof was);

	queue <int> q;
	q.push(0);
	dp[0] = 1;
	was[0] = true;

	while (!q.empty()) {
		int v = q.front();
		q.pop();

		forn(u, cnt)
			if  (g[v][u]) {
				dp[u] += dp[v];
				
				if  (!was[u]) {
					q.push(u);
					was[u] = true;
				}
			}
	}

	return dp[1];
}

int main() {
	memset (g, false, sizeof g);

	int k;
	scanf("%d", &k);

	if  (k == 1) {
		cnt = 2;
		addE(0, 1);
		printf("%d\n", cnt);
		forn(i, cnt) {
			forn(j, cnt)
				printf("%c", g[i][j] ? 'Y' : 'N');
			puts("");
		}
		return 0;
	}

	cnt = 2;
	build(0, k);

	printf("%d\n", cnt);
	forn(i, cnt) {
		forn(j, cnt)
			printf("%c", g[i][j] ? 'Y' : 'N');
		puts("");
	}
		
	return 0;
}