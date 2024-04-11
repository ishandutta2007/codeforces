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

const int MAX_N = 85, INF = 1e9;

int dp[MAX_N][MAX_N][MAX_N][2];
vector<pii> gr[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, k, m;
	scanf("%d%d%d", &n, &k, &m);
	forn (i, m) {
	 	int v, u, c;
	 	scanf("%d%d%d", &v, &u, &c);
	 	v--, u--;
	 	if (v == u)
	 		continue;
	 	gr[v].pb(mp(u, c));
	 	//gr[u].pb(mp(v, c));
	}
	forn (g, k + 1)
		forn (l, n)
			forn (r, n)
				forn (j, 2)
					dp[g][l][r][j] = INF;
	forn (r, n)
		forn (l, r + 1)
			dp[1][l][r][0] = dp[1][l][r][1] = 0;
	
	forab (g, 2, k + 1) {
	 	forn (r, n)
	 		forn (l, r + 1) {
	 			for (auto np : gr[l]) {
	 				int u = np.fs, c = np.sc;
                	if (u >= l && u <= r) {
                	 	dp[g][l][r][0] = min(dp[g][l][r][0], min(dp[g - 1][u][r][0], dp[g - 1][l + 1][u][1]) + c);
                	}
                }
	 			for (auto np : gr[r]) {
	 				int u = np.fs, c = np.sc;
                	if (u >= l && u <= r) {
                	 	dp[g][l][r][1] = min(dp[g][l][r][1], min(dp[g - 1][l][u][1], dp[g - 1][u][r - 1][0]) + c);
                	}
                }
	 		}	
	}
	int minn = INF;
	forn (r, n)
		forn (l, r + 1)
			forn (j, 2)
				minn = min(minn, dp[k][l][r][j]);
	if (minn == INF)
		minn = -1;
	printf("%d\n", minn);
	return 0;
}