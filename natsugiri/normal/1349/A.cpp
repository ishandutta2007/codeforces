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
VI C[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int a;
	scanf("%d", &a);
	for (int p=2; p*p<=a; p++) {
	    int cnt = 0;
	    while (a % p == 0) {
		a /= p;
		cnt++;
	    }

	    if (cnt) {
		C[p].push_back(cnt);
	    }
	}

	if (a > 1) C[a].push_back(1);
    }

    LL ans = 1;
    REP (p, 200011) {
	if ((int)C[p].size() == N-1) {
	    int m = *min_element(C[p].begin(), C[p].end());
	    REP (j, m) ans *= p;
	} else if ((int)C[p].size() == N) {
	    nth_element(C[p].begin(), C[p].begin()+1, C[p].end());
	    int m = C[p][1];
	    REP (j, m) ans *= p;
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}