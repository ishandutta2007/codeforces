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
char S[100011];
void MAIN() {
    scanf("%s", S);
    N = strlen(S);

    int c1 = count(S, S+N, '1');
    REP (i, N) {
	if (S[i] == '0') {
	    putchar('0');
	} else if (S[i] == '2') {
	    while (c1) {
		putchar('1');
		c1--;
	    }
	    putchar('2');
	}
    }
    while (c1) {
	putchar('1');
	c1--;
    }
    putchar('\n');
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}