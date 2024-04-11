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
char A[100111];
int C[256];

int main() {
    scanf("%s", A);
    N = strlen(A);
    REP (i, N) C[A[i]]++;

    int ans = N;
    amin(ans, C['B']);
    amin(ans, C['u']/2);
    amin(ans, C['l']);
    amin(ans, C['b']);
    amin(ans, C['a']/2);
    amin(ans, C['s']);
    amin(ans, C['a']/2);
    amin(ans, C['u']/2);
    amin(ans, C['r']);

    printf("%d\n", ans);

    return 0;
}