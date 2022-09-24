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

int N;
int M;
int nxt[500011];

VI G[1<<20];
int deg[1<<20];

void init() {
    REP (i, M*2) {
	G[i].clear();
	deg[i] = 0;
    }
    for (int i=M; --i;) {
	deg[i] += 2;
    }
}

int stk[1<<20];
int sz;
void add(int x, int y, int tar) {
    sz = 0;
    stk[sz++] = 0;
    stk[sz++] = M;
    stk[sz++] = 1;
    while (sz) {
	int k = stk[--sz];
	int r = stk[--sz];
	int l = stk[--sz];
	if (y <= l || r <= x) {
	} else if (x <= l && r <= y) {
	    G[k].push_back(tar);
	    deg[tar]++;
	} else {
	    stk[sz++] = l;
	    stk[sz++] = (l+r)/2;
	    stk[sz++] = k*2;

	    stk[sz++] = (l+r)/2;
	    stk[sz++] = r;
	    stk[sz++] = k*2+1;
	}
    }
}

int ans[1<<20];
void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", nxt+i), nxt[i]--;

    M = 1;
    while (M < N) M *= 2;
    init();

    REP (i, N) {
	if (nxt[i] == -2) continue;
	if (nxt[i] < N) {
	    G[M + i].push_back(M + nxt[i]);
	    deg[M+nxt[i]]++;
	}
	if (i+1 < nxt[i]) {
	    add(i+1, nxt[i], M + i);
	}
    }

    sz = 0;
    REP (i, M*2) if (deg[i] == 0) stk[sz++] = i;
    int cnt = 0;
    while (sz) {
	int v = stk[--sz];
	if (M <= v && v < M+N) {
	    ans[v-M] = ++cnt;
	}

	if (v > 1) {
	    deg[v/2]--;
	    if (deg[v/2] == 0) stk[sz++] = v/2;
	}
	EACH (e, G[v]) {
	    deg[*e]--;
	    if (deg[*e] == 0) {
		stk[sz++] = *e;
	    }
	}
    }

    if (*max_element(deg, deg+M*2) == 0) {
	rprintf("%d", ans, ans+N);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}