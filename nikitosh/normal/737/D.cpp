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

const int MAX_K = 100, MAX_N = 4005, INF = 1e9;

unordered_map<int, int> dp(MAX_N * MAX_K * MAX_K);
int a[MAX_N], sum[MAX_N];

inline int gett(int k, int l, int r) {
    return k * 4005 * 4005 + l * 4005 + r;
}	

int go(int l, int r, int k) {
 	if (r - l < k)
 		return 0;
 	if (r - l == k)
 		return sum[r] - sum[l];
 	if (r - l < 2 * k)
 		return max(sum[l + k], sum[l + k + 1]) - sum[l];
 	if (dp.count(gett(k, l, r)))	
 		return dp[gett(k, l, r)];
	int maxx = -INF;
	forab (x, k, k + 2) {
	 	int nL = l + x;
	 	if (nL > r)
	 		continue;
	 	int cur = INF;
	 	forab (y, x, x + 2) {
	 	 	int nR = r - y;
	 	 	if (nR < nL)
	 	 		continue;
	 	 	cur = min(cur, go(nL, nR, y) - (sum[r] - sum[r - y]));
	 	 	if (cur + sum[nL] - sum[l] < maxx)
	 	 		break;
	 	}
	 	if (cur == INF)
	 		cur = 0;
		maxx = max(maxx, cur + sum[nL] - sum[l]);
	}
	if (maxx == -INF)
		maxx = 0;
	return dp[gett(k, l, r)] = maxx;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

    int n;
    scanf("%d", &n);
    //n = 4000;
    forn (i, n) {
    	scanf("%d", &a[i]);
    	//a[i] = rand() % 201 - 100;
    }
    forn (i, n)
    	sum[i + 1] = sum[i] + a[i];
    printf("%d\n", go(0, n, 1));
	cerr << clock() * 1. / CLOCKS_PER_SEC;
	return 0;
}