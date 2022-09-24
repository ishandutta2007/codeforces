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
int A[100111];
int S[100111];
LL sq(LL x) { return x * x; }

int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) {
	S[i] += A[i];
	S[i+1] += S[i];
    }

    LL ans = 1 + (LL)A[1] * A[1];
    for (LL len=1; len<=N; len++) {
	LL l = len * len;
	if (l >= ans) continue;
	REP (i, N-len) {
	    LL tmp = l + sq(S[i+len] - S[i]);
	    amin(ans, tmp);
	}
    }
    
    printf("%lld\n", ans);

    return 0;
}