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

const int MAXN = 200111;
int N;
int A[MAXN];
int xors[MAXN];
int B[32];

int ge(int a) {
    for (int i=31; i--; ) {
	if (a>>i&1) a ^= B[i];
    }
    return a;
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) xors[i+1] = xors[i] ^ A[i];

    if (xors[N] == 0) {
	puts("-1");
    } else {
	int ans = 1;
	int last = 0;
	REP (i, N) {
	    int a = xors[i+1] ^ xors[last];
	    if (a == 0) continue;

	    int b = xors[N] ^ xors[i+1];

	    int c = ge(a), d = ge(b);
	    if (c && d && c != d) {
		ans++;
		B[__lg(c)] = c;
		last = i+1;
	    }
	}
	printf("%d\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}