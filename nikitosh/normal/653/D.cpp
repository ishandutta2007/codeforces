#include <bits/stdc++.h> 

using namespace std;
 
#define pb push_back
#define mp make_pair
#define fs first
#define sc second
#define sz(x) (int)((x).size()) 
#define forn(i,n) for (int i = 0; (i) < (n); ++i)
#define fornr(i,n) for (int i = (n) - 1; (i) >= 0; --i)
#define forab(i,a,b) for (int i = (a); (i) < (b); ++i)
#define forba(i,a,b) for (int i = (b) - 1; (i) >= (a); --i)
#define forit(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define all(c) (c).begin(),(c).end() 

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

typedef long long LL;
typedef unsigned long long ULL;
typedef long double LD;
typedef unsigned int uint;
typedef vector <int> vi;
typedef pair <int, int> pii;

#define FNAME ""

const int MAXN = 1005, INF = 1e9;

int v[MAXN], u[MAXN], c[MAXN], used[MAXN];
vi g[MAXN];

struct Edge
{
 	int v, u;
 	LL c, f;
 	Edge(): v(0), u(0), c(0), f(0) {}
 	Edge(int v, int u, LL c, LL f): v(v), u(u), c(c), f(f) {}
};

vector <Edge> edges;

void addEdge(int v, int u, LL c)
{
	edges.pb(Edge(v, u, c, 0));
	g[v].pb(sz(edges) - 1);
	edges.pb(Edge(u, v, 0, 0));
	g[u].pb(sz(edges) - 1);
}

void push(int e, int f)
{
	edges[e].f += f;
	edges[e ^ 1].f -= f;
}

int dfs(int v, int can, int minn, int t)
{
	used[v] = 1;
	if (v == t)
		return can;
	for (int e : g[v])
	{
		if (edges[e].c >= edges[e].f + minn && !used[edges[e].u])
		{
			int fl = dfs(edges[e].u, min((LL) can, edges[e].c - edges[e].f), minn, t);	 
			if (fl >= minn)
			{
				push(e, fl);
    			return fl;
    		}
    	}
 	}	
 	return 0;
}

int main() 
{
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    
	
	int n, m, x;
	scanf("%d%d%d", &n, &m, &x);
	forn (i, m)
		scanf("%d%d%d", &v[i], &u[i], &c[i]);
	double ll = 0, rr = 1e9;
	forn (k, 80)
	{
		double mm = (ll + rr) / 2;
		forn (i, n)
			g[i].clear(), used[i] = 0;
		edges.clear();
		forn (i, m)
			addEdge(v[i] - 1, u[i] - 1, LL(c[i] / mm));
		int flow = 0;
		fornr (llog, 20)
		{
			while (1)
			{
				forn (i, n)
					used[i] = 0;
				int fl = dfs(0, INF, (1 << llog), n - 1);
				flow += fl;
				if (fl == 0)
					break;
			}
		}
		//printf("%.20f %d\n", mm, flow);
		if (flow >= x)
			ll = mm;
		else
			rr = mm;
	}
	printf("%.20f\n", ll * x);
	return 0;
}