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
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;

int Z;
VI S;
int buf[2][83][6401];
int (*cur)[6401] = buf[0];
int (*nxt)[6401] = buf[1];
int ans[6401];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int a;
	scanf("%d", &a);
	if (a == 0) Z++;
	if (a == 1) S.push_back(i);
    }

    if (S.empty()) {

    } else {
	S.push_back(N);
	int hi = 0;
	memset(cur, 0xc0, sizeof buf[0]);
	cur[0][0] = 0;
	REP (i, S.size()) {
	    memset(nxt, 0xc0, sizeof buf[0]);

	    int nxt_hi = hi;
	    REP (a, Z+1) REP (b, hi+1) if (cur[a][b] >= 0) {
		REP (c, Z-a+1) {
		    int cst = abs(a+c+i - S[i]);
		    amax(nxt[a+c][b + cst], cur[a][b] + a * c);
		    amax(nxt_hi, b + cst);
		}
	    }
	    hi = nxt_hi;
	    swap(cur, nxt);
	}

	REP (b, hi+1) ans[b] = cur[Z][b];
    }

    int len = N * (N-1) / 2 + 1;
    REP (i, len) amax(ans[i+1], ans[i]);
    rprintf("%d", ans, ans + len);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}