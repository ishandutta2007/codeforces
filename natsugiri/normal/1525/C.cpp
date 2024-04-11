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
LL M;
LL X[300011];
char S[300011];

int idx[300011];

LL Y[300011];
int ans1[300011];
VI B[2];

void MAIN() {
    scanf("%d%lld", &N, &M);
    REP (i, N) scanf("%lld", X+i);
    REP (i, N) scanf("%s", S+i);

    REP (i, N) idx[i] = i;
    sort(idx, idx+N, [&](int i, int j) {
	    return X[i] < X[j];
	    });

    REP (i, N) ans1[i] = -1;
    REP (t, 2) B[t].clear();

    REP (i_, N) {
	int i = idx[i_];
	if (S[i] == 'R') {
	    B[X[i] % 2].push_back(i);
	    Y[i] = X[i];
	} else {
	    if (B[X[i] % 2].size()) {
		int j = B[X[i] % 2].back();
		B[X[i] % 2].pop_back();
		ans1[i] = ans1[j] = (X[i] - Y[j]) / 2;
	    } else {
		B[X[i] % 2].push_back(i);
		Y[i] = -X[i];
	    }
	}
    }
    REP (t, 2) {
	while (B[t].size() >= 2u) {
	    int i = B[t].back();
	    B[t].pop_back();
	    int j = B[t].back();
	    B[t].pop_back();

	    // eprintf("[%lld %lld]\n", Y[i], Y[j]);
	    LL y = 2*M - Y[i];
	    ans1[i] = ans1[j] = (y - Y[j]) / 2;
	}
    }

    rprintf("%d", ans1, ans1+N);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}