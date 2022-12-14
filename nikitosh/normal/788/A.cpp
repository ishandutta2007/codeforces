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

const int MAX_N = 2e5 + 5;
const ll INFLL = 1e18;

int a[MAX_N];
ll b[MAX_N], sum[MAX_N], minn[MAX_N], maxx[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

    int n;
    scanf("%d", &n);
    forn (i, n)
    	scanf("%d", &a[i]);
    forn (i, n - 1)
    	b[i] = abs(a[i] - a[i + 1]);
	forn (i, n - 1)
		if (i % 2 == 1)
			b[i] *= (-1);
	forn (i, n - 1)
		sum[i + 1] = sum[i] + b[i];
	maxx[n - 1] = max(0ll, sum[n - 1]);
	minn[n - 1] = min(0ll, sum[n - 1]);
	fornr (i, n - 1) {
	 	maxx[i] = max(maxx[i + 1], sum[i]);
	 	minn[i] = min(minn[i + 1], sum[i]);
	}
	ll ans = -INFLL;		
	forn (i, n - 1)
		if (i % 2 == 0)
			ans = max(ans, maxx[i + 1] - sum[i]);
		else
			ans = max(ans, -(minn[i + 1] - sum[i]));
	printf(I64 "\n", ans);
	return 0;
}