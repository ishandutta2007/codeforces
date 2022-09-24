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

int N, M;
char F[1011][1011];
VI ans;

void build(int a, int b, int c) {
    int half = M / 2;

    REP (i, half) ans.push_back(i%2? b: a);
    reverse(ans.begin(), ans.end());

    ans.push_back(b);

    REP (i, half) ans.push_back(i%2? b: c);
}

bool solve() {
    ans.clear();

    if (M % 2 == 1) {
	REP (k, M+1) ans.push_back(k % 2);
	return true;
    }

    REP (i, N) REP (j, i) {
	if (F[i][j] == F[j][i]) {
	    REP (k, M+1) {
		ans.push_back((k&1)?i:j);
	    }
	    return true;
	}
    }

    if (N == 2) return false;

    if (F[0][1] == F[1][2]) {
	build(0, 1, 2);
    } else if (F[1][2] == F[2][0]) {
	build(1, 2, 0);
    } else if (F[2][0] == F[0][1]) {
	build(2, 0, 1);
    }
    return true;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    if (solve()) {
	puts("YES");
	EACH (e, ans) (*e)++;
	rprintf("%d", ans.begin(), ans.end());
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