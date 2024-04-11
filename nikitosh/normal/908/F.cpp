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

const int INF = 2e9;
const int MAX_N = 3e5 + 5;

vi g, r, b;
int maxR[MAX_N], maxB[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n) {
		int x;
		char ch;
		scanf("%d %c", &x, &ch);
		if (ch == 'G')
			g.pb(x);
		if (ch == 'R')
			r.pb(x);
		if (ch == 'B')
			b.pb(x);
	}	
	if (sz(g) == 0) {
	    ll ans = 0;
	 	forn (i, sz(b) - 1)
	 		ans += b[i + 1] - b[i];	
	 	forn (i, sz(r) - 1)
	 		ans += r[i + 1] - r[i];
	 	printf(I64 "\n", ans);
	 	return 0;
	}
	ll ans = 0;
	if (sz(b) > 0) {
		if (b[0] < g[0])
			ans += g[0] - b[0];		
		if (b.back() > g.back())
			ans += b.back() - g.back();
	}
	if (sz(r) > 0) {
		if (r[0] < g[0])
			ans += g[0] - r[0];		
		if (r.back() > g.back())
			ans += r.back() - g.back();
	}
	forn (i, sz(b)) {
		if (b[i] > g[0] && b[i] < g.back()) {
			int k = lower_bound(all(g), b[i]) - g.begin() - 1;
			if (i != 0 && b[i - 1] > g[k]) 
				maxB[k] = max(maxB[k], b[i] - b[i - 1]);
			else
				maxB[k] = max(maxB[k], b[i] - g[k]);
			if (i == sz(b) - 1 || b[i + 1] > g[k + 1])
				maxB[k] = max(maxB[k], g[k + 1] - b[i]);
     	}	
	}	
	forn (i, sz(r)) {
		if (r[i] > g[0] && r[i] < g.back()) {
			int k = lower_bound(all(g), r[i]) - g.begin() - 1;
			if (i != 0 && r[i - 1] > g[k]) 
				maxR[k] = max(maxR[k], r[i] - r[i - 1]);
			else
				maxR[k] = max(maxR[k], r[i] - g[k]);
			if (i == sz(r) - 1 || r[i + 1] > g[k + 1])
				maxR[k] = max(maxR[k], g[k + 1] - r[i]);
     	}	
	}	
	forn (i, sz(g) - 1) {
		if (maxR[i] == 0 && maxB[i] == 0)
			ans += g[i + 1] - g[i];
		else {
		 	if (maxR[i] == 0)
		 		ans += 2 * (g[i + 1] - g[i]) - maxB[i];
			else {
			 	if (maxB[i] == 0)
			 		ans += 2 * (g[i + 1] - g[i]) - maxR[i];
				else
					ans += min(2ll * (g[i + 1] - g[i]), 3ll * (g[i + 1] - g[i]) - maxR[i] - maxB[i]);
			}	
		}
	}
	printf(I64 "\n", ans);
	return 0;
}