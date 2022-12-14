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

const int MAX_N = 1e5 + 5;

vi g[MAX_N];
int ls[MAX_N], gr[MAX_N];

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m;
	scanf("%d%d", &n, &m);
	forn (i, m) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--, u--;
		g[min(v, u)].pb(max(v, u));
		gr[min(v, u)]++;
		ls[max(v, u)]++;
	}
	ll ans = 0;
	forn (i, n) {
		ans += gr[i] * 1ll * ls[i];
	}
	cout << ans << "\n";
	int q;
	scanf("%d", &q);
	forn (qq, q) {
		int i;
		scanf("%d", &i);
		i--;
		ans -= gr[i] * 1ll * ls[i];
		for (int k : g[i]) {
			ans -= gr[k];
			gr[k]++, ls[k]--;
			ans += ls[k];
			g[k].pb(i);
		}
		g[i].clear();
		ls[i] += gr[i], gr[i] = 0;
		cout << ans << "\n";
	}
	return 0;
}