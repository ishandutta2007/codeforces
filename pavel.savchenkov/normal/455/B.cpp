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

#define PB push_back
#define F first
#define S second
#define MP make_pair 
#define SZ(C) ((int) (C).size())
#define FORN(i, n) for (int i = 0; i < (int) n; ++i)
#define FORD(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define ALL(C) (C).begin(), (C).end()

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
typedef vector <vector<pii> > vvii;

const double EPS = 1e-9;
const int MAXN = int(1e6) + 10;

int go[MAXN][30];
bool can_win[MAXN];
bool can_lose[MAXN];
bool calced[MAXN];

int cnt = 1;

void add( int v, char *s ) {
	if  (!*s) {
		return;
	}

	int c = *s - 'a';
	if  (!go[v][c]) {
		go[v][c] = cnt++;
	}

	add(go[v][c], ++s);
}

void dfs( int v ) {
	if  (calced[v]) {
		return;
	}

	// can_win
	can_win[v] = false;
	FORN(i, 26) {
		int to = go[v][i];
		if  (to) {
			dfs(to);
			if  (!can_win[to]) {
				can_win[v] = true;
			}	
		}
	}

	// can_lose
	can_lose[v] = false;
	bool was = false;
	FORN(i, 26) {
		int to = go[v][i];
		if  (to) {
			dfs(to);
			was = true;
			if  (!can_lose[to]) {
				can_lose[v] = true;
			}
		}
	}

	if  (!was) {
		can_lose[v] = true;
	}

	calced[v] = true;
}

int n, k;
char s[MAXN];

bool solve() {
//	printf("%d %d\n", can_win[0], can_lose[0]);

	if  (can_win[0] && can_lose[0]) {
		return true;
	}

	if  (can_win[0]) {
		return k & 1;
	}

	if  (can_lose[0]) {
		return false;
	}

//	assert(false);
	return false;
}          

main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d%d\n", &n, &k);
	FORN(i, n) {
		gets(s);
		add(0, s);		
	}
/*
	FORN(i, cnt + 1) {
		FORN(j, 26) {
			if  (go[i][j]) {
				printf("%d -> %d, c = %c\n", i, go[i][j], j + 'a');
			}
		}
	}
*/
	dfs(0);

	puts(solve() ? "First" : "Second");
	return 0;
}