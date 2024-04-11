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

void MAIN() {
    scanf("%d", &N);

    bool first;
    if (N == 1) first = false;
    else if (N == 2) first = true;
    else if (N % 2 == 1) first = true;
    else {
	int two = 0;
	while (N % 2 == 0) {
	    N /= 2;
	    two++;
	}

	int cnt = 0;
	for (int p=3; p*p<=N; p+=2) {
	    while (N % p == 0) {
		cnt++;
		N /= p;
	    }
	}
	if (N > 1) cnt++;

	if (cnt == 0) {
	    // 4 8 16
	    assert(two >= 2);
	    first = false;
	} else if (two >= 2) {
	    first = true;
	} else {
	    if (cnt == 1) first = false;
	    else first = true;
	}
    }

    puts(first? "Ashishgup": "FastestFinger");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}