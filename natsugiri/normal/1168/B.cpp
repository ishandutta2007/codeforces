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
char S[300011];
int X[300011];
int H[300011];

void MAIN() {
    scanf("%s", S);
#ifdef LOCAL
    N = 5;
    REP (i, N) S[i] = '0';
    S[N] = 0;
#endif

    N = strlen(S);
    memset(H, 0x3f, sizeof H);

    REP (s, 2) {
	for (char c='0'; c<='1'; c++) {
	    int len = 0;
	    for (int i=s; i<N; i+=2) if (S[i] == c) {
		X[len++] = i;
	    }
	    int left = 0;
	    for (int i=s; i<N; i+=2) if (S[i] == c) {
		while (left < len && X[left] <= i) left++;
		// S[i], S[(i+X[j])/2], S[X[j]];
		for (int j=left; j<len; j++) if (S[(i+X[j])/2] == c) {
		    H[i] = X[j];
		    break;
		}
	    }
	}
    }
    for (int i=N; i--;) amin(H[i], H[i+1]);

    LL ans = 0;
    REP (i, N) if (H[i] < N) {
	ans += N-H[i];
    }
    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}