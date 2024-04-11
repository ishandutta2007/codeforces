#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<tuple>

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

VI G[32];
int low[32], high[32];

using Tuple = tuple<int, int, int>;
vector<Tuple> ans;

void MAIN() {
    int L, R;
    scanf("%d%d", &L, &R);
    int D = R-L+1;

    int cnt = 1;
    low[0] = 0;
    high[0] = 0;
    low[1] = 1;
    high[1] = 1;
    ans.emplace_back(0, 1, 1);

    int v = 2;

    while (cnt * 2 <= D) {
	low[v] = 1;
	high[v] = cnt * 2;

	int w = 1;
	REP (i, v) {
	    ans.emplace_back(i, v, w-low[i]);
	    w += high[i] - low[i] + 1;
	}

	v++;
	cnt *= 2;
    }

    int w = L;
    for (int i=0; i<v; i++) {
	int c = high[i] - low[i] + 1;
	if (i == 0 || (D & c)) {
	    ans.emplace_back(i, v, w - low[i]);
	    w += c;
	    D -= c;
	}
    }

    puts("YES");
    printf("%d %d\n", v+1, (int)ans.size());

    EACH (e, ans) {
	int x, y, c;
	tie(x, y, c) = *e;
	assert(c > 0);
	printf("%d %d %d\n", x+1, y+1, c);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}