#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

struct UnionFindTimestamp {
    typedef pair<int, int> Pair;
    int n;
    vector<vector<Pair> >U;
    int count_link;
    UnionFindTimestamp(int n_ = 0) : n(n_), U(n+2), count_link(0) {
	REP (i, n) U[i].emplace_back(0, -1);
	U[n].emplace_back(0, n);
    }

    int root(int x, int t) const {
	while (1) {
	    if (t < U[x].back().first || U[x].back().second < 0) return x;
	    x = U[x].back().second;
	}
    }

    bool link(int x, int y) {
	x = root(x, count_link);
	y = root(y, count_link);
	count_link++;
	if (x == y) return false;
	if (U[x].back().second < U[y].back().second) swap(x, y);
	U[y].emplace_back(count_link, U[x].back().second + U[y].back().second); // (time, -size);
	U[x].emplace_back(count_link, y); // (time, parent = y);
	U[n].emplace_back(count_link, U[n].back().second-1); // (time, connected components);
	U[n+1].emplace_back(y, x); // (y, x);
	return true;
    }

    bool same(int x, int y, int t) const {
	return x == y || root(x, t) == root(y, t);
    }

    int count(int t) const { // # connected components;
	int k = upper_bound(U[n].begin(), U[n].end(), Pair(t, n)) - U[n].begin() - 1;
	return U[n][k].second;
    }

    int size(int x, int t) const {
	while (1) {
	    if (t < U[x].back().first || U[x].back().second < 0) {
		int k = upper_bound(U[x].begin(), U[x].end(), Pair(t, n)) - U[x].begin() - 1;
		return -U[x][k].second;
	    }
	    x = U[x].back().second;
	}
    }

    bool rollback() {
	if (count_link == 0) return false;
	count_link--;
	if (U[n+1].empty()) return false;
	Pair p = U[n+1].back();
	if (count_link >= U[p.first].back().first) return false;
	U[p.first].pop_back(); U[p.second].pop_back(); U[n].pop_back(); U[n+1].pop_back();
	return true;
    }
};

int N, M, K;
int C[500011];

struct Data {
    int cx, cy, x, y;
    Data(){}
    Data(int cx_, int cy_, int x_, int y_): cx(cx_), cy(cy_), x(x_), y(y_) {}

    bool operator<(const Data &o) const {
	return cx != o.cx? cx < o.cx:
	    cy < o.cy;
    }
};
vector<Data> E;

bool bad[500011];

void MAIN() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%d", C+i), C[i]--;
    UnionFindTimestamp U(N*2);

    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	if (C[x] == C[y]) {
	    U.link(x, y+N);
	    U.link(x+N, y);
	} else {
	    E.emplace_back(min(C[x], C[y]), max(C[x], C[y]), x, y);
	}
    }

    REP (i, N) if (U.same(i, i+N, 1<<29)) {
	bad[C[i]] = true;
    }

    LL good = 0;
    REP (i, K) if (!bad[i]) good++;
    LL ans = (LL)good * (good-1) / 2;

    sort(E.begin(), E.end());

    for (int i=0; i<(int)E.size(); ) {
	int j = i;
	while (j < (int)E.size() && E[i].cx == E[j].cx && E[i].cy == E[j].cy) {
	    j++;
	}

	if (!bad[E[i].cx] && !bad[E[i].cy]) {
	    bool ok = true;
	    int count_link = U.count_link;
	    for (int k=i; k<j; k++) {
		U.link(E[k].x, E[k].y + N);
		U.link(E[k].x + N, E[k].y);
		if (U.same(E[k].x, E[k].x + N, 1<<29)) {
		    ok = false;
		    break;
		}
	    }

	    if (!ok) ans--;

	    while (U.count_link != count_link) U.rollback();
	}

	i = j;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}