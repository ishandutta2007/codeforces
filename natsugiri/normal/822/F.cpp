#include<cmath>
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
int A[111], B[111];
VI G[111];
int to(int v, int i) {
    int k = G[v][i];
    return A[k]^B[k]^v;
}
double ans[111];
void dfs(int v, int p, double ad) {
    int m = G[v].size();
    REP (i, m) {
	int w = to(v, i);
	if (w == p) continue;
	int id = G[v][i];
	if (ans[id] != -1) {
	    ans[id] = fmod(ans[id] + ad, 2.0);
	    dfs(w, v, ad);
	}
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N-1) {
	int u, v;
	scanf("%d%d", &u, &v);
	u--; v--;
	A[i] = u; B[i] = v;
	G[u].push_back(i);
	G[v].push_back(i);
	ans[i] = -1;
    }

    REP (v, N) {
	int m = G[v].size();
	REP (i, m) {
	    int w = to(v, i);
	    int id = G[v][i];
	    double p = 2.0  * i / m;
	    if (B[id] == v) {
		p += 1.0;
	    }

	    if (ans[id] != -1) {
		dfs(w, v, 2.0 + p - ans[id]);
	    }
	    ans[id] = fmod(p, 2.0);
	}
    }

    printf("%d\n", N-1);
    REP (i, N-1) {
	ans[i] = fmod(ans[i], 2.0);
	if (ans[i] >= 1.0) {
	    printf("1 %d %d %d %.9f\n", i+1, B[i]+1, A[i]+1, ans[i] - 1.0);
	} else {
	    printf("1 %d %d %d %.9f\n", i+1, A[i]+1, B[i]+1, ans[i]);
	}
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}