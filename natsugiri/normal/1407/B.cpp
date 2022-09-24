#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

LL gcd(LL x, LL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N;
VI ans;
vector<pair<int, int> > cur, nxt;

void MAIN() {
    scanf("%d", &N);
    cur.clear();
    ans.clear();

    REP (i, N) {
	int x;
	scanf("%d", &x);
	cur.emplace_back(x, x);
    }

    while (cur.size()) {
	int ma = max_element(cur.begin(), cur.end())->first;
	nxt.clear();

	EACH (e, cur) {
	    if (e->first == ma) {
		ans.push_back(e->second);
	    } else {
		nxt.emplace_back(gcd(ma, e->first), e->second);
	    }
	}

	swap(cur, nxt);
    }


    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}