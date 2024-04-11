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
LL L, R;
LL A[100111];
LL B[100111];
int P[100111];
int rev[100111];


int main() {
    scanf("%d%lld%lld", &N, &L, &R);
    REP (i, N) scanf("%lld", A+i);
    REP (i, N) {
	scanf("%d", P+i);
	P[i]--;
	rev[P[i]] = i;
    }

    LL last = -(1LL<<60);
    bool yes = true;
    REP (y, N) {
	int i = rev[y];
	LL g = max(last + A[i] + 1, L);
	if (g > R) {
	    yes = false;
	    break;
	}
	B[i] = g;
	last = g - A[i];
    }

    if (yes) {
	rprintf("%lld", B, B+N);
    } else {
	puts("-1");
    }

    return 0;
}