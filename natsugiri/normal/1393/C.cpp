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

int N;
pair<int, int> P[100011];
VI B[100011];

int last[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%d", &P[i].first);
	P[i].second = 1;
    }
    sort(P, P+N);
    int len = 1;
    for (int i=1; i<N; i++) {
	if (P[len-1].first != P[i].first) {
	    P[len++] = P[i];
	} else {
	    P[len-1].second++;
	}
    }

    int block = 0;
    REP (i, len) amax(block, P[i].second);
    REP (i, block) B[i].clear();

    REP (i, len) if (P[i].second == block) {
	REP (j, P[i].second) B[j].push_back(P[i].first);
    }

    REP (i, len) if (P[i].second == block - 1) {
	REP (j, P[i].second) B[j].push_back(P[i].first);
    }

    int pos = 0;
    REP (i, len) if (P[i].second < block - 1) {
	REP (j, P[i].second) {
	    B[pos].push_back(P[i].first);
	    pos++;
	    if (pos == block - 1) pos = 0;
	}
    }

    pos = 0;
    REP (i, block) EACH (e, B[i]) {
	P[pos++].first = *e;
	last[*e] = -1;
    }
    assert(pos == N);

    int ans = N;
    REP (i, pos) {
	int m = P[i].first;
	if (last[m] != -1) amin(ans, i - last[m] - 1);
	last[m] = i;
    }
    printf("%d\n", ans);

//    REP (i, pos) eprintf("%d ", P[i].first);
//    eprintf("\n");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}