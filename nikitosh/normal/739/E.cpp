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

const int MAX_N = 2e3 + 5, INF = 2e9 + 10;

vi g[MAX_N];
int p1[MAX_N], p2[MAX_N], q[MAX_N], pr[MAX_N], inQ[MAX_N], d[MAX_N];

struct Edge {
  	int v, u, c, f, w;
  	Edge() {}
  	Edge(int v, int u, int c, int f, int w): v(v), u(u), c(c), f(f), w(w) {}
};

vector<Edge> edges;

void addEdge(int v, int u, int c, int w) {
 	g[v].pb(sz(edges));
 	edges.pb(Edge(v, u, c, 0, w));
 	g[u].pb(sz(edges));
 	edges.pb(Edge(u, v, 0, 0, -w));
}

void addFlow(int e, int f) {
 	edges[e].f += f;
 	edges[e ^ 1].f -= f;
}

int fordBellman(int n, int s, int t) {
	forn (i, n)
		inQ[i] = 0, d[i] = INF;	
	d[s] = 0;
	int head = 0, tail = 0;
	q[tail++] = s;
	while (tail > head) {
	 	int v = q[head++];
	 	inQ[v] = 0;
	 	for (int edge : g[v]) {
			auto &e = edges[edge];
			if (e.f < e.c && d[e.u] > d[e.v] + e.w) {
				d[e.u] = d[e.v] + e.w;
				pr[e.u] = edge;
				if (!inQ[e.u])
					inQ[e.u] = 1, q[tail++] = e.u;
			}
		}
	}
	return d[t];
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n, a, b;
	scanf("%d%d%d", &n, &a, &b);
	int s = 0;
	addEdge(s, 1, a, 0);
	addEdge(s, 2, b, 0);
	forn (i, n) {
	    int q1, q2;
		scanf("%d.%d", &q1, &q2);
		p1[i] = (q1 * 1000 + q2) * 1000;
	}
	forn (i, n) {
	    int q1, q2;
		scanf("%d.%d", &q1, &q2);
		p2[i] = (q1 * 1000 + q2) * 1000;
	}
	int t = n + 3;
	forn (i, n) {
	 	addEdge(1, i + 3, 1, -p1[i]);
	 	addEdge(2, i + 3, 1, -p2[i]);
	 	addEdge(i + 3, t, 1, 0);
	 	addEdge(i + 3, t, 1, p1[i] / 1000 * p2[i] / 1000);
	}	
	int ans = 0, dist = 0;
	while ((dist = fordBellman(n + 4, s, t)) != INF) {
		int minFlow = INF;
		for (int cur = t; cur != s; cur = edges[pr[cur]].v)
			minFlow = min(minFlow, edges[pr[cur]].c - edges[pr[cur]].f);
		for (int cur = t; cur != s; cur = edges[pr[cur]].v)
			addFlow(pr[cur], minFlow);
		ans += dist * minFlow;
	}	
	printf("%.20f\n", -ans / 1e6);
	return 0;
}