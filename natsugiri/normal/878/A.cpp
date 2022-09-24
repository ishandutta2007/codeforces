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
const int SIZE = 1024;

void MAIN() {
    scanf("%d", &N);

    int cur0 = 0, cur1 = (1<<10) - 1;
    REP (i, N) {
	char op[11]; int x;
	scanf("%s%d", op, &x);
	if (*op == '&') {
	    cur0 &= x;
	    cur1 &= x;
	} else if (*op == '|') {
	    cur0 |= x;
	    cur1 |= x;
	} else if (*op == '^') {
	    cur0 ^= x;
	    cur1 ^= x;
	}
    }

    puts("3");
    int mask = 0;
    REP (i, 10) if ((cur0>>i&1) || (cur1>>i&1)) mask |= 1<<i;
    printf("& %d\n", mask);

    mask = 0;
    REP (i, 10) if ((cur0>>i&1) && (cur1>>i&1)) mask |= 1<<i;
    printf("| %d\n", mask);

    mask = 0;
    REP (i, 10) if ((cur0>>i&1) && (~cur1>>i&1)) mask |= 1<<i;
    printf("^ %d\n", mask);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}