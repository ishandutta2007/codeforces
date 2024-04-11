#include <cassert>
#include <cmath>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <iostream>
#include <sstream>
#include <set>
#include <map>
//#include <emmintrin.h>

using namespace std;

#define FORE(it,c)  for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); ++it)
#define FOR(i,a,b)  for(int i=(a);i<(b);++i)
#define REP(i,a)    FOR(i,0,a)
#define ZERO(m)    memset(m,0,sizeof(m))
#define ALL(x)      x.begin(),x.end()
#define PB          push_back
#define S          size()
#define LL          long long
#define ULL        unsigned long long
#define LD          long double
#define MP          make_pair
#define X          first
#define Y          second
#define VC          vector
#define PII        pair <int, int>
#define VI          VC < int >
#define VVI        VC < VI >
#define VD          VC < double >
#define VVD        VC < VD >
#define VS          VC < string >
#define DB(a)      cerr << #a << ": " << (a) << endl;

template<class T> void print(VC < T > v) {cerr << "[";if (v.S) cerr << v[0];FOR(i, 1, v.S) cerr << ", " << v[i];cerr << "]\n";}
template<class T> string i2s(T x) {ostringstream o; o << x; return o.str(); }
VS splt(string s, char c = ' ') {VS all; int p = 0, np; while (np = s.find(c, p), np >= 0) {if (np != p) all.PB(s.substr(p, np - p)); p = np + 1;} if (p < s.S) all.PB(s.substr(p)); return all;}

int n, m;
int a[81][81];

#define MAXV (80*80+10)

struct Edge {
	int target;
	int flow;
	int cost;
	int reverse;
	
	Edge(int target, int flow, int cost, int reverse) {
		this->target = target;
		this->flow = flow;
		this->cost = cost;
		this->reverse = reverse;
	}
};

VC < Edge > edges[MAXV];
int prev[MAXV];
int dist[MAXV];

void addEdge(int a, int b, int flow, int cost) {
	int sa = edges[a].S;
	int sb = edges[b].S;
	edges[a].PB(Edge(b, flow, cost, sb));
	edges[b].PB(Edge(a, 0, -cost, sa));
}

int MCMF(int source, int sink, int N) {
	int totalCost = 0;
	int totalFlow = 0;

	while (true) {
		memset(dist, 0x3F, sizeof(dist));
		dist[source] = 0;
		prev[sink] = -1;
		prev[source] = -1;
		REP(step, N) {
			bool done = true;
			REP(i, N) REP(j, edges[i].S) if (edges[i][j].flow > 0 && dist[edges[i][j].target] > dist[i] + edges[i][j].cost) {
				dist[edges[i][j].target] = dist[i] + edges[i][j].cost;
				prev[edges[i][j].target] = edges[i][j].reverse;
				done = false;
			}
			if (done) break;
		}
		
		if (prev[sink] == -1 || dist[sink] > (1 << 20)) break;
		
		int maxFlow = 1 << 30;
		int v = sink;
		while (v != source) {
			int pv = edges[v][prev[v]].target;
			maxFlow = min(maxFlow, edges[pv][edges[v][prev[v]].reverse].flow);
			v = pv;
		}
		
		assert(maxFlow > 0);
		
		totalFlow += maxFlow;
		
		v = sink;
		while (v != source) {
			int pv = edges[v][prev[v]].target;
			edges[pv][edges[v][prev[v]].reverse].flow -= maxFlow;
			edges[v][prev[v]].flow += maxFlow;
			totalCost += edges[pv][edges[v][prev[v]].reverse].cost * maxFlow;
			v = pv;
		}
		
	}
	
	return totalCost;
}

int main() {
	cin >> n >> m;
	REP(i, n) REP(j, m) cin >> a[i][j];
	REP(i, n) REP(j, m) if ((i+j)%2) {
		addEdge(n*m, i*m+j, 1, 0);
		FOR(di,-1,2) FOR(dj,-1,2) if (abs(di) + abs(dj) == 1) {
			int ni = i + di;
			int nj = j + dj;
			if (ni < 0 || ni >= n || nj < 0 || nj >= m) continue;
			addEdge(i*m+j,ni*m+nj, 1, a[i][j] == a[ni][nj] ? 0 : 1);
		}
	} else {
		addEdge(i*m+j, n*m+1, 1, 0);
	}
	
	cout << MCMF(n*m, n*m+1, n*m+2) << endl;
	
}