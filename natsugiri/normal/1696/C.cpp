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

int N, M, K;
int A[50011];
int B[50011];

vector<pair<int, LL> > normal(int a[], int n) {
    vector<pair<int, LL> > ret;
    REP (i, n) {
	int x = a[i];
	LL c = 1;
	while (x % M == 0) {
	    x /= M;
	    c *= M;
	}

	if (ret.empty() || ret.back().first != x) {
	    ret.emplace_back(x, c);
	} else {
	    ret.back().second += c;
	}
    }
    return ret;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", A+i);
    scanf("%d", &K);
    REP (i, K) scanf("%d", B+i);

    auto A2 = normal(A, N);
    auto B2 = normal(B, K);
    if (A2 == B2) {
	puts("Yes");
    } else {
	puts("No");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}