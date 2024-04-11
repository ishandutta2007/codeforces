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

int N, K;
int X[100011];
int First[100011], Last[100011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, K) scanf("%d", X+i);

    memset(First, 0x3f, sizeof First);
    memset(Last, -1, sizeof Last);
    REP (i, K) {
	amin(First[X[i]], i);
	amax(Last[X[i]], i);
    }

    int ans = 0;
    for (int i=1; i<=N; i++) {
	if (Last[i] < 0) ans++;
    }
    for (int i=1; i<N; i++) {
	if (Last[i] < First[i+1]) ans++;
	if (Last[i+1] < First[i]) ans++;
    }
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}