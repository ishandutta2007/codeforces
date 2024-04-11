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
char S[100111];

int main() {
    scanf("%s", S);
    N = strlen(S);

    int sh = count(S, S+N, '#');
    int o = count(S, S+N, '(');
    int c = count(S, S+N, ')');

    int cur = 0;
    bool yes = true;
    VI ans(sh, 1);
    ans.back() = o - c - (sh - 1);
    int pos = 0;
    if (ans.back() < 1) yes = false;

    REP (i, N) {
	if (S[i] == '(') {
	    cur++;
	} else if (S[i] == ')') {
	    cur--;
	    if (cur < 0) yes = false;
	} else {
	    cur -= ans[pos];
	    pos++;
	    if (cur < 0) yes = false;
	}
    }

    if (cur != 0) yes = false;

    if (yes) {
	REP (i, ans.size()) printf("%d\n", ans[i]);
    } else {
	puts("-1");
    }

    return 0;
}