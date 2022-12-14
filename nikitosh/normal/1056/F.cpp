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

const int MAX_N = 105;

double c;
double poww[MAX_N + 5];
double dp[MAX_N][MAX_N * 10], dp2[MAX_N][MAX_N * 10];
pii a[MAX_N];

bool check(double m, double t) {
 	double curA = c;
 	double curB = 1 - c * t;
 	double curC = m - t;
 	double curD = curB * curB - 4 * curA * curC;
 	if (curD < 0)
 		return 0;
	double x1 = (-curB - sqrt(curD)) / (2 * curA);
	double x2 = (-curB + sqrt(curD)) / (2 * curA);
	if (x1 > x2)
		swap(x1, x2);
	if (x1 > t || x2 < 0)
		return 0;
	return 1;
}

void update(double &val, double newVal) {
 	if (val < -0.5 || val > newVal)
 		val = newVal;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int tc;
	scanf("%d", &tc);
	poww[0] = 1;
	forab (i, 1, MAX_N)
		poww[i] = poww[i - 1] * 10. / 9;
	forn (tt, tc) {
	 	int n;
	 	double t;
	 	scanf("%d%lf%lf", &n, &c, &t);
	 	forn (i, n)
	 		scanf("%d%d", &a[i].fs, &a[i].sc);
	 	sort(a, a + n);
	 	reverse(a, a + n);
	 	forn (i, n + 1)
	 		forn (j, (n + 1) * 10 + 1)
	 			dp[i][j] = dp2[i][j] = -1;
		dp[0][0] = 0;
		forn (i, n) {
		 	fornr (j, i + 1)
		 		fornr (g, 10 * j + 1) {
		 			if (dp[j][g] != -1) {
		 				update(dp2[j][g], dp[j][g]);
		 				update(dp2[j + 1][g + a[i].sc], dp[j][g] + a[i].fs * poww[j + 1]);
					}
		 		}
			forn (j, i + 2)
				forn (g, 10 * j + 1)
					dp[j][g] = dp2[j][g], dp2[j][g] = -1;
		}
		int ans = 0;
		forn (i, n + 1)
			forn (j, 10 * n + 1) {
				if (dp[i][j] > 0) {
				 	if (t >= 10 * i && check(dp[i][j], t - 10 * i)) {
				 	    //printf("%d %d %f\n", i, j, dp[i][j]);
				 		ans = max(ans, j);	
				 	}
				}
		}
		printf("%d\n", ans);
	}

	return 0;
}