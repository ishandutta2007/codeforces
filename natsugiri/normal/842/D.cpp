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
const int BASE = 1<<19;
int B[BASE * 2];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) {
	int x;
	scanf("%d", &x);
	B[x + BASE] = 1;
    }
    for (int i=BASE; --i;) {
	B[i] = B[i*2] + B[i*2+1];
    }

    int mask = 0;
    REP ($, M) {
	int x;
	scanf("%d", &x);
	mask ^= x;

	int cur = 1, len = BASE;
	for (int t=19; t--;) {
	    len >>= 1;
	    if (mask >> t & 1) {
		if (B[cur*2+1] == len) {
		    cur = cur * 2;
		} else {
		    cur = cur * 2 + 1;
		}
	    } else {
		if (B[cur*2] == len) {
		    cur = cur * 2 + 1;
		} else {
		    cur = cur * 2;
		}
	    }
	}

	printf("%d\n", (cur - BASE) ^ mask);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}