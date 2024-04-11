#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

int N, K;
LL X;
char S[2011];

void MAIN() {
    scanf("%d%d%lld", &N, &K, &X);
    X--;
    scanf("%s", S);

    vector<int> V;
    int cnt = 0;
    REP (i, N) {
	if (S[i] == '*') cnt++;
	else {
	    if (cnt) V.push_back(cnt);
	    cnt = 0;
	}
    }
    if (cnt) V.push_back(cnt);

    for (int i=V.size(); i--;) {
	int m = V[i] * K + 1;
	LL r = X % m;
	V[i] = r;
	
	X /= m;
    }
    assert(X == 0);

    int z = 0;
    cnt = 0;
    REP (i, N) {
	if (S[i] == '*') cnt++;
	else {
	    if (cnt) {
		REP (j, V[z]) putchar('b');
		z++;
	    }
	    putchar('a');
	    cnt = 0;
	}
    }
    if (z < (int)V.size()) {
	REP (j, V[z]) putchar('b');
    }
    putchar('\n');
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}