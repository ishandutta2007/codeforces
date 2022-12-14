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
typedef vector<int> vi;
typedef pair<int, int> pii;

#define FNAME ""

const int MAX_N = 5e3 + 5, INF = 1e9;

int dp[MAX_N][MAX_N][2], a[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i + 1]);
	forn (i, n + 1)
		forn (j, n + 1)
			dp[i][j][0] = dp[i][j][1] = INF;
	dp[0][0][0] = 0;
	forab (i, 1, n + 1) {
	 	dp[i][0][0] = 0;
 		int dlt = 0;
 		if (i != n)
 			dlt = max(0, a[i + 1] - (a[i] - 1));
 		int dlt2 = max(0, a[i - 1] - (a[i] - 1));
 		int dlt3 = max(0, min(a[i - 2] - 1, a[i - 1]) - (a[i] - 1));
	 	forab (j, 1, (i + 1) / 2 + 1) {
	 		dp[i][j][0] = min(dp[i - 1][j][0], dp[i - 1][j][1]);
	 		if (i == 1) {
	 			dp[i][j][1] = dlt;
	 			continue;
	 		}
	 		dp[i][j][1] = dp[i - 2][j - 1][0] + dlt + dlt2;
	 		if (i > 2)
		 		dp[i][j][1] = min(dp[i][j][1], dp[i - 2][j - 1][1] + dlt + dlt3);
	 	}
	}
	forab (i, 1, (n + 1) / 2 + 1)
		printf("%d ", min(dp[n][i][0], dp[n][i][1]));
	return 0;
}