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

string S, T;
char buf[100011];
int nxt[100011][26];

void MAIN() {
    scanf("%s", buf);
    S = buf;
    scanf("%s", buf);
    T = buf;

    REP (c, 26) nxt[S.size()][c] = S.size();
    for (int i=S.size(); i--;) {
	REP (c, 26) nxt[i][c] = nxt[i+1][c];
	nxt[i][S[i]-'a'] = i;
    }

    bool yes = true;
    int ans = 0;
    int pos = S.size();
    REP (i, T.size()) {
	int c = T[i] - 'a';
	if (nxt[0][c] >= (int)S.size()) {
	    yes = false;
	    break;
	}
	if (nxt[pos][c] >= (int)S.size()) {
	    ans++;
	    pos = 0;
	}
	pos = nxt[pos][c] + 1;
    }

    if (yes) printf("%d\n", ans);
    else puts("-1");
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}