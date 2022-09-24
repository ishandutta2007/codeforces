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

bool P[10][50];

bool check(int n, int k) {
    REP (a, n+1) {
	int s = a + (n-a)*50;
	if (k == s) return true;
    }
    return false;
}

void MAIN() {
    scanf("%d", &N);
    LL ans = 0;
    for (int i5=0; i5<9; i5++) {
	for (int i10=0; i10<49; i10++) {
	    int t = 5*i5+10*i10;
	    // t, (i5+i10, i5, i10)

	    bool yes = true;
	    for (int s=0; s<i5+i10; s++) {
		REP (a, s+1) {
		    int b = s - a;
		    if (5*a+10*b > t) continue;
		    if (check(i5+i10-s, t-5*a-10*b)) {
			yes = false;
			break;
		    }
		}
		if (!yes) break;
	    }
	    if (!yes) continue;

	    {
		int s = i5+i10;
		REP (a, s) {
		    int b = s - a;
		    if (i5 < a) continue;
		    if (i5 == a && i10 <= b) continue;
		    if (5*a+10*b > t) continue;
		    if (check(i5+i10-s, t-5*a-10*b)) {
			yes = false;
			break;
		    }
		}
		if (!yes) continue;
	    }


	    LL rest = N - i5 - i10;
	    if (rest >= 0) {
		ans += rest + 1;
	    }
	}
    }

    printf("%lld\n" ,ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}