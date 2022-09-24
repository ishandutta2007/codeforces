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
int A[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i);
    int cnt = count(A, A+N, 1);

    bool yes = true;
    if (cnt % 2) yes = false;
    if (yes) {
	// 1 (00|11)* 1
	if (N % 2 == 0 && A[0] == 1 && A[N-1] == 1) {
	    bool p = true;
	    for (int i=1; i+1<N; i+=2) {
		if (A[i] != A[i+1]) p = false;
	    }

	    if (p) yes = false;
	}
    }

    if (yes) {
	VI ans;

	for (int i = 0; i<N-2; ) {
	    int m = A[i] + A[i+1] + A[i+2];
	    if (m == 0) {
		i++;
	    } else if (m == 1) {
		if (A[i] == 1) {
		    ans.push_back(i+1);
		    A[i] = A[i+1] = A[i+2] = 1;
		} else {
		    i++;
		}
	    } else if (m == 2) {
		ans.push_back(i+1);
		A[i] = A[i+1] = A[i+2] = 0;
		i = max(0, i-2);
	    } else if (m == 3) {
		if (i && A[i-1] == 0) i--;
		else i += 2;
	    } else {
		assert(false);
	    }
	}

	assert(count(A, A+N, 1) == 0);
	puts("YES");
	printf("%d\n", (int)ans.size());
	if (ans.size()) {
	    rprintf("%d", ans.begin(), ans.end());
	}
    } else {
	puts("NO");
    }

}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}