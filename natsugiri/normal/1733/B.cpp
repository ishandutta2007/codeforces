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

int N, X, Y;
VI ans;

void MAIN() {
    scanf("%d%d%d", &N, &X, &Y);
    if (X > Y) swap(X, Y);

    ans.clear();

    if (X == 0 && Y > 0 && (N-1) % Y == 0) {
	int left = 1;
	int streak = 0;
	for (int i=2; i<=N; i++) {
	    if (streak == Y) {
		left = i;
		streak = 1;
	    } else {
		streak++;
	    }
	    ans.push_back(left);
	}
    }

    if (ans.empty()) {
	puts("-1");
    } else {
	rprintf("%d", ans.begin(), ans.end());
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}