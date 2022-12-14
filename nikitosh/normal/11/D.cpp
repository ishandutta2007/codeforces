#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; (i) < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i, a, b) for (int i = (a); (i) < (b); ++i)
#define forba(i, a, b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it, c) for (__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(), (c).end() 

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
#else
	#define I64 "%lld"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAX_N = 20;

int a[MAX_N][MAX_N];
ll d[(1 << MAX_N)][MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m;
	scanf("%d%d", &n, &m);
	forn (i, m) {
	 	int v, u;
	 	scanf("%d%d", &v, &u);
	 	v--, u--;
	 	a[v][u] = 1, a[u][v] = 1;
	}
	ll ans = 0;
	forab (mask, 1, (1 << n)) {
	    int ind = -1;
	 	forn (i, n)
	 		if ((mask >> i) & 1) {
	 		 	ind = i;
	 		 	break;
	 		}
		if (mask == (1 << ind)) {
		 	d[mask][ind] = 0;
		 	continue;
		}
		bool was = 0;
		forab (i, ind + 1, n) {
		 	int mask2 = mask ^ (1 << i);
		 	if (mask2 == (1 << ind)) {
		 	    if (a[ind][i])
			 	 	d[mask][i] = 1;
		 	 	was = 1;
		 	 	continue;
		 	}
		 	forab (j, ind + 1, n) {
		 	 	if (j != ind && a[i][j] && ((mask2 >> j) & 1))
		 	 		d[mask][i] += d[mask2][j];//, printf("%d %d %d\n", mask, i, d[mask][i]);
		 	}
		}
		if (was)	
			continue;
		forab (i, ind + 1, n)
			if (((mask >> i) & 1) && a[ind][i])
				ans += d[mask][i];
    }
	printf(I64 "\n", ans / 2);    	
	return 0;
}