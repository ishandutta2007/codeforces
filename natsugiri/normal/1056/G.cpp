#include<cassert>
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

LL N, M, S;
LL T;

LL skip[60][100011];
LL level[100011];

LL go(LL s, LL t) {
    if (s < M) return (s + t) % N;
    else return (s - t + N) % N;
}

void MAIN() {
    scanf("%lld%lld%lld%lld", &N, &M, &S, &T);
    S--;

    // memset(skip, -1, sizeof skip);

    while (T%N) {
	S = go(S, T%N);
	T--;
    }
    memset(level, 0, sizeof level);

    while (T) {
	if (level[S] == 0) {
	    LL cur = S;
	    for (LL i=N-1; i>=1; i--) {
		cur = go(cur, i);
	    }
	    skip[0][S] = cur;
	    level[S] = 1;
	} else {
	    LL l = level[S] - 1;
	    skip[l+1][S] = skip[l][skip[l][S]];
	    level[S]++;
	}

	LL l = 0;
	while (l + 1 < level[S] && ((LL)N<<(l+1))<=T) l++;
	S = skip[l][S];
	T -= (LL)N<<l;
    }
    printf("%lld\n", S+1);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}