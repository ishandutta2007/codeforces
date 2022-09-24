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
VI R[200011];
VI S[200011];
VI P;
int D[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	R[y].push_back(x);
    }

    int len;
    scanf("%d", &len);
    P.resize(len);
    REP (i, len) scanf("%d", &P[i]), P[i]--;

    VI que;
    que.push_back(P.back());
    memset(D, 0x3f, sizeof D);
    D[P.back()] = 0;
    for (int i=0; i<(int)que.size(); i++) {
	int v = que[i];
	EACH (e, R[v]) if (D[*e] > D[v] + 1) {
	    D[*e] = D[v] + 1;
	    que.push_back(*e);
	}
    }
    REP (i, N) EACH (e, R[i]) if (D[i]+1 == D[*e]) {
	S[*e].push_back(i);
    }

    int cst0 = 0, cst1 = 0;
    REP (i, len-1) {
	int x = P[i], y = P[i+1];
	bool has = false, diff = false;
	EACH (e, S[x]) {
	    if (*e == y) has = true;
	    if (*e != y) diff = true;
	}

	if (!has) {
	    cst0++;
	    cst1++;
	} else if (diff) {
	    cst1++;
	}
    }

    printf("%d %d\n", cst0, cst1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}