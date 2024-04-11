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

int N, K, M;
int B[200011];
VI X;

bool is_subset() {
    int idx = 0;
    REP (i, M) {
	while (idx < N && idx < B[i]) {
	    X.push_back(idx);
	    idx++;
	}
	if (idx == B[i]) {
	    idx++;
	} else {
	    return false;
	}
    }

    while (idx < N) X.push_back(idx++);
    return true;
}

bool divide() {
    int rem = N - M;
    if (rem % (K-1)) return false;

    int half = K/2;
    int small = X[half-1];
    int large = X.rbegin()[half-1];
    REP (i, M) if (small <= B[i] && B[i] <= large) return true;
    return false;
}

void MAIN() {
    scanf("%d%d%d", &N, &K, &M);
    REP (i, M) scanf("%d", B+i), B[i]--;

    X.clear();

    if (is_subset() && divide()) {
	puts("YES");
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