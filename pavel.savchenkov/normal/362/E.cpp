#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define all(A) A.begin(), A.end()
#define sqr(x)((x) * (x))

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = 52;
const int INF = int(1e9);

struct edge {
	int v, to, cap, flow;

	edge() {}

	edge( int v, int to, int cap, int flow ) : v(v), to(to), cap(cap), flow(flow) {}
};

struct graph {
	vi g[MAXN];
	vector <edge> e;
	vi dist;
	int n;
	int FLOW;

	graph() {}

	graph(int n) : n(n) { FLOW = 0; }

	void addE( int v, int to, int cap ) {
		g[v].pb(sz(e));
		e.pb(edge(v, to, cap, 0));

		g[v].pb(sz(e));
		e.pb(edge(to, v, 0, 0));
	}

	bool addFlow() {
		int s = 0;
		int t = n - 1;

		vi dist = vi(n, INF);
		vi prev = vi(n, -1);
		queue <int> q;
		q.push(s);
		dist[s] = 0;

		while (!q.empty()) {
			int v = q.front();
			q.pop();

			forn(i, sz(g[v])) {
				int id = g[v][i];
				int to = e[id].to;

				if  (dist[to] < dist[v] + 1 || e[id].cap - e[id].flow <= 0) {
					continue;
				}

				dist[to] = dist[v] + 1;
				prev[to] = id;
				q.push(to);
			}
		}

		if  (dist[t] == INF)
			return false;

		int v = t;
		int push = INF;
		while (v != s) {
			int id = prev[v];
			push = min(push, e[id].cap - e[id].flow);
			v = e[id].v;	
		}

		v = t;
		while (v != s) {
			int id = prev[v];
			e[id].flow += push;
			e[id^1].flow -= push;
			v = e[id].v;	
		}

		FLOW += push;
		return true;	
	}

	void init() {
		while (addFlow()) {}
	}

	int addOne( int can_add ) {
		int s = 0;
		int t = n - 1;

		vi dist = vi(n, INF);
		vi prev = vi(n, -1);

		queue <int> q;
		q.push(s);
		dist[s] = 0;

		while (!q.empty()) {
			int v = q.front();
			q.pop();

			forn(i, sz(g[v])) {
				int id = g[v][i];
				int to = e[id].to;

				bool can = (e[id].cap - e[id].flow > 0);

				if  (can && dist[v] < dist[to]) {
					dist[to] = dist[v];
					prev[to] = id;
					q.push(to);
				}

				if  (!can && dist[v] + 1 < dist[to]) {
					dist[to] = dist[v] + 1;
					prev[to] = id;
					q.push(to);
				}
			}
		}

		if  (dist[t] == INF)
			return -1;

		int v = t;
		int add = 0;
		while (v != s) {
			int id = prev[v];
			if  (e[id].cap - e[id].flow <= 0) {
				add++;
				e[id].cap++;

//				printf("bad at %d -> %d\n", e[id].v + 1, e[id].to + 1);
			}

			e[id].flow++;
			e[id^1].flow--;
			v = e[id].v;	
		}

		if  (add <= can_add)
			FLOW++;

//		printf("end\n");
		return add;	
	}
};

int n, k;
graph G;

int main() {
//	freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

    scanf("%d%d", &n, &k);

    G = graph(n);

    forn(i, n)
    	forn(j, n) {
    		int c;
    		scanf("%d", &c);

    		if  (c == 0)
    			continue;

    		G.addE(i, j, c);
    	}

    G.init();

    while (k > 0) {
    	int add = G.addOne(k);

    	if  (add == -1)
    		break;

//    	assert(add > 0);

    	k -= add;
    }

    printf("%d\n", G.FLOW);
	return 0;
}