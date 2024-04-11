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

int N, K;
int P[300011];
int X[300011], Y[300011];

int nxt[300011];
int prv[300011];

int U[300011];
int root(int i) {
    return U[i] == i? i: U[i] = root(U[i]);
}

VI B[300011];

bool test_path() {
    memset(prv, -1, sizeof (int)*N);
    memset(nxt, -1, sizeof (int)*N);
    REP (i, K) {
	nxt[X[i]] = Y[i];
	prv[Y[i]] = X[i];
    }

    REP (i, K) {
	if (nxt[X[i]] != Y[i]) return false;
	if (prv[Y[i]] != X[i]) return false;
    }

    REP (i, N) U[i] = i;
    REP (i, K) {
	int x = root(X[i]);
	int y = root(Y[i]);
	U[y] = U[x];
    }

    int cnt = 0;
    REP (i, N) {
	if (prv[i] == -1 && nxt[i] != -1) {
	    assert(root(i) == i);
	    int x = i;
	    while (x != -1) {
		cnt++;
		B[i].push_back(x);
		x = nxt[x];
	    }
	}
	if (prv[i] == -1 && nxt[i] == -1) {
	    assert(root(i) == i);
	    cnt++;
	    B[i].push_back(i);
	}
    }

    return cnt == N;
}

VI G[300011];

int deg[300011];
VI que;
VI ans;
bool test_dag() {
    int rt = -1;
    REP (i, N) G[i].clear();

//    REP (i, K) {
//	G[X[i]].push_back(Y[i]);
//    }

    REP (i, N) {
	if (P[i] == -1) {
	    rt = i;
	} else {
	    int p = root(P[i]);
	    int k = root(i);
	    if (p != k) {
		G[p].push_back(k);
	    }
	}
    }

    memset(deg, 0, sizeof (int) * N);

    REP (i, N) EACH (e, G[i]) deg[*e]++;

    if (deg[rt] != 0) return false;

    ans.clear();
    ans.insert(ans.end(), B[rt].begin(), B[rt].end());
    que.clear();
    que.push_back(rt);
    for (int i=0; i<(int)que.size(); i++) {
	int v = que[i];
	EACH (e, G[v]) {
	    deg[*e]--;
	    if (deg[*e] == 0) {
		que.push_back(*e);
		ans.insert(ans.end(), B[*e].begin(), B[*e].end());
	    }
	}
    }

    return (int)ans.size() == N;
}

bool test_ans() {
    REP (i, N) G[i].clear();

    int rt = -1;
    REP (i, N) {
	if (P[i] == -1) {
	    rt = i;
	} else {
	    G[P[i]].push_back(i);
	}
    }

    memset(deg, 0, sizeof (int) * N);

    REP (i, N) EACH (e, G[i]) deg[*e]++;

    REP (i, N) {
	int v = ans[i];
	if (deg[v] != 0) return false;

	EACH (e, G[v]) {
	    deg[*e]--;
	}
    }

    return true;
}

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", P+i), P[i]--;
    REP (i, K) {
	scanf("%d%d", X+i, Y+i);
	X[i]--;
	Y[i]--;
    }

    bool yes = true;
    if (yes) {
	yes = test_path();
    }
    if (yes) {
	yes = test_dag();
    }
    if (yes) {
	yes = test_ans();
    }

    if (yes) {
	EACH (e, ans) (*e)++;
	rprintf("%d", ans.begin(), ans.end());
    } else {
	puts("0");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}