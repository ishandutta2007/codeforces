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

void MAIN() {
    scanf("%d", &N);

    int ans = 0;
    REP (t, 9) {
	VI a, b;
	REP (i, N) {
	    if (i>>t&1) b.push_back(i);
	    else a.push_back(i);
	}
	if (a.empty() || b.empty()) break;

	VI q;
	EACH (e, a) q.push_back(*e+1);
	EACH (e, b) q.push_back(*e+1);
	printf("%d %d ", (int)a.size(), (int)b.size());
	rprintf("%d", q.begin(), q.end());
	fflush(stdout);

	int r;
	scanf("%d", &r);
	amax(ans, r);
    }

    printf("-1 %d\n", ans);
    fflush(stdout);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}