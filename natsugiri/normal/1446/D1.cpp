#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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
int C[200011];

bool is_unique() {
    REP (i, N) if (A[i] != A[0]) return false;
    return true;
}

int X;
int know[200011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    int ma = *max_element(A, A+N);


    if (is_unique()) {
	puts("0");
	return;
    }

    REP (i, N) C[A[i]]++;
    X = max_element(C, C+N+1) - C;

    int ans = 0;

    REP (t, ma + 1) {
	if (t == X) continue;

	memset(know, -1, sizeof know);
	int sum = 0;
	know[0] = 0;

	REP (i, N) {
	    if (A[i] == t) {
		sum--;
	    } else if (A[i] == X) {
		sum++;
	    }

	    if (sum <= 0) {
		amax(ans, i+1);
	    } else if (know[sum] != -1) {
		amax(ans, i+1 - know[sum]);
	    } else {
		know[sum] = i+1;
	    }
	}
    }


    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}