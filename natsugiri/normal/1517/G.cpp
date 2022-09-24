#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<map>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

struct Dinic {
    typedef LL Flow;
    static const Flow INF = 1LL<<50;
    struct Edge {
	int src, dst;
	Flow cap;
	int rev;
    };
    typedef vector<vector<Edge> > Graph;
    Graph G;
    vector<int>len, iter;
    Dinic(int N) : G(N) {}
    void add_edge(int u, int v, Flow c) {
	G[u].push_back((Edge){ u, v, c, (int)G[v].size() });
	G[v].push_back((Edge){ v, u, 0, (int)G[u].size()-1 });
    }
    Flow dfs(int v, int s, Flow c) {
	if (v == s || c == 0) return c;
	Flow ret = 0;
	for (int &i=iter[v]; i<(int)G[v].size(); i++) {
	    Edge &e = G[v][i], &re = G[e.dst][e.rev];
	    if (re.cap > 0 && len[v] > len[e.dst]) {
		Flow f = dfs(e.dst, s, min(c-ret, re.cap));
		ret += f;
		e.cap += f; re.cap -= f;
		if (ret == c) break;
	    }
	}
	return ret;
    }
    
    VI que;
    void bfs(int s) {
	len.assign(G.size(), -1);
	que.clear();
	que.push_back(s);
	len[s] = 0;
	for (int a=0; a<(int)que.size(); a++) {
	    int v = que[a];
	    for (int i=0; i<(int)G[v].size(); i++) {
		const Edge &e = G[v][i];
		if (e.cap > 0 && len[e.dst] == -1) {
		    len[e.dst] = len[v] + 1;
		    que.push_back(e.dst);
		}
	    }
	}
    }
    Flow _flow;
    Flow solve(int source, int sink, Flow limit=-1) {
	if (limit == -1) limit = INF;
	Flow ret = 0;
	while (true) {
	    bfs(source);
	    if (len[sink] == -1 || limit == 0) return _flow = ret;
	    iter.assign(G.size(), 0);
	    Flow tmp = dfs(sink, source, limit);
	    ret += tmp;
	    limit -= tmp;
	}
    }
};
const Dinic::Flow Dinic::INF;

int N;
int X[1011];
int Y[1011];
int W[1011];

map<pair<int, int>, int> mp;
int get(int x, int y) {
    auto it = mp.find(make_pair(x, y));
    if (it == mp.end()) return -1;
    return it->second;
}


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d%d%d", X+i, Y+i, W+i);

    REP (i, N) mp[make_pair(X[i], Y[i])] = i;
    
    int SRC = N * 2;
    int SNK = SRC + 1;

    Dinic D(SNK+1);

    const LL INF = 1LL<<50;

    LL sum = 0;
    REP (i, N) {
	sum += W[i];

	D.add_edge(i*2, i*2+1, W[i]);

	if ((X[i] + Y[i]) % 2 != 0) {
	    int a = get(X[i]+1, Y[i]);
	    if (a != -1) D.add_edge(i*2+1, a*2, INF);
	    int b = get(X[i]-1, Y[i]);
	    if (b != -1) D.add_edge(i*2+1, b*2, INF);
	} 

	if (X[i] % 2 == 0 && Y[i] % 2 == 0) {
	    int a = get(X[i], Y[i]+1);
	    if (a != -1) D.add_edge(i*2+1, a*2, INF);
	    int b = get(X[i], Y[i]-1);
	    if (b != -1) D.add_edge(i*2+1, b*2, INF);
	}

	if (X[i] % 2 != 0 && Y[i] % 2 == 0) {
	    D.add_edge(SRC, i*2, INF);
	}
	if (X[i] % 2 != 0 && Y[i] % 2 != 0) {
	    D.add_edge(i*2+1, SNK, INF);
	}
    }

    LL ans = sum - D.solve(SRC, SNK);
    printf("%lld\n", ans);

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}