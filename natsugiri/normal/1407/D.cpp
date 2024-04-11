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
int H[300011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", H+i);
    vector<pair<int, int> > inc, dec;

    inc.emplace_back(H[0], 0);
    dec.emplace_back(H[0], 0);

    for (int i=1; i<N; i++) {
	int val = 1<<29;
	while (!inc.empty() && inc.back().first > H[i]) {
	    amin(val, inc.back().second + 1);
	    inc.pop_back();
	}
	if (!inc.empty()) {
	    amin(val, inc.back().second + 1);
	    if (inc.back().first == H[i]) inc.pop_back();
	}

	while (!dec.empty() && dec.back().first < H[i]) {
	    amin(val, dec.back().second + 1);
	    dec.pop_back();
	}
	if (!dec.empty()) {
	    amin(val, dec.back().second + 1);
	    if (dec.back().first == H[i]) dec.pop_back();
	}

	inc.emplace_back(H[i], val);
	dec.emplace_back(H[i], val);
    }

    printf("%d\n", inc.back().second);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}