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
int M;
int A[100011];
int R[100011];
double P[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i), A[i]--;
    REP (i, M) scanf("%d%lf", R+i, P+i);

    int bad = -1;
    REP (i, N) if (A[i] != i) bad = i;


    double ans;
    if (bad == -1) {
	ans = 1.0;
    } else {
	double f = 1.0;
	REP (i, M) if (bad < R[i]) {
	    f *= 1.0 - P[i];
	}

	ans = 1.0 - f;
    }

    printf("%.12lf\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}