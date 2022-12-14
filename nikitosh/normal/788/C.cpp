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

const int MAX_N = 1005, W = 250000, INF = 1e9;

int was[MAX_N], ans[2 * W + 5];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, k, l;
	scanf("%d%d", &n, &k);
	int gr = 0, ls = 0;
	forn (i, k) {
		scanf("%d", &l), was[l] = 1;
		if (l == n) {
		 	puts("1");
		 	return 0;
		}
		if (l >= n)
			gr = 1;
		if (l <= n)
			ls = 1;
	}
	if (!gr || !ls) {
		puts("-1");
		return 0;
	}
	bool run = 1;
	forn (i, 2 * W + 1)
		ans[i] = INF;
	ans[W] = 0;
	forn (i, 1001) {
		if (!was[i])
			continue;
		int r = i - n;
		if (r > 0) {
		 	forn (i, 2 * W + 1)
		 		if (ans[i] != INF && i + r <= 2 * W) {
					if (ans[i + r] > ans[i] + 1 || (i + r == W && run == 1)) {
						if (i + r == W)
							run = 0;
						ans[i + r] = ans[i] + 1;
		 		 	}	
		 		}
		}
		if (r < 0) {
		 	fornr (i, 2 * W + 1)
		 		if (ans[i] != INF && i + r >= 0) {
					if (ans[i + r] > ans[i] + 1 || (i + r == W && run == 1)) {
						if (i + r == W)
							run = 0;
						ans[i + r] = ans[i] + 1;
		 		 	}	
		 		}
		}
	}	
	printf("%d\n", ans[W]);
	return 0;
}