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

int N, K;
char S[200011];

bool ok() {
    for (int i=K; i<N; i++) {
	if (S[i] < S[i-K]) return true;
	if (S[i] > S[i-K]) return false;
    }
    return true;
}

void MAIN() {
    scanf("%d%d%s", &N, &K, S);

    if (!ok()) {
	for (int i=K-1; i>=0; i--) {
	    if (S[i] != '9') {
		S[i]++;
		break;
	    } else {
		S[i] = '0';
	    }
	}
    }
    for (int i=K; i<N; i++) {
	S[i] = S[i-K];
    }
    printf("%d\n", N);
    puts(S);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}