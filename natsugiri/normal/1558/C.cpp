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
int A[2222];
VI ans;

void ADD(int x) {
    assert(x % 2 == 1);
    ans.push_back(x);
    reverse(A, A+x);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    bool yes = true;
    REP (i, N) if (A[i] % 2 == i % 2) yes = false;

    if (yes) {
	ans.clear();

	int len = N;
	while (len >= 3) {
	    if (A[len-1] == len && A[len-2] == len-1) {
		len -= 2;
	    } else if (A[0] == len && A[1] == len-1) {
		ADD(len);
	    } else {
		int a = -1, b = -1;
		REP (i, len) {
		    if (A[i] == len) a = i;
		    if (A[i] == len-1) b = i;
		}

		if (b+1 == a) {
		    ADD(a+1);
		} else if (a+1 == b) {
		    ADD(b+2);
		} else if (a == 0) {
		    ADD(b);
		} else {
		    ADD(a+1);
		}
	    }
	}

	printf("%d\n", (int)ans.size());
	rprintf("%d", ans.begin(), ans.end());
    } else {
	puts("-1");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}