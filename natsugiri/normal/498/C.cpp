#include<set>
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

#define REP(i,n) for(int i=0,i##_len=(n); i<i##_len; i++)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin();i!=(c).end();i++)

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


int f_count(int n, int p) {
    int cnt = 0;
    while (n % p == 0) {
	cnt++;
	n /= p;
    }
    return cnt;
}

int N, M, A[111];
int I[111], J[111];
int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);

    REP (i, M) {
	scanf("%d%d", I+i, J+i);
	I[i]--;
	J[i]--;
	if (I[i] % 2) swap(I[i], J[i]);
    }
    
    set<int> se;
    REP (i, N) {
	int x = A[i];
	for (int j=2; j*j<=x; j++) {
	    if (x % j == 0) {
		se.insert(j);
		while (x % j == 0) x /= j;
	    }
	}
	if (x > 1) se.insert(x);
    }


    int ans = 0;
    
    const int source = N, sink = source + 1;
    EACH (it, se) {
	Dinic X(sink+1);
	REP (k, M)
	    X.add_edge(I[k], J[k], X.INF);
	for (int i=0; i<N; i+=2) 
	    X.add_edge(source, i, f_count(A[i], *it));
	for (int i=1; i<N; i+=2)
	    X.add_edge(i, sink, f_count(A[i], *it));
	ans += X.flow(source, sink);
    }

    printf("%d\n", ans);
    return 0;
}