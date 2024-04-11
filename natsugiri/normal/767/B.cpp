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

LL Ts, Tf, T;
int N;
LL A[100111];

int main() {
    scanf("%lld%lld%lld%d", &Ts, &Tf, &T, &N);
    REP (i, N) scanf("%lld", A+i);
    sort(A, A+N);
    
    LL ans = Ts, ans_pos = 0;
    LL last = Ts;
    REP (i, N) {
	if (last > Tf-T) break;
	if (last < A[i]) {
	    if (ans > 0) {
		ans = 0;
		ans_pos = last;
	    }
	    last = A[i] + T;
	} else {
	    if (ans > last - (A[i] - 1)) {
		ans = last - (A[i] - 1);
		ans_pos = A[i] - 1;
	    }
	    last += T;
	}
    }
    if (last <= Tf - T) {
	if (ans > 0) {
	    ans = 0;
	    ans_pos = last;
	}
    }

    printf("%lld\n", ans_pos);

    return 0;
}