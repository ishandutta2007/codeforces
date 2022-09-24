#include<queue>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

#define NDEBUG
#include<cassert>

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

const int MAX = 100000;
int min_factor[MAX+1];
vector<int>prime;
void make_prime() {
    for (int i=2; i*i<=MAX; i++) {
	if (!min_factor[i]) {
	    min_factor[i] = i;
	    for (int j=i*i; j<=MAX; j+=i)
		if (!min_factor[j]) min_factor[j] = i;
	}
    }
    for (int i=2; i<=MAX; i++) {
	if (min_factor[i]==0) min_factor[i] = i;
	if (min_factor[i]==i) prime.push_back(i);
    }
}
bool is_prime(LL n) {
    if (n<=MAX) return min_factor[n] == n;
    for (int i=0; (LL)prime[i]*prime[i]<=n; i++)
	if (n%prime[i]==0) return false;
    return true;
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
    void bfs(int s) {
	len.assign(G.size(), -1);
	queue<int>qu;
	qu.push(s);
	len[s] = 0;
	for (;!qu.empty();) {
	    int v = qu.front(); qu.pop();
	    for (int i=0; i<(int)G[v].size(); i++) {
		const Edge &e = G[v][i];
		if (e.cap > 0 && len[e.dst] == -1) {
		    len[e.dst] = len[v] + 1;
		    qu.push(e.dst);
		}
	    }
	}
    }
    Flow _flow;
    Flow flow(int source, int sink) {
	Flow ret = 0;
	while (true) {
	    bfs(source);
	    if (len[sink] == -1) return _flow = ret;
	    iter.assign(G.size(), 0);
	    ret += dfs(sink, source, INF);
	}
    }
};
const Dinic::Flow Dinic::INF;

int N;
const string imp("Impossible");
typedef vector<VI> Adj;

int F[222];
VI O, E, Oi, Ei;
int main() {
    make_prime();
    
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d", F+i);
	if (F[i]&1) {
	    O.push_back(F[i]);
	    Oi.push_back(i);
	} else {
	    E.push_back(F[i]);
	    Ei.push_back(i);
	}
    }

    if (O.size() != E.size()) {
	printf("%s\n", imp.c_str());
	return 0;
    }

    int M = N/2;
    int O_BASE = 0, E_BASE = M, source = N, sink = source + 1;
    Dinic D(sink+1);

    REP (i, M) REP (j, M) {
	if (is_prime(O[i] + E[j]))
	    D.add_edge(O_BASE + i, E_BASE + j, 1);
    }
    REP (i, M) {
	D.add_edge(source, O_BASE + i, 2);
	D.add_edge(E_BASE + i, sink, 2);
    }

    D.flow(source, sink);

    if (D._flow != N) {
	printf("%s\n", imp.c_str());
	return 0;
    } else {
	Adj A(N);
	REP (i, M) {
	    EACH (e, D.G[i]) {
		if (e->cap == 0 && e->dst < source) {
		    int v = Oi[i], w = Ei[e->dst-M];
		    A[v].push_back(w);
		    A[w].push_back(v);
		}
	    }
	}

	REP (i, N) assert(A[i].size() == 2u);

	Adj cycles;
	vector<char> use(N, 0);
	REP (i, N) {
	    if (use[i]) continue;
	    VI C;
	    for (int v=i, p=-1;; ) {
		C.push_back(v);
		use[v] = true;
		int w = (A[v][0] == p ? A[v][1] : A[v][0]);

		if (use[w]) break;
		p = v; v = w;
	    }
	    cycles.push_back(C);
	}
	printf("%d\n", (int)cycles.size());
	EACH (e, cycles) {
	    VI v = *e;
	    printf("%d", (int)v.size());
	    EACH (x, v) printf(" %d", *x + 1);
	    putchar('\n');
	}
    }
    
    assert(false);
    return 0;
}