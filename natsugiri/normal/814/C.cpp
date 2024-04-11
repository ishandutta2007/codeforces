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

int N, Q;
char S[1511];
int R[1511][26];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);
    for (int l=1; l<=N; l++) {
	REP (c, 26) {
	    int t = 0;
	    REP (i, l-1) if (S[i] -'a' == c) t++;
	    for (int i=l-1; i<N; i++) {
		if (S[i] - 'a' == c) t++;
		amax(R[l-t][c], l);
		if (S[i-l+1] - 'a' == c) t--;
	    }
	}
    }

    REP (l, N+1) REP (c, 26) amax(R[l+1][c], R[l][c]);

    scanf("%d", &Q);
    REP ($, Q) {
	int M;
	char op[11];
	scanf("%d%s", &M, op);
	printf("%d\n", R[M][*op - 'a']);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}