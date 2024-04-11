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
const int INF = int(2e9);
const int MAXN = int(1e6) + 10;

struct solver {
	vi balance;
	vi t;
	int sz;

	solver() {}

	solver( const vi & balance ) : balance(balance) {
		sz = 1;
		while (sz < sz(balance)) sz <<= 1;

		t.assign(sz << 1, INF);

		forn(v, sz(balance))
			t[sz + v] = balance[v];
		for (int v = sz - 1; v >= 1; v--)
			t[v] = min(t[v * 2], t[v * 2 + 1]);
	}

	int get_min( int l, int r ) {
		int res = INF;
		l += sz;
		r += sz;
		while (l <= r) {
			res = min(t[r], res);
			res = min(t[l], res);
			r = (r - 1) / 2;
			l = (l + 1) / 2;
		}
		return res;
	}

	int get_skipped_closes( int l, int r ) {
		int min_balance = get_min(l, r) - ((l == 0) ? 0 : balance[l - 1]);
		return max(0, -min_balance);
	}	
};

char s[MAXN];
int n;
solver solver1, solver2;

int main() {
	gets(s);
	n = (int) strlen(s);

	vi balance(n);
	balance[0] = s[0] == '(' ? 1 : -1;
	for (int i = 1; i < n; i++)
		balance[i] = balance[i - 1] + ((s[i] == '(') ? 1 : -1);
	solver1 = solver(balance);

	reverse(s, s + n);
	balance[0] = s[0] == ')' ? 1 : -1;
	for (int i = 1; i < n; i++)
		balance[i] = balance[i - 1] + ((s[i] == ')') ? 1 : -1);
	solver2 = solver(balance);

	int m;
	scanf("%d", &m);
	while (m --> 0) {
		int l, r;
		scanf("%d%d", &l, &r);
		l--;
		r--;

		int skip_closes = solver1.get_skipped_closes(l, r);
		int skip_opens = solver2.get_skipped_closes(n - r - 1, n - l - 1);

		printf("%d\n", r - l + 1 - skip_closes - skip_opens);
	}	
	return 0;
}