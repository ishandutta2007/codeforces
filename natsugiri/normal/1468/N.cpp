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
LL C[3];
LL A[5];

void MAIN() {
    REP (i, 3) scanf("%lld", C+i);
    REP (i, 5) scanf("%lld", A+i);
    bool yes = true;
    
    if (C[0] < A[0]) yes = false;
    if (C[1] < A[1]) yes = false;
    if (C[2] < A[2]) yes = false;
    if (C[0] + C[2] < A[0] + A[2] + A[3]) yes = false;
    if (C[1] + C[2] < A[1] + A[2] + A[4]) yes = false;
    if (C[0] + C[1] + C[2] < A[0] + A[1] + A[2] + A[3] + A[4]) yes = false;
    puts(yes? "YES": "NO");

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}