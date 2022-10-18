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
const int MAXN = int(1e6) + 10;

int n, k;
int pos[MAXN];
bool del[MAXN];

int fenw[MAXN];

void upd( int pos, int add ) {
	for (int i = pos; i < MAXN; i = (i | (i + 1)))
		fenw[i] += add;
}

int sum( int r ) {
	int res = 0;
	for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
		res += fenw[i];
	return res;
}

int get_len( int l, int r ) {
	return sum(r) - sum(l - 1);
}

set <pii> segments;

void go_del( int x, bool fucking_del ) {
	x = pos[x];

	if  (!fucking_del) {
		upd(x, -1);
		return;
	}

	set <pii> :: iterator it = segments.upper_bound(mp(x, n));
	assert(it != segments.begin());
	it--;

	int l = it->f;
	int r = it->s;

	assert(l <= x && x <= r);

	segments.erase(it);

	if  (l <= x - 1) {
		segments.insert(mp(l, x - 1));
	}

	if  (x + 1 <= r) {
		segments.insert(mp(x + 1, r));
	}
}             

int go( int x ) {
	x = pos[x];

	set <pii> :: iterator it = segments.upper_bound(mp(x, n));
	assert(it != segments.begin());
	it--;

	int l = it->f;
	int r = it->s;

	assert(l <= x && x <= r);

	return get_len(l, r);
}                

int main() {
	memset (del, true, sizeof del);
	scanf("%d%d", &n, &k);
	forn(i, n) {
		int p;
		scanf("%d", &p);
		p--;
		pos[p] = i;
	}
	forn(i, k) {
		int b;
		scanf("%d", &b);
		b--;
		del[b] = false;
	}

	segments.insert(mp(0, n - 1));
	ll ans = 0;

	memset(fenw, 0, sizeof fenw); 	
	forn(i, n)
		upd(i, 1);
		
	forn(i, n) {
		if  (!del[i]) {
			go_del(i, true);
		} else {
			ans += go(i);
			go_del(i, false);
		}
    }

	cout << ans << '\n';	
	return 0;
}