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
VI G[100111];
int sz[100111];
double dp[100111];

int main() {
    scanf("%d", &N);
    REP (i, N-1) {
	int p;
	scanf("%d", &p);
	G[p-1].push_back(i+1);
    }

    VI ord; ord.reserve(N);
    ord.push_back(0);
    REP (i, N) {
	int v = ord[i];
	EACH (e, G[v]) ord.push_back(*e);
    }
    REP (i_, N) {
	int v = ord[N-1-i_];
	sz[v] = 1;
	EACH (e, G[v]) sz[v] += sz[*e];
    }
    REP (i_, N) {
	int v = ord[i_];
	dp[v] += 1.0;
	EACH (e, G[v]) dp[*e] += dp[v] + (sz[v] - 1 - sz[*e]) / 2.0;
    }
    rprintf("%f", dp, dp+N);


    return 0;
}