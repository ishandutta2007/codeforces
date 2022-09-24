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

int N;
LL L, R;
VI ans;

void MAIN() {
    scanf("%d%lld%lld", &N, &L, &R);
    L--;

    ans.clear();
    LL pos = 0;
    for (int i=1; i<N; i++) {
	if (pos < R && L < pos + (N - i)*2) {
	    for (int j=i+1; j<=N; j++) {
		if (L <= pos && pos < R) ans.push_back(i);
		pos++;
		if (L <= pos && pos < R) ans.push_back(j);
		pos++;
	    }
	} else {
	    pos += (N - i)*2;
	}
    }

    if (R-L != (int)ans.size()) ans.push_back(1);
    pos++;
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}