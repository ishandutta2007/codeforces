#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<set>

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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

LL N, M;
LL L, R;

int ans[200011][4];
VI F[200011];
int C[200011];
set<int> se;

void MAIN() {
    scanf("%lld%lld%lld%lld", &N, &M, &L, &R);
    for (int i=1; i<=200000; i++) for (int j=i; j<=200000; j+=i) {
	F[j].push_back(i);
    }

    LL y_low = M + 1;
    LL y_high = M;

    for (LL X1=1; X1<=N; X1++) {
	LL new_y_low = max(1LL, (L + X1 - 1) / X1);
	LL new_y_high = min(M, R / X1);

	if (new_y_low > new_y_high) continue;

	while (new_y_low < y_low) {
	    y_low--;
	    EACH (e, F[y_low]) {
		C[*e]++;
		if (C[*e] == 1) {
		    se.insert(*e);
		}
	    }
	}

	while (new_y_high < y_high) {
	    EACH (e, F[y_high]) {
		C[*e]--;
		if (C[*e] == 0) {
		    se.erase(*e);
		}
	    }
	    y_high--;
	}

	EACH (e, F[X1]) {
	    LL B = *e;
	    auto it = se.upper_bound(B);
	    if (it == se.end()) break;
	    LL A = *it;

	    LL K = X1 / B;
	    if (K * A <= N) {
		LL T = y_high / A;
		ans[X1][0] = X1;
		ans[X1][1] = T * A;
		ans[X1][2] = K * A;
		ans[X1][3] = T * B;
		break;
	    }
	}
    }

    for (int i=1; i<=N; i++) {
	if (ans[i][0] == 0) {
	    puts("-1");
	} else {
	    rprintf("%d", ans[i], ans[i]+4);
	    assert(ans[i][0] <= N);
	    assert(ans[i][1] <= M);
	    assert(ans[i][2] <= N);
	    assert(ans[i][3] <= M);
	    assert(ans[i][0] < ans[i][2]);
	    assert(ans[i][3] < ans[i][1]);
	    LL left = (LL)ans[i][0] * ans[i][1];
	    LL right = (LL)ans[i][2] * ans[i][3];
	    assert(left == right);
	    assert(L <= left && left <= R);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}