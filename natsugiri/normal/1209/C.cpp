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
char S[200011];
char C[200011];

void MAIN() {
    scanf("%d%s", &N, S);

    REP (t, 10) {
	bool f = false;
	REP (i, N) {
	    if (S[i]-'0' < t) {
		C[i] = '1';
	    } else if (t < S[i]-'0') {
		C[i] = '2';
		f = true;
	    } else if (f) {
		C[i] = '1';
	    } else {
		C[i] = '2';
	    }
	}

	bool yes = true;
	int p = 0;
	for (int x=1; x<=2; x++) {
	    REP (i, N) if (C[i]-'0' == x) {
		if (S[i]-'0' < p) yes = false;
		amax(p, S[i]-'0');
	    }
	}

	if (yes) {
	    C[N] = 0;
	    puts(C);
	    return;
	}
    }

    puts("-");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}