#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(...) fprintf(stderr, __VA_ARGS__)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
int A, B;
LL H[200011], D[200011];

void MAIN() {
    scanf("%d%d%d", &N, &A, &B);
    REP (i, N) scanf("%lld%lld", H+i, D+i);

    LL base = 0;
    vector<pair<LL, LL> > v;
    REP (i, N) {
	base += D[i];

	LL diff1 = max(0LL, H[i] - D[i]);
	LL diff2 = max(0LL, (H[i]<<A) - D[i]);
	if (diff2 > 0) v.emplace_back(diff1, diff2);
    }

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    LL add = 0;
    for (int i=0; i<B && i<(int)v.size(); i++) {
	add += v[i].first;
    }

    LL ans = base + add;
    if (B) {
	REP (i, v.size()) {
	    LL guess;
	    if (i < B) guess = add - v[i].first + v[i].second;
	    else guess = add - v[B-1].first + v[i].second;

	    guess += base;
	    amax(ans, guess);
	}
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}