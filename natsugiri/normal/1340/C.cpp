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
template<class T> struct PriorityQueue {
    using ULL = unsigned long long;
    static const int SIZE = 65;
    unsigned sz;
    ULL last;
    vector<pair<ULL, T> > b[SIZE];

    static ULL bsr(ULL x) {
	return x? 64u - __builtin_clzll(x): 0u;
    }

    PriorityQueue() {
	sz = last = 0;
    }

    bool empty() const { return sz == 0; }

    unsigned size() const { return sz; }

    void push(ULL x, const T &v) {
	assert(last <= x);
	sz++;
	b[bsr(x^last)].emplace_back(x, v);
    }

    pair<ULL, T>& get_min() {
	assert(sz);
	if (b[0].empty()) {
	    int k = 1;
	    while (b[k].empty()) k++;
	    last = b[k][0].first;
	    EACH (e, b[k]) amin(last, e->first);
	    REP (i, b[k].size()) b[bsr(b[k][i].first^last)].push_back(b[k][i]);
	    b[k].clear();
	}
	return b[0].back();
    }

    void pop_min() {
	if (b[0].empty()) get_min();
	b[0].pop_back();
	sz--;
    }
};

int N;
int M;
int D[10011];
LL dist[10011][1011];
int G, R;

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d", D+i);
    sort(D, D+M);
    scanf("%d%d", &G, &R);

    memset(dist, 0x3f, sizeof dist);
    const LL INF = dist[0][0];
    dist[0][G] = 0;
    PriorityQueue<pair<int, int> > Q;
    Q.push(0, make_pair(0, G));

    while (Q.size()) {
	auto p = Q.get_min();
	Q.pop_min();
	LL cst = p.first;
	int pos = p.second.first;
	int rest = p.second.second;

	if (dist[pos][rest] != cst) continue;
	if (pos == M-1) break;

	if (rest == 0) {
	    rest = G;
	    cst += R;
	}

	if (pos + 1 < M) {
	    LL diff = D[pos+1] - D[pos];
	    if (diff <= rest && dist[pos+1][rest-diff] > cst + diff) {
		dist[pos+1][rest-diff] = cst + diff;
		Q.push(cst+diff, make_pair(pos+1, rest-diff));
	    }
	}
	if (pos) {
	    LL diff = D[pos] - D[pos-1];
	    if (diff <= rest && dist[pos-1][rest-diff] > cst + diff) {
		dist[pos-1][rest-diff] = cst + diff;
		Q.push(cst+diff, make_pair(pos-1, rest-diff));
	    }
	}
    }

    LL ans = INF;
    REP (g, G+1) amin(ans, dist[M-1][g]);
    if (ans == INF) puts("-1");
    else printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}