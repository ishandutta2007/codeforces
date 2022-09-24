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

const int SIZE = 500011;
const int LOG = 20;
int N, M;
int D[LOG][SIZE];

void MAIN() {
    scanf("%d%d", &N, &M);

    REP (i, SIZE) D[0][i] = i;
    REP (i, N) {
	int l, r;
	scanf("%d%d", &l, &r);
	amax(D[0][l], r);
    }

    int ma = 0;
    REP (i, SIZE) {
	amax(ma, D[0][i]);
	amax(D[0][i], ma);
    }
    REP (t, LOG-1) REP (i, SIZE) D[t+1][i] = D[t][D[t][i]];

    REP (i, M) {
	int l, r;
	scanf("%d%d", &l, &r);

	int ans = 1<<29;
	int cur = 0;
	for (int t=LOG; t--;) {
	    if (D[t][l] < r) {
		cur += 1<<t;
		l = D[t][l];
	    } else {
		amin(ans, cur + (1<<t));
	    }
	}
	if (ans == (1<<29)) {
	    puts("-1");
	} else {
	    printf("%d\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}