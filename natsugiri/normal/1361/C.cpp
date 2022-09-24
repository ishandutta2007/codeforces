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

// Undirected Graph; Bidirected Adjacency List
struct Edge {
    int src, dst;
    int rev;
    bool use;
    int info;
    Edge(int s, int d): src(s), dst(d) {}
    //Edge(int s, int d, int r, bool u): src(s), dst(d), rev(r), use(u) {};
    Edge(int s, int d, int r, bool u, int info_): src(s), dst(d), rev(r), use(u), info(info_) {};
};

vector<Edge> G[1<<20];

vector<Edge> eularianCycle(int N) { // [(x->y), (y->w), ..., (z->x)]
    int cnt = 0;
    for (int i=0; i<N; i++) {
	cnt += G[i].size();
	if (G[i].size()%2) return vector<Edge>(); // odd degree vertex
    }
    vector<int> iter(N);
    vector<Edge> S;
    vector<Edge> ret;
    for (int i=0; i<N; i++) if (G[i].size()) {
	S.push_back(Edge(-1, i));
	break;
    }
    while (!S.empty()) {
	Edge e = S.back();
	if (iter[e.dst] < (int)G[e.dst].size()) {
	    Edge &f = G[e.dst][iter[e.dst]++];
	    if (!f.use) {
		f.use = G[f.dst][f.rev].use = true;
		S.push_back(f);
	    }
	} else {
	    S.pop_back();
	    ret.push_back(e);
	}
    }
    if ((int)ret.size() != (cnt>>1)+1) return vector<Edge>(); // not connected
    ret.pop_back(); reverse(ret.begin(), ret.end());
    return ret;
}


int N;
int A[500011];
int B[500011];

void MAIN() {
    scanf("%d", &N);

    REP (i, N) {
	scanf("%d%d", A+i, B+i);
    }

    int ans = 0;
    VI seq;
    for (int level=20; level>0; level--) {
	REP (i, 1<<level) G[i].clear();
	int mask = (1<<level) - 1;
	REP (i, N) {
	    int x = A[i] & mask;
	    int y = B[i] & mask;

	    if (x == y) {
		int sz = G[x].size();
		G[x].emplace_back(x, x, sz+1, false, i);
		G[x].emplace_back(x, x, sz, false, i-N);
	    } else {
		int sz = G[x].size();
		G[x].emplace_back(x, y, G[y].size(), false, i);
		G[y].emplace_back(y, x, sz, false, i-N);
	    }
	}

	auto cycle = eularianCycle(1<<level);
	if (cycle.size()) {
	    ans = level;
	    REP (i, cycle.size()) {
		int idx = cycle[i].info;
		if (idx < 0) {
		    idx += N;
		    seq.push_back(idx*2+2);
		    seq.push_back(idx*2+1);
		} else {
		    seq.push_back(idx*2+1);
		    seq.push_back(idx*2+2);
		}
	    }

	    break;
	}
    }

    if (seq.empty()) {
	ans = 0;
	REP (i, N*2) seq.push_back(i+1);
    }

    printf("%d\n", ans);
    rprintf("%d", seq.begin(), seq.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}