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
char S[200011];

void MAIN() {
    scanf("%d%s", &N, S);

    LL left = 0, right = 0;
    REP (i, N) {
	if (S[0] == S[i]) {
	    left++;
	} else {
	    break;
	}
    }
    for (int i=N; i--;) {
	if (S[N-1] == S[i]) {
	    right++;
	} else {
	    break;
	}
    }


    LL ans = 0;
    if (S[0] == S[N-1]) {
	ans = (left + 1) * (right + 1);
    } else {
	ans = left + right + 1;
    }

    ans %= 998244353;
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}