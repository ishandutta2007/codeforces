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
int Z[10][3];
char buf[111];

void go(int ad) {
    scanf("%s", buf);
    int n = strlen(buf);
    if (buf[n-1] == 'S') Z[n-1][0] += ad;
    if (buf[n-1] == 'M') Z[n-1][1] += ad;
    if (buf[n-1] == 'L') Z[n-1][2] += ad;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) go(1);
    REP (i, N) go(-1);

    int ans = 0;
    REP (i, 10) REP (j, 3) if (Z[i][j] > 0) ans += Z[i][j];
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}