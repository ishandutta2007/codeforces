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

int N, P;
char S[2011];

void MAIN() {
    scanf("%d%d", &N, &P);
    scanf("%s", S);

    REP (i, N-P) if (S[i] == '.' || S[i+P] == '.') {
	if (S[i] == '0' || S[i+P] == '1') {
	    S[i] = '0';
	    S[i+P] = '1';
	} else {
	    S[i] = '1';
	    S[i+P] = '0';
	}
    }
    REP (i, N) if (S[i] == '.') S[i] = '0';


    bool yes = false;
    REP (i, N-P) if (S[i] != S[i+P]) yes = true;

    if (yes) {
	puts(S);
    } else {
	puts("No");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}