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

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &a, T b) { if (a>b) a=b; }
template<class T> inline void amax(T &a, T b) { if (a<b) a=b; }
typedef pair<int, int> Cost;
Cost operator+(const Cost&x, const Cost&y) {
    return Cost(x.first + y.first, x.second + y.second);
}
struct Edge {
    int src, dst;
    Cost cst;
    Edge(){}
    Edge(int s, int d, int z) {
	src = s;
	dst = d;
	cst.first = 1;
	cst.second = 1-z;
    }
};
bool operator<(const Edge&x, const Edge&y) {
    return x.cst > y.cst;
}

typedef vector<Edge> Edges;
typedef vector<Edges> Graph;

// O(E log V)
struct Dijkstra {
    vector<Cost>len;
    vector<int>prev;
    int s;
    Dijkstra(const Graph&G, int s): s(s) {
        int N = G.size();
        len = vector<Cost>(N, make_pair(1<<29, 1));
        prev = vector<int>(N, -1);
        len[s] = make_pair(0, 0);
        priority_queue<Edge> Q;
	Edge x(-1, 0, 0);
	x.cst = make_pair(0, 0);
        Q.push(x);
        
        for (; !Q.empty();) {
            Edge e = Q.top(); Q.pop();
            if (e.cst > len[e.dst]) continue;
            for (int i=0; i<(int)G[e.dst].size(); i++) {
                Edge f = G[e.dst][i];
                if (len[f.dst] > f.cst + e.cst) {
                    len[f.dst] = f.cst = f.cst + e.cst;
                    prev[f.dst] = e.dst;
                    Q.push(f);
                }
            }
        }
    }
    vector<int> path(int t) { // from t to s
        vector<int>ret;
        if (prev[t] < 0) return ret;
        for (; t >= 0; t=prev[t])
            ret.push_back(t);
        return ret;
    }
};

int N, M;
int A[100011], B[100011];
int Z[100011];

int main() {
    scanf("%d%d", &N, &M);
    Graph G(N);
    REP (i, M) {
	int a, b, z;
	scanf("%d%d%d", &a, &b, &z);
	a--;
	b--;
	G[a].push_back(Edge(a, b, z));
	G[b].push_back(Edge(b, a, z));
	A[i] = a;
	B[i] = b;
	Z[i] = z;
    }

    Dijkstra X(G, 0);

    // REP (i, N) {
    // 	printf("%d %d %d\n", i, X.len[i].first, X.len[i].second);
    // }
    VI v = X.path(N-1);
    set<pair<int, int> > E;
    REP (i, v.size()-1) {
	int a = v[i], b = v[i+1];
	if (b < a) swap(a, b);
	E.insert(make_pair(a, b));
    }

    VI Ax, Bx, Zx;

    REP (i, M) {
	int a = A[i], b = B[i];
	if (b < a) swap(a, b);
	if ((int)E.count(make_pair(a, b)) != Z[i]) {
	    Ax.push_back(A[i]+1);
	    Bx.push_back(B[i]+1);
	    Zx.push_back(1-Z[i]);
	}
    }

    printf("%d\n", (int)Ax.size());
    REP (i, Ax.size()) printf("%d %d %d\n", Ax[i], Bx[i], Zx[i]);
    
    return 0;
}