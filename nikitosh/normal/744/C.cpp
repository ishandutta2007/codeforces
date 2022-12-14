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

const int INF = 1e9 + 10;
const int MAX_N = 16, MAX_MASK = (1 << 16) + 5;

vector<pii> dp[MAX_MASK], dp2;
int a[MAX_N], b[MAX_N];
char c[MAX_N];

void relax(int ind, int &cntA, int &cntB, int dlt) {
	if (c[ind] == 'R')
   		cntA += dlt;
   	else
   		cntB += dlt;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n) {
	 	scanf(" %c%d%d", &c[i], &a[i], &b[i]);
	}
	dp[0].pb(mp(0, 0));
	forab (mask, 1, (1 << n)) {
	    int cntA = 0, cntB = 0;
	 	forn (i, n)
	 		if ((mask >> i) & 1) {
	 		 	relax(i, cntA, cntB, 1);
	 		}
	 	forn (i, n)
	 		if ((mask >> i) & 1) {
	 		 	relax(i, cntA, cntB, -1);
	 		 	for (auto np : dp[mask ^ (1 << i)])
	 		 		dp[mask].pb(mp(np.fs + max(0, a[i] - cntA), np.sc + max(0, b[i] - cntB)));
	 		 	relax(i, cntA, cntB, 1);
	 		}
		sort(all(dp[mask]));
		dp2.clear();
        for (auto np : dp[mask])
			if (sz(dp2) == 0 || dp2.back().sc > np.sc)
				dp2.pb(np);
		dp[mask] = dp2;
	}
	int ans = INF;
	for (auto np : dp[(1 << n) - 1])
		ans = min(ans, max(np.fs, np.sc));
	printf("%d\n", ans + n);
	return 0;
}