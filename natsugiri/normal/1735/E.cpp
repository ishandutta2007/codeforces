#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
template<class T> void sort_unique(vector<T> &v) {
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
}
struct Dinic {
    typedef LL Flow;
    static const Flow INF = 1LL<<60;
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
LL A[1000];
LL B[1000];
vector<LL> Xs;

LL P1, P2;
vector<LL> H;

bool solve(LL P2_) {
    P2 = P2_;
    const int A_BASE = Xs.size();
    const int B_BASE = A_BASE + N;
    const int SRC = B_BASE + N;
    const int SNK = SRC + 1;
    Dinic F(SNK + 1);

    REP (i, N) {
	int cnt = 0;
	LL left = P2 - B[i];
	int k = lower_bound(Xs.begin(), Xs.end(), left) - Xs.begin();
	if (k < (int)Xs.size() && Xs[k] == left) {
	    F.add_edge(k, i + B_BASE, 1);
	    cnt++;
	}

	LL right = P2 + B[i];
	k = lower_bound(Xs.begin(), Xs.end(), right) - Xs.begin();
	if (k < (int)Xs.size() && Xs[k] == right) {
	    F.add_edge(k, i + B_BASE, 1);
	    cnt++;
	}

	if (cnt == 0) return false;
    }

    REP (i, N) {
	F.add_edge(SRC, i + A_BASE, 1);

	int k = lower_bound(Xs.begin(), Xs.end(), (LL)-A[i]) - Xs.begin();
	F.add_edge(i + A_BASE, k, 1);

	k = lower_bound(Xs.begin(), Xs.end(), (LL)A[i]) - Xs.begin();
	F.add_edge(i + A_BASE, k, 1);

	F.add_edge(i + B_BASE, SNK, 1);
    }

    LL f = F.solve(SRC, SNK);
    if (f < N) {
	return false;
    }

    P1 = 0;
    REP (v, N) {
	EACH (e, F.G[v + A_BASE]) {
	    if (e->cap == 0 && e->dst < A_BASE) {
		H.push_back(Xs[e->dst]);
	    }
	}
    }

    LL mi = 0;
    amin(mi, P2);
    REP (i, N) amin(mi, H[i]);
    P1 -= mi;
    P2 -= mi;
    REP (i, N) H[i] -= mi;

    return true;
}


void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", A+i);
    REP (i, N) scanf("%lld", B+i);

    H.clear();

    Xs.clear();
    REP (i, N) {
	Xs.push_back(A[i]);
	Xs.push_back(-A[i]);
    }
    sort_unique(Xs);

    REP (i, N) {
	// A[0] == P2 + B[i];
	if (solve(A[0] - B[i])) {
	    break;
	}

	// A[0] == P2 - B[i];
	if (solve(A[0] + B[i])) {
	    break;
	}
    }

    if (H.size()) {
	puts("YES");
	rprintf("%lld", H.begin(), H.end());
	printf("%lld %lld\n", P1, P2);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}