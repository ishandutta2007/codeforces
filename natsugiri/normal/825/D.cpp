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

int N, TN;
char S[1000111];
char T[1000111];

int cntS[26], cntT[26], Q;

void MAIN() {
    scanf("%s%s", S, T);
    N = strlen(S);
    TN = strlen(T);

    REP (i, N) {
	if (S[i] != '?') cntS[S[i]-'a']++;
	else Q++;
    }
    REP (i, TN) cntT[T[i]-'a']++;

    int lo = 0, hi = N / TN + 10;
    while (hi - lo > 1) {
	LL mid = (lo + hi) / 2;
	LL need = 0;
	REP (i, 26) {
	    need += max(cntT[i] * mid - cntS[i], 0LL);
	}

	(need <= Q? lo: hi) = (int)mid;
    }

    REP (i, 26) cntT[i] = max(cntT[i] * lo - cntS[i], 0);

    REP (i, N) if (S[i] == '?') {
	char c = 'a';
	REP (k, 26) if (cntT[k]) {
	    c = k + 'a';
	    cntT[k]--;
	    break;
	}
	S[i] = c;
    }

    puts(S);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}