#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
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

int N;

bool good(char *A) {
    int c = 0;
    REP (i, N) {
	if (A[i] == '(') c++;
	else c--;
	if (c < 0) return false;
    }
    return c == 0;
}

char S[200011];
char A[200011];
char B[200011];

void MAIN() {
    scanf("%d%s", &N, S);

    int one = count(S, S+N, '1');
    int zero = N - one;

    bool yes = true;
    if (one % 2 == 0 && zero % 2 == 0) {
	int cone = 0;
	int czero = 0;

	REP (i, N) {
	    if (S[i] == '1') {
		if (cone * 2 < one) {
		    A[i] = B[i] = '(';
		} else {
		    A[i] = B[i] = ')';
		}
		cone++;
	    } else {
		if (czero % 2 == 0) {
		    A[i] = '(';
		    B[i] = ')';
		} else {
		    A[i] = ')';
		    B[i] = '(';
		}
		czero++;
	    }
	}

	if (!good(A)) yes = false;
	if (!good(B)) yes = false;
    } else {
	yes = false;
    }

    if (yes) {
	puts("YES");
	A[N] = B[N] = 0;
	puts(A);
	puts(B);
    } else {
	puts("NO");
    }
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}