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

int N, M;
int P[5011];
int C[5011];
int K[5011], D;

bool leave[5011];

VI G[5011];

bool use[5011], act[5011];
int match[5011];

int ans[5011];

bool dfs(int v) {
    if (use[v]) return false;
    use[v] = true;
    for (int i=0; i<(int)G[v].size(); i++) {
	int u = G[v][i];
	if (match[u] == -1 || dfs(match[u])) {
	    match[u] = v;
	    return true;
	}
    }
    return false;
}

void MAIN() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%d", P+i);
    REP (i, N) scanf("%d", C+i), C[i]--;

    scanf("%d", &D);
    REP (j, D) {
	scanf("%d", K+j);
	K[j]--;
	leave[K[j]] = true;
    }
    REP (i, N) if (!leave[i]) {
	// P[i] -> C[i];
	G[P[i]].push_back(C[i]);
    }

    memset(match, -1, sizeof match);
    int power = 0;
    for (int j=D; j--;) {
	memset(use, 0, sizeof use);
	while (dfs(power)) {
	    power++;
	    memset(use, 0, sizeof use);
	}
	ans[j] = power;

	int i = K[j];
	G[P[i]].push_back(C[i]);
    }
    REP (j, D) printf("%d\n", ans[j]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}