#include<queue>
#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }
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

int N, M, A, B;
int tbl[111][111];
int main() {
    scanf("%d%d", &N, &M);
    const int SRC = 2*N, SNK = SRC + 1;
    Dinic D(SNK+1);
    REP (i, N) {
        int a;
        scanf("%d", &a);
        D.add_edge(SRC, i, a);
        A += a;
    }
    REP (i, N) {
        int b;
        scanf("%d", &b);
        D.add_edge(i + N, SNK, b);
        B += b;
    }
    REP (i, M) {
        int x, y;
        scanf("%d%d", &x, &y);
        x--; y--;
        D.add_edge(x, y + N, D.INF);
        D.add_edge(y, x + N, D.INF);
    }
    REP (i, N) D.add_edge(i, i + N, D.INF);
    int F = D.flow(SRC, SNK);


    if (F == A && F == B) {
        puts("YES");
        const Dinic::Graph G = D.G;
        REP (i, N) {
            EACH (e, G[i]) {
                const int x = e->dst;
                if (N <= x && x < 2*N) tbl[i][x-N] = D.INF - e->cap;
            }
        }
        REP (i, N) REP (j, N) printf("%d%c", tbl[i][j], j+1==N? '\n': ' ');
    } else {
        puts("NO");
    }
    return 0;
}