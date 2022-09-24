#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

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
    typedef int Flow;
    static const Flow INF = 1<<29;
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
int A[3001];
int B[3001];
int last[111];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);

    memset(last, -1, sizeof last);

    const int SRC = N;
    const int SNK = SRC + 1;
    Dinic G(SNK+1);
    LL ans = 0;
    REP (i, N) {
	for (int j=1; j<=A[i]; j++) if (A[i] % j == 0 && last[j] != -1) {
	    G.add_edge(i, last[j], Dinic::INF);
	}

	if (0 < B[i]) {
	    ans += B[i];
	    G.add_edge(SRC, i, B[i]);
	} else if (B[i] < 0) {
	    G.add_edge(i, SNK, -B[i]);
	}

	last[A[i]] = i;
    }

    G.solve(SRC, SNK);
    ans -= G._flow;
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}