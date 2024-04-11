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

const char *COLOR = "RGBYW";
int N;
char S[1011];
int A[1111];
int B[1111];

int main() {
    scanf("%d", &N);

    REP (i, N) {
	scanf("%s", S);
	REP (j, 5) if (S[0] == COLOR[j]) A[i] = j;
	B[i] = S[1] - '1';
    }

    int ans = 10;
    REP (a, 1<<5) REP (b, 1<<5) {
	bool ok = true;
	REP (i, N) if (ok) REP (j, i) if (ok) {
	    if (A[i] != A[j] || B[i] != B[j]) {
		int ii = (a & (1<<A[i])? (64<<A[i]): 0) | (b & (1<<B[i])? (1<<B[i]): 0);
		int jj = (a & (1<<A[j])? (64<<A[j]): 0) | (b & (1<<B[j])? (1<<B[j]): 0);

		if (ii == jj) ok = false;
	    }
	}

	if (ok) {
	    amin(ans, __builtin_popcount(a) + __builtin_popcount(b));
	}
    }

    printf("%d\n", ans);

    return 0;
}