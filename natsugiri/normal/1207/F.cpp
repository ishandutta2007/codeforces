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

const int MAXN = 500011;
const int MAGIC = 200;


int A[MAXN];
int S[MAGIC][MAGIC];


void MAIN() {
    int Q;
    scanf("%d", &Q);
    REP ($, Q) {
	int op, x, y;
	scanf("%d%d%d", &op, &x, &y);
	if (op == 1) {
	    for (int mod=1; mod<MAGIC; mod++) S[mod][x%mod] += y;
	    A[x] += y;
	} else {
	    LL ans = 0;
	    if (x < MAGIC) {
		ans = S[x][y];
	    } else {
		for (int i=y; i<MAXN; i+=x) ans += A[i];
	    }
	    printf("%lld\n", ans);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}