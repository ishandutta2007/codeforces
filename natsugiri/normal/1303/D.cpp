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

LL K;
int NUM;
int B[60];

void MAIN() {
    scanf("%lld%d", &K, &NUM);
    memset(B, 0, sizeof B);
    LL sum = 0;
    REP (i, NUM) {
	int x;
	scanf("%d", &x);
	B[__lg(x)]++;
	sum += x;
    }
    if (sum < K) {
	puts("-1");
    } else {
	LL ans = 0;
	REP (t, 50) {
	    if ((K>>t&1) && B[t] == 0) {
		for (int i=t+1; i<60; i++) if (B[i]) {
		    for (; i>t; i--) {
			B[i]--;
			B[i-1] += 2;
			ans++;
		    }
		    break;
		}
	    }

	    if (K>>t&1) {
		assert(B[t]);
		B[t]--;
	    }
	    B[t+1] += B[t]/2;
	}

	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}