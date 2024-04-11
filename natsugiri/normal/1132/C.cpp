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

int N, Q;
int L[5011], R[5011];

int C[5011];
int C1[5011];
int C2[5011];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, Q) scanf("%d%d", L+i, R+i), L[i]--;

    REP (i, Q) {
	C[L[i]]++;
	C[R[i]]--;
    }
    REP (i, N) C[i+1] += C[i];

    int seg = 0;
    REP (i, N) {
	if (C[i]) seg++;

	C1[i+1] += C1[i];
	C2[i+1] += C2[i];
	if (C[i] == 1) C1[i+1]++;
	if (C[i] == 2) C2[i+1]++;
    }

    int ans = 0;
    REP (i, Q) REP (j, i) {
	if (R[i] <= L[j] || R[j] <= L[i]) {
	    amax(ans, seg - C1[R[i]] + C1[L[i]] - C1[R[j]] + C1[L[j]]);
	} else {
	    int l1 = min(L[i], L[j]);
	    int r1 = max(R[i], R[j]);
	    int l2 = max(L[i], L[j]);
	    int r2 = min(R[i], R[j]);
	    amax(ans, seg - C1[r1] + C1[l1] - C2[r2] + C2[l2]);
	}
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}