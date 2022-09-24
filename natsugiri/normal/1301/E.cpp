#include<set>
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

int N, M, Q;
char F[511][511];

int H[511][511];

struct Data {
    int r1, c1;
    int r2, c2;
};
Data query[300011];

vector<pair<int, int> > E[511];
int ans[300011];

set<int> seg[1011];
void init() {
    REP (i, N*2) seg[i].clear();
}
void add(int y, int x) {
    y += N;
    for (; y; y>>=1) {
	seg[y].insert(x);
    }
}

bool test(set<int> &se, int small, int large) {
    auto it = se.lower_bound(small);
    return it != se.end() && *it < large;
}

bool has(int l, int r, int small, int large) {
    l += N;
    r += N;
    for (; l<r; l>>=1, r>>=1) {
	if (l&1) {
	    if (test(seg[l], small, large)) return true;
	    l++;
	}
	if (r&1) {
	    r--;
	    if (test(seg[r], small, large)) return true;
	}
    }
    return false;
}

void MAIN() {
    scanf("%d%d%d", &N, &M, &Q);
    REP (i, N) scanf("%s", F[i]);

    REP (i, N) REP (j, M) {
	if (i && j && F[i][j] == F[i][j-1] && F[i][j] == F[i-1][j] && F[i][j] == F[i-1][j-1]) {
	    H[i][j] = min(H[i][j-1], min(H[i-1][j], H[i-1][j-1])) + 1;
	} else {
	    H[i][j] = 1;
	}
    }

    REP (i, Q) {
	int r1, c1, r2, c2;
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	r1--; c1--;
	query[i] = (Data){r1, c1, r2, c2};
    }

    REP (i, N) REP (j, M) if (F[i][j] == 'B') {
	int x = j - H[i][j];
	int y = i - H[i][j];
	if (0 <= y && 0 <= x
		&& F[y][j] == 'G'
		&& F[i][x] == 'Y'
		&& F[y][x] == 'R'
		&& H[y][j] >= H[i][j]
		&& H[i][x] >= H[i][j]
		&& H[y][x] >= H[i][j]) {
	    E[H[i][j]].emplace_back(i, j);
	}
    }

    REP (s, 511) if (!E[s].empty()) {
	if (E[s].size() <= 10u) {
	    EACH (e, E[s]) {
		int i = e->first;
		int j = e->second;
		REP (p, Q) {
		    if (query[p].r1 + s*2 - 1 <= i
			    && i < query[p].r2
			    && query[p].c1 + s*2 - 1 <= j
			    && j < query[p].c2) {
			ans[p] = s*s*4;
		    }
		}
	    }
	} else {
	    init();
	    EACH (e, E[s]) {
		int i = e->first;
		int j = e->second;
		add(i, j);
	    }
	    REP (i, Q) {
		if (s*2 <= query[i].r2 - query[i].r1 && s*2 <= query[i].c2 - query[i].c1
			&& has(query[i].r1 + s*2 - 1,
			    query[i].r2,
			    query[i].c1 + s*2 - 1,
			    query[i].c2)) {
		    ans[i] = s*s*4;
		}
	    }
	}
    }

    REP (i, Q) printf("%d\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}