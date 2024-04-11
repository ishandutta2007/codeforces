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
VI small, large;

void MAIN() {
    scanf("%d", &N);
    int asc = 0;

    REP (i, N) {
	int l;
	scanf("%d", &l);
	bool a = false;
	int ma = -1, mi = 1<<30;
	REP (j, l) {
	    int x;
	    scanf("%d", &x);
	    if (mi < x) a = true;
	    amax(ma, x);
	    amin(mi, x);
	}

	if (a) {
	    asc++;
	} else {
	    small.push_back(mi);
	    large.push_back(ma);
	}
    }

    sort(small.begin(), small.end());
    sort(large.begin(), large.end());
    LL ans = 0;
    ans += (LL)asc * (N - asc) * 2;
    ans += (LL)asc * asc;

    int pos = 0;
    EACH (e, large) {
	while (pos < (int)small.size() && small[pos] < *e) pos++;
	ans += pos;
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}