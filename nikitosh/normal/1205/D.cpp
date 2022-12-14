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

const int INF = 1e9 + 5;
const int MAX_N = 1e4 + 5;

vi g[MAX_N];
int siz[MAX_N];
vector<pair<pii, int>> ans;
vi toFill, small, big;
int curIt, centroid;

int find(int v, int p, int total) {
	int size = 1, ok = 1;
	for (int to : g[v]) 
		if (to != p) {
			int s = find(to, v, total);
			if (s > total / 2) ok = 0;
			size += s;
		}
	if (ok && size > total / 2) 
		centroid = v;
	return size;
}

void dfs(int v, int p) {
	siz[v] = 1;
 	for (int u : g[v])
 		if (u != p) {
 			dfs(u, v);
 			siz[v] += siz[u];
 		}
}

void fillDfs(int v, int p, int up) {
 	for (int u : g[v])
 		if (u != p) {
 			int w = toFill[curIt++] - up;
 			ans.pb(mp(mp(v, u), w));
 			fillDfs(u, v, up + w);
 		}
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	forn (i, n - 1) {
	 	int v, u;
	 	scanf("%d%d", &v, &u);
	 	v--, u--;
	 	g[v].pb(u);
	 	g[u].pb(v);
	}
	find(0, -1, find(0, -1, INF));
	int v = centroid;
	dfs(v, -1);
	bool was = 0;
	int s = 0;
	for (int u : g[v])
		if (siz[u] >= n / 3) {
			s = siz[u];
			for (int w : g[v])
				if (w != u)
					big.pb(w);
				else
					small.pb(w);
			was = 1;
			break;	 	
		}
	if (!was) {
		int cur = 0;
		forn (i, sz(g[v])) {
			cur += siz[g[v][i]];
			small.pb(g[v][i]);
			if (cur >= n / 3) {
			 	forab (j, i + 1, sz(g[v]))
			 		big.pb(g[v][j]);
			 	if (cur > n - 1 - cur) {
			 		swap(small, big);
			 		cur = n - 1 - cur;
			 	}
			 	s = cur;
			 	break;
			}
		}
	}
	g[v] = small;
	toFill.clear();
	forn (i, s)
		toFill.pb(i + 1);
	curIt = 0;
	fillDfs(v, -1, 0);
	g[v] = big;
	toFill.clear();
	forn (i, n - s - 1)
		toFill.pb((i + 1) * (s + 1));
	curIt = 0;
	fillDfs(v, -1, 0);
	for (auto np : ans)
		printf("%d %d %d\n", np.fs.fs + 1, np.fs.sc + 1, np.sc);
	return 0;
}