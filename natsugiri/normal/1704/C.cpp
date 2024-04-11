#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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

LL N;
int M;
LL A[100011];

void MAIN() {
    scanf("%lld%d", &N, &M);
    REP (i, M) scanf("%lld", A+i), A[i]--;

    sort(A, A+M);
    vector<LL> V;
    REP (i, M-1) {
	LL g = A[i+1] - A[i] - 1;
	if (g) V.push_back(g);
    }
    {
	LL g = N + A[0] - A[M-1] - 1;
	if (g) V.push_back(g);
    }
    sort(V.begin(), V.end());

    LL safe = 0;
    LL day = 0;
    for (int i=(int)V.size()-1; i>=0; i--) {
	LL len = V[i] - day * 2;
	if (len > 0) {
	    safe++;
	    day++;
	    len -= 2;
	    if (len > 0) {
		safe += len;
		day++;
	    }
	}
    }
    printf("%lld\n", N-safe);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}