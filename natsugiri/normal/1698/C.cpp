#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N;
LL A[200011];

void MAIN() {
    scanf("%d", &N);
    int zero = 0;
    int len = 0;
    REP (i, N) {
	LL x;
	scanf("%lld", &x);
	if (x == 0) zero++;
	else A[len++] = x;
    }

    bool yes;
    if (len <= 1) {
	yes = true;
    } else if (len == 2) {
	yes = (A[0] + A[1] == 0);
    } else if (len <= 4) {

	yes = true;

	if (zero) {
	    A[len++] = 0;
	}
	sort(A, A+len);

	REP (i, len) for (int j=i+1; j<len; j++) for (int k=j+1; k<len; k++) {
	    bool find = false;
	    LL target = A[i] + A[j] + A[k];
	    REP (l, len) {
		if (target == A[l]) {
		    find = true;
		    break;
		}
	    }

	    if (!find) {
		yes = false;
		break;
	    }
	}

    } else {
	yes = false;
    }

    puts(yes?"YES":"NO");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}