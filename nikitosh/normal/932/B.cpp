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

const int MAX_N = 1e6 + 5, MAX_Q = 2e5 + 5;

int dp[MAX_N], sum[MAX_N], l[MAX_Q], r[MAX_Q], k[MAX_Q], ans[MAX_Q];

inline int f(int n) {
	int ans = 1;
 	while (n) {
 	 	if (n % 10 != 0)
 	 		ans *= (n % 10);
 	 	n /= 10;
 	}
 	return ans;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	forn (i, 10)
		dp[i] = i;
	forab (i, 10, (int) 1e6 + 1) {
		dp[i] = dp[f(i)];
	}
	int q;
	scanf("%d", &q);
	forn (qq, q) {
		scanf("%d%d%d", &l[qq], &r[qq], &k[qq]);
	}	
	forab (j, 1, 10) {
	 	forab (i, 1, (int) 1e6 + 1) 
	 		sum[i] = 0;
	 	forab (i, 1, (int) 1e6 + 1) {
	 		sum[i] = sum[i - 1];
	 		if (dp[i] == j)
				sum[i]++;
		}
		forn (qq, q)
			if (k[qq] == j)
				ans[qq] = sum[r[qq]] - sum[l[qq] - 1];
	}
	forn (qq, q)
		printf("%d\n", ans[qq]);
	return 0;
}