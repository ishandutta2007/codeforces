#include<stack>
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

const LL INF = 1LL<<40;
int N;
char OP[100011];
int X[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	scanf("%s", OP+i);
	if (OP[i] == 'f') scanf("%d", X+i);
    }

    stack<LL> L;
    L.push(1);
    LL ans = 0;
    REP (i, N) {
	if (OP[i] == 'f') {
	    L.push(min(INF, X[i] * L.top()));
	} else if (OP[i] == 'e') {
	    L.pop();
	} else {
	    ans = min(INF, ans + L.top());
	}
    }

    if (ans >= (1LL<<32)) {
	puts("OVERFLOW!!!");
    } else {
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}