#include<stack>
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

template<class T> vector<int> compress(const vector<T> &v, vector<T> *unq=NULL) {
    int n = v.size();
    vector<pair<T, int> > t(n);
    for (int i=0; i<n; i++) t[i] = make_pair(v[i], i);
    sort(t.begin(), t.end());
    vector<int> r(n);
    int cur = 0;
    for (int i=0, k=0; i<n; i++) {
	if (t[k].first < t[i].first) k = i, cur++;
	r[t[i].second] = cur;
    }
    if (unq) {
	unq->resize(cur+1);
	cur = 0;
	for (int i=0; i<n; i++)
	    if (i == 0 || t[i-1].first < t[i].first)
		(*unq)[cur++] = t[i].first;
    }
    return r;
}

struct Edge {
    int src, dst;
    int rev;
    bool use;
    Edge(int s, int d): src(s), dst(d) {}
    Edge(int s, int d, int r, bool u): src(s), dst(d), rev(r), use(u) {};
};
typedef vector<vector<Edge> > Graph;
Graph G;
void add_edge(int x, int y) {
    if (x == y) {
	int sz = G[x].size();
	G[x].push_back(Edge(x, x, sz+1, false));
	G[x].push_back(Edge(x, x, sz, false));
    } else {
	G[x].push_back(Edge(x, y, G[y].size(), false));
	G[y].push_back(Edge(y, x, G[x].size()-1, false));
    }
}
vector<Edge> eularianPath(Graph &G) { // [(x->y), ..., (z->w)]
    int N = G.size(), cnt = 0, odd = 0, x = 0;
    for (int i=0; i<N; i++) {
	cnt += G[i].size();
	if (1&G[i].size()) odd++, x=i;
	if (odd>2) return vector<Edge>(); // odd degree vertices
    }
    vector<int> iter(N); vector<Edge> ret;
    stack<Edge> S;
    S.push(Edge(-1, x));
    while (!S.empty()) {
	Edge e = S.top();
	if (iter[e.dst] < (int)G[e.dst].size()) {
	    Edge &f = G[e.dst][iter[e.dst]++];
	    if (!f.use) {
		f.use = G[f.dst][f.rev].use = true;
		S.push(f);
	    }
	} else {
	    S.pop();
	    ret.push_back(e);
	}
    }
    if ((int)ret.size() != (cnt>>1)+1) return vector<Edge>(); // not connected
    ret.pop_back(); reverse(ret.begin(), ret.end());
    return ret;
}

int N;
VI buf;
int B[100011], C[100011];

bool check(VI ans) {
    assert((int)ans.size() == N);
    vector<pair<int, int> > O(N-1), A(N-1);
    REP (i, N-1) {
	O[i] = make_pair(buf[i], buf[i+N-1]);
	A[i] = make_pair(min(ans[i], ans[i+1]), max(ans[i], ans[i+1]));
    }
    sort(O.begin(), O.end());
    sort(A.begin(), A.end());
    return A == O;
}

void MAIN() {
    scanf("%d", &N);
    buf.reserve(N+N);
    REP (i, N + N - 2) {
	int x;
	scanf("%d", &x);
	buf.push_back(x);
    }
    VI unq;
    VI ex = compress(buf, &unq);
    REP (i, N-1) {
	B[i] = ex[i];
	C[i] = ex[i+N-1];
	if (B[i] > C[i]) {
	    puts("-1");
	    return;
	}
    }

//    rprintf("%d", B, B+N-1);
//    rprintf("%d", C, C+N-1);

    int ma = *max_element(ex.begin(), ex.end());
    G.resize(ma+1);

    REP (i, N-1) {
	add_edge(B[i], C[i]);
    }

    auto path = eularianPath(G);
    if (path.empty()) {
	puts("-1");
    } else {
	VI ans;
	EACH (e, path) ans.push_back(unq[e->src]);
	ans.push_back(unq[path.back().dst]);
	if (check(ans)) {
	    rprintf("%d", ans.begin(), ans.end());
	} else {
	    puts("-1");
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}