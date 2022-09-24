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

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
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
//	eprintf("%d -> %d : %d\n", u+1, v+1, c);
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

const char *fair = "fair";
const char *unfair = "unfair";

int N, B, Q;
int H[10011];

int main() {
    scanf("%d%d%d", &N, &B, &Q);

    memset(H, -1, sizeof H);
    H[B] = N;
    
    REP (i, Q) {
	int a, g;
	scanf("%d%d", &a, &g);
	if (H[a] != -1 && H[a] != g) {
	    puts(unfair);
	    return 0;
	}
	
	H[a] = g;
    }
    

    int SRC = B + 5, SNK = SRC + 1;
    Dinic X(SNK+1);

    int last = 0;
    REP (i, B) {
	int g = i+1;
	if (H[g] != -1) {
	    if (last > H[g]) {
		puts(unfair);
		return 0;
	    }
	    X.add_edge(SRC, i, H[g] - last);
	    last = H[g];
	} else {
	    X.add_edge(i+1, i, X.INF);
	}


	X.add_edge(i, g % 5 + B, 1);
    }

    REP (i, 5) X.add_edge(i + B, SNK, N/5);

    X.flow(SRC, SNK);
    if (X._flow  == N) puts(fair);
    else puts(unfair);

    return 0;
}