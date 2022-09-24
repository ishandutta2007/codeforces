#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}
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
    Flow flow(int source, int sink, Flow limit=-1) {
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

int N, M;
char F[211][211];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    int SRC = N * M;
    int SNK = SRC + 1;
    Dinic D(SNK + 1);

    REP (i, N) REP (j, M) if (F[i][j] == '#') {
	int my = i * M + j;
	if (i == 0 || F[i-1][j] == '.') {
	    D.add_edge(SRC, my, 1);
	} else {
	    int p = (i-1) * M + j;
	    D.add_edge(p, my, 1);
	}
	
	if (j == 0 || F[i][j-1] == '.') {
	    D.add_edge(my, SNK, 1);
	} else {
	    int p = i * M + j - 1;
	    D.add_edge(my, p, 1);
	}
    }

    int f = D.flow(SRC, SNK);
    printf("%d\n", f);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}