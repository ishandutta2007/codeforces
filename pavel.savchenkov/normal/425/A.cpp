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
const int INF = int(1e9);

int K;

struct vect {
	vi a;
	int sum;

	vect() {
		sum = 0;
	}

	void insert( int x ) {
		if  (sz(a) < K) {
			a.pb(x);
			sum += x;
			return;
		}

		int mn = INF;
		forn(i, sz(a))
			mn = min(mn, a[i]);

		if  (x <= mn) {
			return;
		}

		forn(i, sz(a)) {
			if  (a[i] == mn) {
				a[i] = x;
				sum -= mn;
				sum += x;
				return;
			}
		}
	}

    void output() {
    	forn(i, sz(a)) {
    		printf("%d ", a[i]);
    	}
    	puts("");
    }    
};

int a[300];
int n;
vect pref[300];
vect suff[300];

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	scanf("%d%d", &n, &K);
	forn(i, n) {
		scanf("%d", &a[i]);
	}

	forn(i, n + 1) {
		pref[i] = vect();
		forn(j, i) {
			pref[i].insert(a[j]);
		}

		suff[i] = vect();
		for (int j = i; j < n; ++j) {
			suff[i].insert(a[j]);
		}

//		suff[i].output();
	}

	int mx = -INF;
	forn(i, n) {
		vect cur = vect();

		int sum = 0;
		for (int j = i; j < n; ++j) {
			cur.insert(-a[j]);
			sum += a[j];

			vi big;
			forn(k, sz(pref[i].a)) {
				big.pb(-pref[i].a[k]);
			}
			forn(k, sz(suff[j + 1].a)) {
				big.pb(-suff[j + 1].a[k]);
			}

			sort(all(big));
			forn(k, sz(big)) {
				big[k] = -big[k];
			}

			vi small;
			forn(k, sz(cur.a)) {
				small.pb(-cur.a[k]);
			}

			sort(all(small));

			int Sum = sum;
			forn(k, min(sz(small), sz(big))) {
				if  (small[k] >= big[k]) {
					break;
				}

				Sum -= small[k];
				Sum += big[k];	
			}

			mx = max(mx, Sum);
		}
	}

	printf("%d\n", mx);

	return 0;
}