#include<bitset>
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

using Bits = bitset<10048>;

int M, N;
Bits D[50], S[50];

void MAIN() {
    scanf("%d%d", &M, &N);
    REP (i, M) {
	int len;
	scanf("%d", &len);
	REP (j, len) {
	    int x;
	    scanf("%d", &x);
	    x--;
	    D[i].set(x);
	}
	REP (j, N) if (!D[i].test(j)) S[i].set(j);
    }

    bool yes = true;
    REP (i, M) REP (j, M) if (yes && i != j) {
	if ((D[i] & S[j]) == D[i]) yes = false;
    }
    puts(yes? "possible": "impossible");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}