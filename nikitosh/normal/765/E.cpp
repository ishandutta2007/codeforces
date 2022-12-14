#define FNAME ""

#undef __STRICT_ANSI__

#include <bits/stdc++.h> 

using namespace std;

#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define fst first
#define snd second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (int)(n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (int)(b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end()

#ifdef LOCAL
	#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
	#define eprintf(...) static_cast<void>(0)   
#endif

#ifdef _WIN32
	#define I64 "%I64d"
	#define U64 "%I64u"
#else
	#define I64 "%lld"
	#define U64 "%llu"
#endif

typedef long long ll;
typedef unsigned long long ull;
typedef double dbl;
typedef long double ld;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

const int MAX_N = 2e5 + 5;

int par[MAX_N], up[MAX_N], deg[MAX_N], used[MAX_N];
vi g[MAX_N], gr[MAX_N], solo[MAX_N], rem[MAX_N];

void dfs1(int v, int p) {
	par[v] = p;
	for (int u : g[v])
		if (u != p)
			dfs1(u, v);
}
	
int dfs2(int v) {
	vector<pii> lens;
	for (int u : gr[v]) {
		int newV = dfs2(u);
		if (deg[newV] == 1) {
			lens.pb(mp(up[newV], newV));
		} else {
			rem[v].pb(newV);
		}
	}
	sort(all(lens));
	forn (i, sz(lens))
		if (i == 0 || lens[i].fs != lens[i - 1].fs)
			solo[v].pb(lens[i].sc);
	if (sz(rem[v]) == 0 && sz(solo[v]) == 1) {
		int u = solo[v][0];
		up[u] += up[v];
		return u;
	}
	return v;
}	

int getAns(int v) {
	while (v % 2 == 0)
		v /= 2;
	return v;
}

void fix(int v) {
	if (sz(rem[v]) >= 2 || sz(rem[v]) + sz(solo[v]) >= 3) {
		puts("-1");
		return;
	}
	if (sz(rem[v]) == 0) {
		int sum = 0;
		for (int u : solo[v])
			sum += up[u];
		printf("%d\n", getAns(sum));
		return;
	}
	int sum = 0;
	if (sz(solo[v]) == 1)
		sum += up[solo[v][0]];
	int u = rem[v][0];
	sum += up[u];
	for (int w : solo[u])
		if (up[w] == sum) {
			fix(u);
			return;
		}
	puts("-1");
	return;
}
	
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n;
	scanf("%d", &n);
	forn (i, n - 1) {
		int v, u;
		scanf("%d%d", &v, &u);
		v--, u--;
		g[v].pb(u), g[u].pb(v);
		deg[v]++, deg[u]++;
	}
	dfs1(0, -1);
	forn (i, n) 
		if (sz(g[i]) == 1) {
			int v = i;
			while (!used[v] && v != 0) {
				used[v] = 1;
				int curV = par[v], curLen = 1;
				while (curV != 0 && sz(g[curV]) == 2)
					curV = par[curV], curLen++;
				gr[curV].pb(v);
				up[v] = curLen;
				v = curV;		
			}	
		}
	dfs2(0);
	fix(0);	
	return 0;
}