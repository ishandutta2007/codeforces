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

int N, M;
int K;
LL X, Y;
int A[200011];
int B[200011];
bool kill[200011];

void MAIN() {
    scanf("%d%d", &N, &M);
    scanf("%lld%d%lld", &X, &K, &Y);
    REP (i, N) scanf("%d", A+i);
    REP (i, M) scanf("%d", B+i);

    int idx = 0;
    REP (i, N) {
	if (idx < M && A[i] == B[idx]) idx++;
	else kill[i] = true;
    }

    bool yes = (idx == M);
    LL ans = 0;

    if (yes) {
	int left = -1;
	for (int i=0; i<=N; i++) {
	    if (!kill[i]) {
		if (left + 1 < i) {

		    // left; [ ... ]; i
		    int l_power = (left == -1? -1: A[left]);
		    int r_power = (i == N? -1: A[i]);

		    int len = i - left - 1;
		    LL cst = 1LL<<60;

		    for (int t=1; t*K<=len; t++) {
			amin(cst, t*X + (len-t*K)*Y);
		    }

		    int ma = *max_element(A+left+1, A+i);
		    if (ma < l_power || ma < r_power) {
			amin(cst, len * Y);
		    }

		    if (cst == (1LL<<60)) {
			yes = false;
			break;
		    }

		    ans += cst;
		}

		left = i;
	    }
	}
    }

    if (yes) {
	printf("%lld\n", ans);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}