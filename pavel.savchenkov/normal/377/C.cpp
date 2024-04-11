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
const int MAXN = 110;
const int INF = int(2e9);

int who[22];
char act[22];
int s[MAXN];
int n, m;
int fbit[(1 << 20) + 10];
int dp[21][1 << 20];
bool was[21][1 << 20];

inline int calc( int i, int mask ) {
	if  (was[i][mask])
		return dp[i][mask];

	was[i][mask] = true;

	if  (i == m || mask == 0)
		return dp[i][mask] = 0;

	if  (act[i] == 'p') {
		int fb = fbit[mask];

		return dp[i][mask] = ((who[i] == 0) ? (s[fb] + calc(i + 1, mask ^ (1 << fb))) : (calc(i + 1, mask ^ (1 << fb)) - s[fb]));
	}

	int tmp_mask = mask;
	int fb = fbit[tmp_mask];
	dp[i][mask] = who[i] == 0 ? -INF : INF;
	while (tmp_mask) {
		int ndp = calc(i + 1, mask ^ (1 << fb));
		if  (who[i] == 0)
			dp[i][mask] = max(dp[i][mask], ndp);
		else
			dp[i][mask] = min(dp[i][mask], ndp);

		tmp_mask = tmp_mask ^ (1 << fb);
		fb = fbit[tmp_mask];
	}

	return dp[i][mask];
}          

void precalc() {
	for (int i = 1; i < (1 << 20); i++) {
		int x = i;		
		fbit[i] = 0;
		while (!(x & 1)) {
			fbit[i]++;
			x /= 2;
		}
	}
}

void output( int mask, int len ) {
	for (int i = 0; i < len; i++)
		printf("%c", (mask & (1 << i)) ? '1' : '0');
}

int main() {
	precalc();
	  
	scanf("%d", &n);
	forn(i, n)
		scanf("%d", &s[i]);
	sort(s, s + n);
	reverse(s, s + n);

	scanf("%d\n", &m);
	forn(i, m) {
		scanf("%c %d\n", &act[i], &who[i]);
		who[i]--;
	}

	memset (was, false, sizeof was);
	
	printf("%d\n", calc(0, (1 << m) - 1));				
	return 0;
}