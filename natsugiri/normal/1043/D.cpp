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
int A[11][100111];
int pos[11][100111];
int L[11], len[11];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (t, M) REP (i, N) scanf("%d", A[t]+i);
    REP (t, M) {
	REP (i, N) {
	    pos[t][A[t][i]] = i;
	}
    }

    LL ans = 0;
    REP (i, N) {
	int head = A[0][i];
	int c = N-i;
	for (int t=1; t<M; t++) {
	    if (len[t] > 1) {
		L[t]++;
		len[t]--;
	    } else {
		L[t] = pos[t][head];
		len[t] = 1;
		while (L[t] + len[t] < N
			&& i + len[t] < N
			&& A[0][i+len[t]] == A[t][L[t]+len[t]]) {
		    len[t]++;
		}
	    }
	    amin(c, len[t]);
	}
	ans += c;
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}