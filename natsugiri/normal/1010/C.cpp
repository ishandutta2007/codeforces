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

LL gcd(LL x, LL y) {
    while (1) {
	if (x) y %= x; else return y;
	if (y) x %= y; else return x;
    }
}

int N, K;
int A[100011];

void MAIN() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i);

    int g = 0;
    REP (i, N) {
	g = gcd(g, A[i] % K);
    }

    VI ans;
    if (g == 0) {
	ans.push_back(0);
    } else {
	g = gcd(g, K);
	for (int t=0; t<K; t+=g) {
	    ans.push_back(t);
	}
    }

    printf("%d\n", (int)ans.size());
    rprintf("%d", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}