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

int N, M;
VI G[200011];
bool use[200011];
int X[200011];

void dfs(int s, int b, int mask) {
    memset(use, 0, sizeof (bool) * N);
    VI stk;
    stk.push_back(s);
    X[s] |= mask;
    while (!stk.empty()) {
	int v = stk.back(); stk.pop_back();
	EACH (e, G[v]) if (*e != b) if (~X[*e] & mask) {
	    X[*e] |= mask;
	    stk.push_back(*e);
	}
    }
}

int A, B;
void MAIN() {
    scanf("%d%d%d%d", &N, &M, &A, &B);
    A--; B--;
    REP (i, N) G[i].clear();
    memset(X, 0, sizeof (int) * N);

    REP (i, M) {
	int u, v;
	scanf("%d%d", &u, &v);
	u--; v--;
	G[u].push_back(v);
	G[v].push_back(u);

    }

    dfs(A, B, 1);
    dfs(B, A, 2);
    X[A] |= 3;
    X[B] |= 3;

    LL cnt1 = 0, cnt2 = 0;
    REP (i, N) {
	if (X[i] == 1) cnt1++;
	if (X[i] == 2) cnt2++;
    }

    printf("%lld\n", cnt1 * cnt2);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}