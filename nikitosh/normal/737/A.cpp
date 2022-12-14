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

const ll INFLL = 1e18;
const int MAX_N = 4e5 + 5;

pii a[MAX_N];
int g[MAX_N];
vector<ll> dists, sums;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, k, s, t;
	scanf("%d%d%d%d", &n, &k, &s, &t);
	forn (i, n)
		scanf("%d%d", &a[i].fs, &a[i].sc);
	g[0] = 0;
	forn (i, k)
		scanf("%d", &g[i + 1]);
	g[k + 1] = s;
	sort(g, g + k + 2);
	int maxDist = 0;
	forn (i, k + 1) {
		maxDist = max(maxDist, g[i + 1] - g[i]);
		dists.pb(g[i + 1] - g[i]);
	}
	sort(all(dists));
	sums.resize(sz(dists));
	sums[0] = dists[0];
	forab (i, 1, sz(dists))
		sums[i] = sums[i - 1] + dists[i];
	ll minCost = INFLL;
	forn (i, n) {
		if (a[i].sc >= maxDist) {
		 	int l = upper_bound(all(dists), a[i].sc / 2) - dists.begin();
			ll curAns = 0;
			if (l > 0)
				curAns += sums[l - 1];
			curAns += ((sums.back() - curAns) * 3) - a[i].sc * 1ll * (k - l + 1);
			if (curAns <= t)
				minCost = min(minCost, (ll) a[i].fs);
			//printf("%I64d\n", curAns);
		}
	}
	if (minCost == INFLL)
		minCost = -1;
	printf(I64 "\n", minCost);
	return 0;
}