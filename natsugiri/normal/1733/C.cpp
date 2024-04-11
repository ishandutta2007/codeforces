#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
int A[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);

    vector<pair<int, int> > ans;


    if (N > 1) {
	auto PUSH = [&](int i, int j) {
	    if (A[i] == A[j]) return;

	    ans.emplace_back(i, j);
	    if (A[i] % 2 == A[j] % 2) {
		A[i] = A[j];
	    } else {
		A[j] = A[i];
	    }
	};

	PUSH(0, N-1);
	for (int i=1; i<N-1; i++) {
	    if (A[0] % 2 == A[i] % 2) {
		PUSH(i, N-1);
	    } else {
		PUSH(0, i);
	    }
	}
    }
    // rprintf("%d,", A, A+N);
    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d %d\n", e->first + 1, e->second + 1);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}