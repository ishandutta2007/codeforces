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
char S[100111], T[100111];
VI G[100111];
int par[100111];
bool dp[100111][2];

int main() {
    scanf("%d", &N);
    REP (i, N-1) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	G[y].push_back(x);
    }

    REP (i, N) scanf("%s", S+i);
    REP (i, N) scanf("%s", T+i);

    VI ans;
    VI ord; ord.reserve(N);
    ord.push_back(0);
    REP (i_, N) {
	int v = ord[i_];
	S[v] ^= dp[v][0];
	if (S[v] != T[v]) {
	    ans.push_back(v+1);
	    dp[v][0] ^= 1;
	}
	EACH (e, G[v]) if (*e != par[v]) {
	    ord.push_back(*e);
	    par[*e] = v;
	    dp[*e][0] ^= dp[v][1];
	    dp[*e][1] ^= dp[v][0];
	}
    }

    printf("%d\n", (int)ans.size());
    EACH (e, ans) printf("%d\n", *e);

    return 0;
}