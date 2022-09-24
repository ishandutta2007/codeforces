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
int L, R;

int C[200011];

void MAIN() {
    scanf("%d%d%d", &N, &L, &R);

    REP (i, N) C[i] = 0;

    REP (i, N) {
	int c;
	scanf("%d", &c);
	c--;
	if (i < L) {
	    C[c]++;
	} else {
	    C[c]--;
	}
    }

    VI V, W;
    int vsum = 0;
    int wsum = 0;

    REP (i, N) if (C[i]) {
	if (C[i] > 0) {
	    vsum += C[i];
	    V.push_back(C[i]);
	} else {
	    wsum -= C[i];
	    W.push_back(-C[i]);
	}
    }

    int ans = 0;
    REP (i, V.size()) {
	while (vsum > wsum && V[i] >= 2) {
	    ans++;
	    vsum -= 2;
	    V[i] -= 2;
	}
    }
    REP (i, W.size()) {
	while (wsum > vsum && W[i] >= 2) {
	    ans++;
	    wsum -= 2;
	    W[i] -= 2;
	}
    }

    ans += min(vsum, wsum);
    ans += abs(vsum - wsum);

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}