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

int N, M, Q;
VI IN[100011];
LL out[100011];

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;

	if (x < y) {
	    IN[x].push_back(y);
	    out[y]++;
	} else {
	    IN[y].push_back(x);
	    out[x]++;
	}
    }
    
    LL ans = 0;
    REP (i, N) ans += (LL)IN[i].size() * out[i];

    printf("%lld\n", ans);

    scanf("%d", &Q);
    REP ($, Q) {
	int v;
	scanf("%d", &v);
	v--;

	ans -= (LL)IN[v].size() * out[v];

	EACH (e, IN[v]) {
	    ans += out[*e] - (LL)IN[*e].size() - 1;
	    IN[*e].push_back(v);
	    out[*e]--;
	}

	out[v] += IN[v].size();
	IN[v].clear();

	printf("%lld\n", ans);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}