#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
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
              
const int MAX_N = 512, MAX_LOG = 61;
const ll INF = 1e18 + 1;

bitset<MAX_N> d[MAX_N][MAX_LOG][2], go, nextGo;

bool can(int v, int n, ll len) {
	go.reset();
	go[v] = 1;
	int rev = 0;
	fornr (i, MAX_LOG) {
	 	if (len >= (1ll << i)) {
	 	 	len -= (1ll << i);
	 	 	nextGo.reset();
	 	 	forn (u, n)
	 	 		if (go[u] == 1) {
	 	 		 	nextGo |= d[u][i][rev];
	 	 		}
	 	 	go = nextGo;
			rev ^= 1;
	 	}
	}
	return go.count();
} 

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, m;
	scanf("%d%d", &n, &m);
	forn (i, m) {
		int v, u, t;
		scanf("%d%d%d", &v, &u, &t);
		v--, u--;
		d[v][0][t][u] = 1;
	}
	forab (i, 1, MAX_LOG) {
	    forn (v, n) {
	     	forn (k, 2) {
	     		bitset<MAX_N> &b = d[v][i - 1][k];
	     		go.reset();
	     		forn (u, n)
	     			if (b[u])
	     				go |= d[u][i - 1][1 ^ k];
	     		d[v][i][k] = go;
	    	}
	    }
	}	
	ll l = 0, r = INF + 10;
	while (r - l > 1) {
	 	ll m = (l + r) / 2;
	 	bool ok = 0;
	 	forn (v, n) {
	 	 	if (can(v, n, m)) {
	 	 	 	ok = 1;
	 	 	 	break;
	 	 	}
	 	}
	 	if (ok)
	 		l = m;
	 	else
	 		r = m;
	}
	if (l > INF)
		puts("-1");
	else
		printf(I64 "\n", l);
	return 0;
}