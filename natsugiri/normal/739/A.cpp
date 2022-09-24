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
int L[100111], R[100111];
int A[100111];

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) scanf("%d%d", L+i, R+i), L[i]--;

    int ans = N;
    REP (i, M) amin(ans, R[i] - L[i]);
    printf("%d\n", ans);
    REP (i, N) A[i] = i % ans;
    rprintf("%d", A, A+N);

    return 0;
}