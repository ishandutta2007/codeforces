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

LL N;
int Q;
LL U, len;
char S[100111];

int main() {
    scanf("%lld%d", &N, &Q);
    LL root = (N+1)/2;
    REP ($, Q) {
	scanf("%lld%s", &U, S);
	REP (i, strlen(S)) {
	    int k = __builtin_ctzll(U);
	    if (S[i] == 'U') {
		if (U != root) {
		    U &= ~(1LL<<k);
		    U |= 1LL<<(k+1);
		}
	    } else if (S[i] == 'L') {
		if (k > 0) {
		    U &= ~(1LL<<k);
		    U |= 1LL<<(k-1);
		}
	    } else if (S[i] == 'R') {
		if (k > 0) {
		    U |= 1LL<<(k-1);
		}
	    }
	}
	printf("%lld\n", U);
    }

    return 0;
}