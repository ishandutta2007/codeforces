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

const int MAX_N = 1e5 + 5, INF = 1e9;

int first[MAX_N], d[MAX_N], q[MAX_N], p[MAX_N], len[MAX_N], wasLen[MAX_N], cnt[MAX_N], nxt[MAX_N], needForLen[MAX_N];
vi g[MAX_N];
set<pii> needed;
map<pii, vi> ans;
char s[MAX_N];

int getNum(char *s) {
 	if (s[0] == '?')
 		return -1;
 	return atoi(s);
}

struct Edge {
  	int v, u, c, f;
  	Edge() {}
  	Edge(int v, int u, int c, int f): v(v), u(u), c(c), f(f) {}
};

vector<Edge> edges;

void addEdge(int v, int u, int c) {
    g[v].pb(sz(edges));
    edges.pb(Edge(v, u, c, 0));
    g[u].pb(sz(edges));
    edges.pb(Edge(u, v, 0, 0));
}	

void addFlow(int e, int f) {
    edges[e].f += f;
    edges[e ^ 1].f -= f;
}	

int dfs(int v, int t, int can, int curPush) {
 	if (v == t)
 		return can;
 	int sum = 0;
 	for (; first[v] < sz(g[v]); first[v]++) {
 	 	auto &e = edges[g[v][first[v]]];
 	 	if (d[e.u] != d[v] + 1 || e.c - e.f < curPush)
 	 		continue;
 	 	int flow = dfs(e.u, t, min(can, e.c - e.f), curPush);
 	 	addFlow(g[v][first[v]], flow);
 	 	can -= flow, sum += flow;
		if (can == 0)
			return sum; 	 	
 	}
 	return sum;
}

int bfs(int n, int s, int t, int curPush) {
 	forn (i, n) 
 		d[i] = INF, first[i] = 0;
 	int head = 0, tail = 0;
	d[s] = 0;
 	q[tail++] = s; 		
 	while (tail > head) {
 	    int v = q[head++];
 	    for (int edge : g[v]) {
 	     	auto &e = edges[edge];
 	     	if (e.c >= e.f + curPush && d[e.u] > d[v] + 1)
 	     		d[e.u] = d[v] + 1, q[tail++] = e.u;
 	    }
 	}	
 	return d[t] != INF;
}

int dinic(int n, int s, int t) {
    int ansFlow = 0;
 	while (bfs(n, s, t, 1))
  		ansFlow += dfs(s, t, INF, 1);
  	return ansFlow;
}

int main() {
#ifdef LOCAL    
	freopen(FNAME".in", "r", stdin);
	freopen(FNAME".out", "w", stdout); 
#endif    

	int n;
	scanf("%d", &n);
	int maxPreCycle = -1, maxInd = -1;
	forn (i, n) {
	    scanf("%s", s);
	    p[i] = getNum(s);
	    scanf("%s", s);
	    len[i] = getNum(s);
		if (len[i] != -1) {
			wasLen[len[i]] = 1;
			if (p[i] == 0)
				cnt[len[i]]++;
		}	                       	
		else
			if (maxPreCycle < p[i])
				maxPreCycle = p[i], maxInd = i;
	}	
    forab (i, 1, n + 1) {
		bool toChange = 0;
	 	if (maxInd != -1) {
	 	 	len[maxInd] = i;
	 	 	if (p[maxInd] == 0)
	 	 		cnt[i]++;
	 	 	if (!wasLen[i])
	 	 		wasLen[i] = 1, toChange = 1;
	 	}

	 	forab (j, 1, n + 1) {
	 		needForLen[j] = 0;
			if (wasLen[j]) {
				needForLen[j] = (j - (cnt[j]) % j) % j;
				if (cnt[j] == 0)
					needForLen[j] = j;
			}
		}	
		needed.clear();
	    forn (j, n)
	    	if (p[j] > 0 && len[j] != -1) {
	    	 	forab (g, 1, p[j]) 
	    	 		needed.insert(mp(g, len[j]));
	    	}
	    forn (j, n) {
	        if (p[j] > 0 && len[j] != -1)
		    	needed.erase(mp(p[j], len[j]));
	    }
	
	 	edges.clear();
	 	forn (j, 2 * n + 2 + sz(needed))
	 		g[j].clear();
	 	int s = 0;
	 	forn (j, n)
			addEdge(s, j + 1, 1);	
		int curV = n + 1;
		int t = curV + n + sz(needed);
		int needFlow = 0;
		forab (j, 1, n + 1) {
			forn (g, n)
				if ((p[g] == -1 && len[g] == -1) || (p[g] == -1 && len[g] == j) || (p[g] == 0 && len[g] == -1))
					addEdge(g + 1, curV, 1);
			//printf("%d %d\n", j, needForLen[j]);
			addEdge(curV++, t, needForLen[j]), needFlow += needForLen[j];
		}
		for (auto np : needed) {
			forn (g, n) 
				if ((p[g] == -1 && len[g] == -1) || (p[g] == -1 && len[g] == np.sc) || (p[g] == np.fs && len[g] == -1))
					addEdge(g + 1, curV, 1);
			//printf("a %d %d\n", np.fs, np.sc);				
		 	addEdge(curV++, t, 1), needFlow++;
		}

		int flow = dinic(t + 1, s, t);
		if (needFlow == flow) {
			curV = n + 1;
		    forab (j, 1, n + 1) {
				for (int edge : g[curV]) {
				 	auto &e = edges[edge];
				 	if (e.f < 0)
				 		p[e.u - 1] = 0, len[e.u - 1] = j;
				}
				curV++;
			}	
			for (auto np : needed) {
			    for (int edge : g[curV]) {
				 	auto &e = edges[edge];
				 	if (e.f < 0)
				 		p[e.u - 1] = np.fs, len[e.u - 1] = np.sc;
				}				
				curV++;
			}
			forn (j, n) {
			    if (p[j] == -1 && len[j] == -1) {
					p[j] = 0, len[j] = 1;			     	
			    } else {
			        if (p[j] == -1)
						p[j] = 1;			        	
			        else if (len[j] == -1) {
			            if (p[j] == 0)
			            	len[j] = 1;
			            else
				        	len[j] = i;
			        }
			    }
			    ans[mp(p[j], len[j])].pb(j);	
			}	
			for (auto it : ans) {
				auto np = it.fs;
				auto v = it.sc;
				if (np.fs != 0)
					for (int j : v)
						nxt[j] = ans[mp(np.fs - 1, np.sc)][0];
				else {
					assert(sz(v) % np.sc == 0);
					for (int j = 0; j < sz(v); j += np.sc) {
						forab (g, j, j + np.sc - 1)
							nxt[v[g]] = v[g + 1]; 
						nxt[v[j + np.sc - 1]] = v[j];
					}
			 	}	
			}
			forn (i, n)
				printf("%d ", nxt[i] + 1);
			return 0;
		}
		 	
	 	if (maxInd != -1) {
	 	 	len[maxInd] = -1;
	 	 	if (p[maxInd] == 0)
	 	 		cnt[i]--;
	 	 	if (toChange)
	 	 		wasLen[i] = 0;
	 	}
	}
	puts("-1");
	return 0;
}