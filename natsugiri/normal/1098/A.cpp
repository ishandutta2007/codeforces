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

const int MAXN = 100011;
int N;
LL A[MAXN];
int P[MAXN];
LL S[MAXN];

VI G[MAXN];

bool ok() {
    if (S[0] != A[0]) return false;
    if (A[0] < 0) return false;
    for (int i=1; i<N; i++) {
	if (S[i] != A[i] + S[P[i]]) return false;
	if (A[i] < 0) return false;
    }
    return true;
}

void MAIN() {
    scanf("%d", &N);
    P[0] = -1;
    REP (i, N-1) {
	scanf("%d", P+i+1);
	P[i+1]--;
	G[P[i+1]].push_back(i+1);
    }
    REP (i, N) scanf("%lld", S+i);

    A[0] = S[0];
    for (int i=1; i<N; i++) {
	if (S[i] == -1) {
	    if (G[i].empty()) {
		A[i] = 0;
	    } else {
		int p = P[i];
		A[i] = 1LL<<60;
		EACH (e, G[i]) {
		    amin(A[i], S[*e] - S[p]);
		}
	    }
	    S[i] = S[P[i]] + A[i];
	} else {
	    A[i] = S[i] - S[P[i]];
	}
    }

    if (ok()) {
	LL ans = 0;
	REP (i, N) ans += A[i];
	printf("%lld\n", ans);
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}