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

int W, N, M;
int C[1<<12];
int D[540000];
char S[111];

void MAIN() {
    scanf("%d%d%d", &W, &N, &M);
    REP (i, N) {
	int a;
	scanf("%d", &a);
	C[a]++;
    }
    REP (s, 1<<W) if (C[s]) {
	REP (t, 1<<W) {
	    int v = 0;
	    for (int k=W-1; k>=0; k--) {
		v *= 3;
		if (t>>k&1) v += 2;
		else if (s>>k&1) v += 1;
	    }
	    D[v] += C[s];
	}
    }

    REP ($, M) {
	scanf("%s", S);
	reverse(S, S+W);
	LL ans = 0;
	REP (s, 1<<W) if (C[s]) {
	    bool no = false;
	    int v = 0;
	    for (int k=W-1; k>=0; k--) {
		v *= 3;
		if (S[k] == 'X') {
		    v += (s>>k&1);
		} else if (S[k] == 'x') {
		    v += (~s>>k&1);
		} else if (S[k] == 'A') {
		    if (s>>k&1) {
		    } else {
			v += 2;
		    }
		} else if (S[k] == 'a') {
		    if (s>>k&1) {
			v += 1;
		    } else {
			no = true;
			break;
		    }
		} else if (S[k] == 'O') {
		    if (s>>k&1) {
			no = true;
			break;
		    } else {
		    }
		} else if (S[k] == 'o') {
		    if (s>>k&1) {
			v += 2;
		    } else {
			v += 1;
		    }
		}
	    }
	    if (!no) {
		ans += (LL)C[s] * D[v];
	    }
	}

	printf("%lld\n", ans);
    }

}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}