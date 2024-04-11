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
char S[111];

void MAIN() {
    scanf("%s", S);

    int L = 0, R = 0;
    REP (i, 3) {
	L += S[i] - '0';
	R += S[i+3] - '0';
    }
    if (L > R) {
	REP (i, 3) swap(S[i], S[i+3]);
	swap(L, R);
    }

    int ans = 0;
    while (L != R) {
	int dl = 9 - (*min_element(S, S+3) - '0');
	int dr = *max_element(S+3, S+6) - '0';
	if (dl > dr) {
	    int g = min(R-L, dl);
	    *min_element(S, S+3) += g;
	    L += g;
	} else {
	    int g = min(R-L, dr);
	    *max_element(S+3, S+6) -= g;
	    R -= g;
	}

	ans++;
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}