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
char S[11111];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", S);


    bool yes;
    if (N == 1) {
	yes = (S[0] == '1');
    } else {
	bool adj = false;
	REP (i, N-1) {
	    if (S[i] == '1' && S[i+1] == '1') adj = true;
	}

	bool triple = false;
	REP (i, N-2) {
	    if (S[i] == '0' && S[i+1] == '0' && S[i+2] == '0') triple = true;
	}
	yes = (S[0] != S[1]) && (S[N-1] != S[N-2]) && !adj && !triple;
    }
    puts(yes? "Yes": "No");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}