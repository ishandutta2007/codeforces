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

const int MAX_N = 4e5 + 5;
const ll INFLL = 1e18;

vector<pii> g[MAX_N];
ll d[MAX_N];
vi st;
set<pair<ll, int>> dists;

void go(int l, int r) {
    while (l <= r) {
		if (l % 2 == 1)
			st.pb(l), l++;
		l /= 2;
		if (r % 2 == 0)
			st.pb(r), r--;
	   	r /= 2;
	}
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, q, s;
	scanf("%d%d%d", &n, &q, &s);
	int tSize = 1;
	while (tSize < n)
		tSize *= 2;
	s = s + tSize - 1;
	forab (i, 1, tSize)
		g[i].pb(mp(2 * i, 0)), g[i].pb(mp(2 * i + 1, 0));
	int z = 2 * tSize;
	forab (i, 1, tSize) {
	    if (i >= tSize / 2)
	    	g[2 * i].pb(mp(z + i, 0)), g[2 * i + 1].pb(mp(z + i, 0));
		else
			g[z + 2 * i].pb(mp(z + i, 0)), g[z + 2 * i + 1].pb(mp(z + i, 0));
	}
	/*
	forn (i, 3 * tSize) {
	 	printf("%d:\n", i);
	 	for (auto k : g[i])
	 		printf("%d ", k.fs);
	 	puts("");
	}
	*/
	forn (qq, q) {
		int t, v, u, l, r, w;
	 	scanf("%d%d", &t, &v);
	 	v = v + tSize - 1;
	 	if (t == 1) {
	 	 	scanf("%d%d", &u, &w);
			u = u + tSize - 1;	 	 	
	 	 	g[v].pb(mp(u, w));
	 	}
	 	if (t == 2) {
	 	 	scanf("%d%d%d", &l, &r, &w);
			st.clear();
			l += tSize - 1;
			r += tSize - 1;
			go(l, r);
			for (int k : st)
				g[v].pb(mp(k, w));
	 	}
	 	if (t == 3) {
	 	 	scanf("%d%d%d", &l, &r, &w);
			st.clear();
			l += tSize - 1;
			r += tSize - 1;
			go(l, r);
			for (int k : st)
				if (k >= tSize)
					g[k].pb(mp(v, w));
				else
					g[k + 2 * tSize].pb(mp(v, w));
	 	}
	}
	forn (i, 3 * tSize)
		d[i] = INFLL;
	d[s] = 0;
	forn (i, 3 * tSize)
		dists.insert(mp(d[i], i));
	while (sz(dists)) {
	 	auto np = *dists.begin();
	 	if (np.sc == INFLL)
	 		break;
	 	dists.erase(dists.begin());
	 	int v = np.sc;
	 	for (auto e : g[v]) {
	 		int u = e.fs;
	 	 	if (d[u] > d[v] + e.sc) {
	 	 	 	dists.erase(mp(d[u], u));
	 	 	 	d[u] = d[v] + e.sc;
	 	 	 	dists.insert(mp(d[u], u));
	 	 	}
	 	}
	}
	forn (i, n)
		if (d[i + tSize] == INFLL)
			printf("-1 ");
		else
			printf(I64 " ", d[i + tSize]);
	return 0;
}