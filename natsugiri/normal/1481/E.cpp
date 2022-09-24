#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
int A[500011];
int L[500011];
int R[500011];
int C[500011];

int X[500011];
int Xi;

int Z[500011];
int idx[500011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    int ma = 0;
    for (int i=N; i--;) {
	C[A[i]]++;
	amax(ma, C[A[i]]);
	Z[i] = ma;
    }

    memset(R, -1, sizeof R);
    memset(L, 0x3f, sizeof L);
    memset(C, 0, sizeof C);

    REP (i, N) {
	amin(L[A[i]], i);
	amax(R[A[i]], i);
	C[A[i]]++;
    }


    REP (i, N) idx[i] = i;
    sort(idx, idx+N, [&](int i, int j) {
	    return L[i] < L[j];
	    });

    int ans = 0;
    Xi = 0;
    int bestX = 0;
    REP (i_, N) {
	int i = idx[i_];
	if (R[i] == -1) continue;

	while (Xi < L[i]) {
	    amax(bestX, X[Xi]);
	    Xi++;
	}

	int tmp = bestX + C[i];
	amax(ans, tmp + Z[R[i]+1]);
	X[R[i]] = tmp;
    }

    printf("%d\n", N-ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}