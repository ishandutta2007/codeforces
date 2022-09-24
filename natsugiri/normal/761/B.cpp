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

int N, L;
int A[1111];
int B[1111];
int C[1111];

int main() {
    scanf("%d%d", &N, &L);
    REP (i, N) scanf("%d", A+i);
    REP (i, N) scanf("%d", B+i);
    REP (i, N) C[A[i]]++;

    bool yes = false;

    REP (s, L+1) {
	bool all = true;
	REP (i, N) if (!C[(B[i] + s)%L]) { all = false; break; }
	if (all) {
	    yes = true;
	    break;
	}
    }

    puts(yes? "YES": "NO");

    return 0;
}