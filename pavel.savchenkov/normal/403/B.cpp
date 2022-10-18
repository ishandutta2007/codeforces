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
const int MAXN = 5 * int(1e3) + 10;
const int MAXP = 31830;

bool prime[MAXP];
vi primes;
int a[MAXN];
int b[MAXN];
int n, m;
int pref_gcd[MAXN];

bool good( int p ) {
	int pos = lower_bound(b, b + m, p) - b;
	return pos == m || b[pos] != p;
}

int f( int x ) {
	int res = 0;
	forn(i, sz(primes)) {
		int pr = primes[i];

		bool G;
		if  (x % pr == 0) {
			G = good(pr);
			res = G ? (res + 1) : (res - 1);
			x /= pr;	
		}
		while (x % pr == 0) {
			res = G ? (res + 1) : (res - 1);
			x /= pr;	
		}
	}

	if  (x > 1) {
		int pr = x;
		res = good(pr) ? (res + 1) : (res - 1);
	}

	return res;
}

void precalc() {
	memset (prime, true, sizeof prime);
	prime[1] = false;
	for (int i = 2; i < MAXP; i++)
		if  (prime[i]) {
			primes.pb(i);
			for (int j = i + i; j < MAXP; j += i)
				prime[j] = false;
		}
}

int main() {
	precalc();

	scanf("%d%d", &n, &m);
	forn(i, n)
		scanf("%d", &a[i]);
	forn(i, m)
		scanf("%d", &b[i]);

	sort(b, b + m);

	while (1) {
		pref_gcd[0] = a[0];
		for (int i = 1; i < n; i++)
			pref_gcd[i] = __gcd(pref_gcd[i - 1], a[i]);

		int best_pos = -1;
		ford(i, n) {
			int cur_f = f(pref_gcd[i]);
			if  (cur_f < 0) {
				best_pos = i;
				break;
			}
		}

		if  (best_pos == -1) {
			break;
		}

		int g = pref_gcd[best_pos];
		forn(i, best_pos + 1)
			a[i] /= g;
	}

	int ans = 0;
	forn(i, n)
		ans += f(a[i]);

	printf("%d\n", ans);
	return 0;
}