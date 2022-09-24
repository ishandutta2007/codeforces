#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N, M;
int A[2][200111];

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d %d", A[0]+i, A[1] + i);
    int max_l = *max_element(A[0], A[0] + N);
    int min_r = *min_element(A[1], A[1] + N);
    scanf("%d", &N);
    REP (i, N) scanf("%d %d", A[0]+i, A[1] + i);

    LL ans = 0, tmp;
    tmp = *max_element(A[0], A[0] + N);
    amax(ans, tmp - min_r);
    tmp = *min_element(A[1], A[1] + N);
    amax(ans, max_l - tmp);

    printf("%lld\n", ans);

    return 0;
}