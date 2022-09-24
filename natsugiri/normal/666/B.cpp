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

int N, M;
int D[3001][3001];
int E[5001], F[5001];
VI G[3001];

int from[3001][4], to[3001][4];


int main() {
    scanf("%d%d", &N, &M);

    REP (i, M) {
	scanf("%d%d", E+i, F+i);
	E[i]--; F[i]--;
	G[E[i]].push_back(F[i]);
    }

    memset(D, 0x3f, sizeof D);
    VI ord; ord.reserve(N);
    REP (s, N) {
	ord.clear();
	ord.push_back(s);
	D[s][s] = 0;
	for (int i=0; i<(int)ord.size(); i++) {
	    int v = ord[i];
	    EACH (e, G[v]) if (D[s][*e] > N) {
		D[s][*e] = D[s][v] + 1;
		ord.push_back(*e);
	    }
	}
    }

    REP (s, N) {
	REP (i, 3) from[s][i] = to[s][i] = s;
	REP (v, N) {
	    if (D[v][s] <= N) {
		from[s][3] = v;
		for (int i=3; i--; ) 
		    if (D[from[s][i]][s] < D[from[s][i+1]][s]) 
			swap(from[s][i], from[s][i+1]);
	    }

	    if (D[s][v] <= N) {
		to[s][3] = v;
		for (int i=3; i--; ) 
		    if (D[s][to[s][i]]< D[s][to[s][i+1]])
			swap(to[s][i], to[s][i+1]);
	    }
	}
    }


    int best = 0;
    int ans[4] = {};

    REP (s, N) REP (t, N) if (s != t && D[s][t] <= N) {
	REP (i, 3) if (from[s][i] != s && from[s][i] != t) {
	    REP (j, 3) if (to[t][j] != s && to[t][j] != t && to[t][j] != from[s][i]) {
		int tmp = D[from[s][i]][s] + D[s][t] + D[t][to[t][j]];
		if (best < tmp) {
		    best = tmp;
		    ans[0] = from[s][i] + 1;
		    ans[1] = s + 1;
		    ans[2] = t + 1;
		    ans[3] = to[t][j] + 1;
		}
	    }
	}
    }

    rprintf("%d", ans, ans + 4);

    return 0;
}