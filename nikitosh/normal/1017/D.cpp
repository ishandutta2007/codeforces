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

const int MAX_N = 5e3, MAX_K = 105;

int w[MAX_N], a[MAX_N], cnt[MAX_N][MAX_K * 15];
char s[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	forn (i, n)
		scanf("%d ", &w[i]);
	forn (i, m) {
		gets(s);
		int k = 0;
		forn (j, n)
			k = 2 * k + s[j] - '0';
		a[k]++;
	}
	forn (i, (1 << n)) {
		forn (j, (1 << n)) {
			int g = i ^ j, sum = 0;
		 	forn (k, n)
		 		if (!((g >> k) & 1)) {
					sum += w[n - k - 1];		 		 	
		 		}
		 	cnt[i][sum] += a[j];
		}
	}
	forn (qq, q) {
		int k = 0, x;
	 	scanf(" %s %d", s, &x);
	 	forn (i, n)
	 		k = 2 * k + s[i] - '0';
	 	int ans = 0;
	 	forn (i, x + 1)
	 		ans += cnt[k][i];
	 	printf("%d\n", ans);
	}
	return 0;
}