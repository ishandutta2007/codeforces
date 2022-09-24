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
LL X;
char S[100011];

void MAIN() {
    scanf("%d%lld", &N, &X);
    scanf("%s", S);

    int c0 = count(S, S+N, '0');
    int c1 = N - c0;

    bool yes = true;
    int ans = 0;
    int a0 = 0, a1 = 0;
    REP (i, N) {
	if (c0 == c1) {
	    if (a0 - a1 == X) yes = false;
	} else {
	    LL r = X - (a0 - a1);
	    LL d = c0 - c1;
	    if (r % d == 0 && r / d >= 0) ans++;
	}

	if (S[i] == '0') a0++;
	else a1++;
    }

    if (yes) printf("%d\n", ans);
    else puts("-1");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}