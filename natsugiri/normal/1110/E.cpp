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

int N;
LL C[100011];
LL T[100011];

LL X[100011];
LL Y[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld", C+i);
    REP (i, N) scanf("%lld", T+i);

    REP (i, N-1) X[i] = C[i] - C[i+1];
    REP (i, N-1) Y[i] = T[i] - T[i+1];
    sort(X, X+N-1);
    sort(Y, Y+N-1);
    bool yes = true;
    REP (i, N-1) if (X[i] != Y[i]) yes = false;
    if (C[0] != T[0]) yes = false;
    if (C[N-1] != T[N-1]) yes = false;
    puts(yes? "Yes": "No");
}


int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}