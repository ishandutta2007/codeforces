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

const int MAX_N = 4e5 + 5;

pii a[MAX_N];
int b[MAX_N];
vi v[MAX_N];
vector<pii> ans;

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n)
		scanf("%d", &a[i].fs), a[i].sc = 2 * i + 1;
	sort(a, a + n);
	reverse(a, a + n);
	b[0] = a[0].sc;
	b[a[0].fs] = a[0].sc + 1;
	int cur = 1;			
	forab (i, 1, a[0].fs) {
		if (b[i])
			continue;
		b[i] = a[cur].sc;
		if (b[i + a[cur].fs]) {
			v[i + a[cur].fs - 1].pb(a[cur].sc + 1);
		} else
			b[i + a[cur].fs] = a[cur].sc + 1;
		cur++;
	}
	forab (i, cur, n) {
		if (a[i].fs == 1) {
			ans.pb(mp(a[i].sc, a[i].sc + 1));
			v[0].pb(a[i].sc);
		} else {
			v[0].pb(a[i].sc);
			v[a[i].fs - 2].pb(a[i].sc + 1);
		}
	}
	forn (i, 2 * n) {
		if (!b[i]) 
			break;
		if (i != 0)
			ans.pb(mp(b[i - 1], b[i]));
		for (int u : v[i])
			ans.pb(mp(b[i], u));
	}
	for (auto& np : ans)
		printf("%d %d\n", np.fs, np.sc);
	return 0;
}