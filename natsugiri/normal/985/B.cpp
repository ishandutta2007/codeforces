#include<bitset>
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

typedef bitset<(1<<11)> Bits;

int N, M;
Bits B[2011];
Bits U[2011];
Bits D[2011];
char buf[1<<11];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	scanf("%s", buf);
	B[i] = Bits(buf);
    }

    REP (i, N) U[i+1] = U[i] | B[i];
    for (int i=N; i--;) D[i] = D[i+1] | B[i];

    REP (i, N) {
	if ((U[i]|D[i+1]).count() == M) {
	    puts("YES");
	    return;
	}
    }
    puts("NO");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}