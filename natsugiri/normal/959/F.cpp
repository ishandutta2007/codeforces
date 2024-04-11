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
const LL MOD = 1e9 + 7;
LL powMod(LL x, LL y) {
    x %= MOD;
    LL r = 1;
    for (; y; y>>=1) {
	if (y & 1) r = r * x % MOD;
	x = x * x % MOD;
    }
    return r;
}

int N, Q;
struct Query {
    int l, x, i;
    bool operator<(const Query &y) const {
	return l < y .l;
    }
} query[100011];;

int A[100011];
int D[30];
int ans[100011];

void MAIN() {
    scanf("%d%d", &N, &Q);
    REP (i, N) scanf("%d", A+i);
    REP (i, Q) {
	scanf("%d%d", &query[i].l, &query[i].x);
	query[i].i = i;
    }

    sort(query, query+ Q);
    int rk = 0;
    int cur = 0;
    REP (i, Q) {
	while (cur < query[i].l) {
	    int a = A[cur++];
	    for (int t=20; t--;) {
		if (a>>t & 1) a ^= D[t];
		if (a>>t & 1) {
		    rk++;
		    D[t] = a;
		    break;
		}
	    }
	}

	{
	    int a = query[i].x;
	    for (int t=20; t--;) {
		if (a>>t & 1) a ^= D[t];
	    }

	    if (a == 0) {
		ans[query[i].i] = powMod(2, cur - rk);
	    } else {
		ans[query[i].i] = 0;
	    }
	}
    }

    REP (i, Q) printf("%d\n", ans[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}