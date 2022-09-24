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

VI G[100011];
bool girl[100011];
bool boy[100011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	G[i].clear();
	girl[i] = boy[i] = 0;
    }

    REP (i, N) {
	int len;
	scanf("%d", &len);
	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    G[i].push_back(x);
	}
    }

    REP (i, N) {
	EACH (e, G[i]) if (!boy[*e]) {
	    girl[i] = boy[*e] = true;
	    break;
	}
    }

    REP (i, N) if (!girl[i]) {
	REP (j, N) if (!boy[j]) {
	    puts("IMPROVE");
	    printf("%d %d\n", i+1, j+1);
	    return;
	}
    }

    puts("OPTIMAL");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}