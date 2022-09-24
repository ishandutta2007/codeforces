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

char S[200011];
int N;

pair<int, int> solve(char L, char R) {
    int cur = 0;
    int mi = 0, ma = 0;
    REP (i, N) {
	if (S[i] == L) cur--;
	if (S[i] == R) cur++;
	amin(mi, cur);
	amax(ma, cur);
    }

    const int MI = mi;
    const int MA = ma;
    pair<int, int> ret;
    ret.first = ma - mi + 1;
    ret.second = ret.first;

    for (int t=1; t<=2; t++) {
	bool f = false;
	cur = 0;
	mi = 0, ma = 0;
	REP (i, N) {
	    if (S[i] == L) {
		if (!f && (t&1) && MI == cur-1) {
		    cur++;
		    f = true;
		    amin(mi, cur);
		    amax(ma, cur);
		}
		cur--;
	    }
	    if (S[i] == R) {
		if (!f && (t&2) && MA == cur+1) {
		    cur--;
		    f = true;
		    amin(mi, cur);
		    amax(ma, cur);
		}
		cur++;
	    }
	    amin(mi, cur);
	    amax(ma, cur);
	}
	amin(ret.second, ma - mi + 1);
    }
    return ret;
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    auto a = solve('A', 'D');
    auto b = solve('S', 'W');
    LL ans = (LL)a.first * b.first;
    amin(ans, (LL)a.first * b.second);
    amin(ans, (LL)b.first * a.second);
    printf("%lld\n", ans);
//    eprintf("%lld %lld\n", a, b);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}