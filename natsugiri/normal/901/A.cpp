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

int H;
int A[200111];
int P[200111];

void MAIN() {
    scanf("%d", &H);
    REP (i, H+1) scanf("%d", A+i);
    int N = 0;
    REP (i, H+1) N += A[i];
    REP (i, H) {
	if (A[i] > 1 && A[i+1] > 1) {
	    puts("ambiguous");
	    
	    int cur = 1;
	    P[0] = -1;
	    for (int k=1; k<=H; k++) P[cur++] = k-1;
	    for (int k=1; k<=H; k++) REP (t, A[k]-1) P[cur++] = k-1;
	    REP (j, N) P[j]++;
	    rprintf("%d", P, P+N);
	    REP (j, N) P[j]--;

	    int r = 0;
	    for (int j=H+1; j<N; j++) if (P[j] == i-1) { r = j; break; }
	    for (int j=H+1; j<N; j++) if (P[j] == i) { P[j] = r; break; }
	    REP (j, N) P[j]++;
	    rprintf("%d", P, P+N);

	    return;
	}
    }

    puts("perfect");
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}