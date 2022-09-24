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

int R, C, K;
char S[111][111];
int E[111];

char name(int i) {
    if (i < 10) return i + '0';
    i -= 10;
    if (i < 26) return i + 'A';
    i -= 26;
    return i + 'a';
}

void MAIN() {
    scanf("%d%d%d", &R, &C, &K);
    REP (i, R) scanf("%s", S[i]);

    int rice = 0;
    REP (i, R) rice += count(S[i], S[i] + C, 'R');
    REP (i, K) E[i] = rice / K + (i < rice % K? 1: 0);

    int id = 0;
    REP (i, R) {
	int j, dj;
	if (i % 2 == 0) {
	    j = 0;
	    dj = 1;
	} else {
	    j = C-1;
	    dj = -1;
	}
	for (; 0 <= j && j < C; j += dj) {
	    if (S[i][j] == 'R') {
		S[i][j] = name(id);
		E[id]--;
		if (E[id] == 0 && id+1 < K) id++;
	    } else {
		S[i][j] = name(id);
	    }
	}
    }
    REP (i, R) puts(S[i]);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}