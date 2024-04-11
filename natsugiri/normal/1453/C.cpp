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
char F[2011][2011];

int solve(const int d_) {
    const char d = d_ + '0';

    int ret = 0;

    int top = -1, bottom = -1;
    REP (i, N) REP (j, N) if (F[i][j] == d) {
	if (top == -1) top = i;
	bottom = i;
    }

    REP (i, N) {
	int left = -1, right = -1;
	REP (j, N) {
	    if (F[i][j] == d) {
		if (left == -1) left = j;
		right = j;
	    }

	    if (left != -1) {
		assert(top != -1);
		assert(bottom != -1);

		if (left != right) {
		    amax(ret, abs((right-left) * (i - 0)));
		    amax(ret, abs((right-left) * ((N-1) - i)));
		}

		int w = 0;
		amax(w, abs(left));
		amax(w, abs(N-1-left));
		amax(w, abs(right));
		amax(w, abs(N-1-right));
		amax(ret, w * abs(i - top));
		amax(ret, w * abs(bottom - i));
	    }
	}
    }

    return ret;
}

int ans[10];
void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%s", F[i]);

    memset(ans, 0, sizeof ans);
    REP (d, 10) amax(ans[d], solve(d));
    REP (i, N) for (int j=i+1; j<N; j++) swap(F[i][j], F[j][i]);
    REP (d, 10) amax(ans[d], solve(d));

    rprintf("%d", ans, ans + 10);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}