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

int used[MAX_N];
vi cells[MAX_N], g[MAX_N];
set<int> s;

void dfs(int v) {
 	used[v] = 1;
 	for (int u : g[v])
 		if (!used[u])
 			dfs(u);
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	forn (qq, q) {
	 	int r, c;
	 	scanf("%d%d", &r, &c);
		r--;
		c--;
		s.insert(r);
		cells[r].pb(c);
	}
	forn (i, n)
		forn (j, sz(cells[i]) - 1) {
			g[cells[i][j]].pb(cells[i][j + 1]);
			g[cells[i][j + 1]].pb(cells[i][j]);
		}
	int cnt = 0;
	forn (i, m)
		if (!used[i])
			dfs(i), cnt++;
	printf("%d\n", n - sz(s) + cnt - 1);
	return 0;
}