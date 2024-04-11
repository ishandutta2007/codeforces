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

/*
A -> XX
X -> AX
AAA -> .

X -> A* X

*/

int N, M;
int Q;
char S[100011];
char T[100011];
int sumsS[100011];
int sumsT[100011];

void MAIN() {
    scanf("%s", S);
    scanf("%s", T);
    N = strlen(S);
    M = strlen(T);
    REP (i, N) sumsS[i+1] = sumsS[i] + (S[i] == 'A'? 0: 1);
    REP (i, M) sumsT[i+1] = sumsT[i] + (T[i] == 'A'? 0: 1);
    scanf("%d", &Q);
    REP ($, Q) {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	a--; c--;

	int cntS = sumsS[b] - sumsS[a];
	int cntT = sumsT[d] - sumsT[c];
	int botS = lower_bound(sumsS+a, sumsS+N+1, sumsS[b]) - sumsS;
	int botT = lower_bound(sumsT+c, sumsT+M+1, sumsT[d]) - sumsT;

	int laS = botS - a - cntS;
	int laT = botT - c - cntT;
	int raS = b - botS;
	int raT = d - botT;

	bool yes = false;

	if (raS == raT) {
	    if (cntS == 0) {
		// AAA -> AAA
		if (cntS == cntT && laS == laT) yes = true;
		// AAA -> XAAA
		// no
	    } else {
		// XAAA -> AAA
		// no
		//
		// AXAAA -> AXXXAAA
		if (cntS <= cntT && (cntT-cntS) % 2 == 0) yes = true;
	    }
	} else if (raS > raT) {
	    // AAA -> XXAA
	    if (cntS < cntT && (cntT-cntS) % 2 == 0) yes = true;
	    
	    // XAAA -> X
	    if (cntS == cntT && raS % 3 == raT % 3) yes = true;
	}
	putchar(yes? '1': '0');
    }
    puts("");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}