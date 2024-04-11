#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

int N;
char S[200011];
int nxt[200011][26];
int Q;

bool three(int l, int r) {
    int cnt = 0;
    REP (c, 26) {
	if (nxt[l][c] < r) {
	    cnt++;
	    if (cnt >= 3) return true;
	}
    }

    return false;
}

void MAIN() {
    scanf("%s", S);
    N = strlen(S);
    scanf("%d", &Q);

    REP (c, 26) nxt[N][c] = N;
    for (int i=N; i--;) {
	REP (c, 26) nxt[i][c] = nxt[i+1][c];
	nxt[i][S[i]-'a'] = i;
    }


    REP ($, Q) {
	int l, r;
	scanf("%d%d", &l, &r);
	l--;

	bool yes;
	if (r-l == 1) {
	    yes = true;
	} else if (S[l] != S[r-1]) {
	    yes = true;
	} else if (three(l, r)) {
	    yes = true;
	} else {
	    yes = false;
	}
	puts(yes? "Yes": "No");
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}