#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int count_node(int x) { return -u[root(x)]; }
    int count_tree() { return cc; }
};

const int MAXN = 200011;
const int MAXE = 300011;

int N, M, Q;
// Node;
int P[MAXN];
int rev[MAXN];
VI G[MAXN];

// Edges
int A[MAXE];
int B[MAXE];
int life[MAXE];
bool active[MAXE];


// Queries;
char op[500011];
int   X[500011];

// Trees;
int cnt;
int name[MAXN];
//set<int> S[200011];
priority_queue<int> PQ[MAXN];

struct Data {
    int v, p, i;
    Data(){}
    Data(int v_, int p_, int i_): v(v_), p(p_), i(i_) {}
};

bool step(vector<Data> &que, int &idx, int cut) {
    while (1) {
	if (idx >= (int)que.size()) return false;

	int v = que[idx].v;
	if ((int)G[v].size() <= que[idx].i) {
	    idx++;
	    continue;
	}

	int w = G[v][que[idx].i];
	if (w == cut || name[v] != name[w]) {
	    G[v][que[idx].i] = G[v].back();
	    G[v].pop_back();
	    continue;
	}
	if (w == que[idx].p) {
	    que[idx].i++;
	    continue;
	}

	que[idx].i++;
	que.emplace_back(w, v, 0);
	return true;
    }
    assert(false);
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &Q);
    memset(rev, -1, sizeof rev);
    REP (i, N) {
	scanf("%d", P+i);
	rev[P[i]] = i;
    }

    REP (i, M) {
	scanf("%d%d", A+i, B+i);
	A[i]--;
	B[i]--;
	life[i] = Q;
    }

    REP (i, Q) {
	scanf("%s%d", op+i, X+i);
	X[i]--;
	if (op[i] == '2') {
	    life[X[i]] = i;
	}
    }

    VI E;
    UnionFind U(N);

    {
	vector<pair<int, int> > LI;
	REP (i, M) {
	    LI.emplace_back(life[i], i);
	}
	sort(LI.begin(), LI.end());
	for (int i=M; i--;) {
	    int a = A[LI[i].second];
	    int b = B[LI[i].second];
	    if (!U.same(a, b)) {
		active[LI[i].second] = true;
		E.push_back(LI[i].second);
		U.link(a, b);
		G[a].push_back(b);
		G[b].push_back(a);
	    }
	}
    }


    cnt = 0;
    REP (i, N) if (U.root(i) == i) {
	name[i] = cnt++;
    }
    REP (i, N) {
	int s = U.root(i);
	name[i] = name[s];
	//S[name[s]].insert(P[i]);
	PQ[name[s]].push(P[i]);
    }

    vector<Data> queA;
    vector<Data> queB;
    int idxA, idxB;

    REP (i, Q) {
	if (op[i] == '1') {
	    int v = X[i];
	    int ans = 0;
	    int sz = PQ[name[v]].size();

	    while (!PQ[name[v]].empty()) {
		int guess = PQ[name[v]].top();
		PQ[name[v]].pop();
		if (rev[guess] == -1) continue;
		if (name[v] != name[rev[guess]]) continue;

		ans = guess;
		P[rev[guess]] = 0;
		rev[guess] = -1;
		break;
	    }

	    if (sz && PQ[name[v]].empty()) {
		PQ[name[v]] = priority_queue<int>();
	    }

//	    if (S[name[v]].empty()) {
//		ans = 0;
//	    } else {
//		ans = *S[name[v]].rbegin();
//		S[name[v]].erase(ans);
//		int w = rev[ans];
//		P[w] = 0;
//		rev[ans] = -1;
//	    }

	    printf("%d\n", ans);
	} else if (active[X[i]]) {
	    active[X[i]] = false;
	    int a = A[X[i]];
	    int b = B[X[i]];
	    // int s = name[a];

	    queA.clear();
	    queA.emplace_back(a, -1, 0);
	    queB.clear();
	    queB.emplace_back(b, -1, 0);
	    idxA = 0;
	    idxB = 0;

	    while (1) {
		bool sa = step(queA, idxA, b);
		bool sb = step(queB, idxB, a);

		if (!sa || !sb) break;
	    }

	    if (queB.size() < queA.size()) {
		swap(a, b);
		swap(queA, queB);
		swap(idxA, idxB);
	    }

	    EACH (e, queA) {
		int v = e->v;

		if (P[v]) {
		    PQ[cnt].push(P[v]);
		}
//		auto it = S[s].find(P[v]);
//		if (it != S[s].end()) {
//		    S[cnt].insert(P[v]);
//		    S[s].erase(it);
//		}
		name[v] = cnt;
	    }

	    cnt++;
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}