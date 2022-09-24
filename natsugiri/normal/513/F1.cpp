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

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }

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

int R, C, M, W, K;
char F[32][32];
int X[1111], Y[1111];
LL Z[1111];
int INF;
int FW[511][511];
inline int encode(int r, int c) {
    return r*C+c;
}
void buildFW() {
    memset(FW, 0x3f, sizeof FW);
    memset(&INF, 0x3f, sizeof INF);
    REP (i, R) REP (j, C) {
	if (F[i][j] == '.') {
	    if (i && F[i-1][j] == '.') {
		int x = encode(i, j), y = encode(i-1, j);
		FW[x][y] = FW[y][x] = 1;
	    }
	    if (j && F[i][j-1] == '.') {
		int x = encode(i, j), y = encode(i, j-1);
		FW[x][y] = FW[y][x] = 1;
	    }
	}
    }
    REP (i, K) FW[i][i] = 0;
    REP (k, K) REP (i, K) REP (j, K) amin(FW[i][j], FW[i][k]+FW[k][j]);
}

bool check(LL bound) {
    int M_BASE = 0, W_BASE = M + M_BASE, I_BASE = W + W_BASE, O_BASE = I_BASE + K, source = O_BASE + K, sink = source + 1;
    Dinic D(sink+1);

    REP (r, R) REP (c, C) if (F[r][c] == '.') {
	int y = encode(r, c);
	D.add_edge(I_BASE + y, O_BASE + y, 1);
	REP (i, M) {
	    int x = encode(X[i], Y[i]);
	    if (FW[x][y] < INF && Z[i] * FW[x][y] <= bound) {
		D.add_edge(M_BASE + i, I_BASE + y, 1);
	    }
	    x = encode(X[i+M], Y[i+M]);
	    if (FW[x][y] < INF && Z[i+M] * FW[x][y] <= bound) {
		D.add_edge(O_BASE + y, W_BASE + i, 1);
	    }
	}
    }
    REP (i, M) {
	D.add_edge(source, M_BASE + i, 1);
	D.add_edge(W_BASE + i, sink, 1);
    }
    return (D.flow(source, sink) >= M);
}


int main() {
    scanf("%d%d%d%d", &R, &C, &M, &W);
    K = R*C;
    if (M+1!=W && W+1!=M) {
	puts("-1");
	return 0;
    }
    REP (i, R) scanf("%s", F[i]);
    if (M+1==W) {
	REP (i, M+1) scanf("%d%d%lld", X+i, Y+i, Z+i);
	REP (i, W) scanf("%d%d%lld", X+i+M+1, Y+i+M+1, Z+i+M+1);
	M++;
    } else {
	scanf("%d%d%lld", X+M+W, Y+M+W, Z+M+W);
	REP (i, M) scanf("%d%d%lld", X+i, Y+i, Z+i);
	REP (i, W) scanf("%d%d%lld", X+i+M, Y+i+M, Z+i+M);
	W++;
    }
    REP (i, 2*M) { X[i]--; Y[i]--; }
    buildFW();

    LL lo = -1, hi = 1e12;
    while (hi - lo > 1) {
	LL m = (hi + lo) / 2;
	if (check(m)) hi = m;
	else lo = m;
    }

    if (hi == 1e12) hi = -1;
    printf("%lld\n", hi);
    return 0;
}