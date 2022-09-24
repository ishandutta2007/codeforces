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

const string P[6][2] = {
    {"AG", "CT"},
    {"AC", "GT"},
    {"AT", "GC"},
    {"GC", "AT"},
    {"GT", "AC"},
    {"CT", "AG"},
};

int ord(char c) {
    if (c == 'A') return 0;
    if (c == 'G') return 1;
    if (c == 'C') return 2;
    if (c == 'T') return 3;
    return 4;
}


void solve(vector<string> &F, int &ans) {
    int N = F.size();
    int M = F[0].size();

    int best_t = -1;
    ans = 1<<29;

    REP (t, 6) {
	int cost = 0;
	REP (i, N) {
	    const string &pat = P[t][i&1];
	    int line_cost = 1<<29;
	    REP (a, 2) {
		int tmp = 0;
		REP (j, M) {
		    tmp += (int)(F[i][j] != pat[(j+a)&1]);
		}
		amin(line_cost, tmp);
	    }

	    cost += line_cost;
	}

	if (ans > cost) {
	    ans = cost;
	    best_t = t;
	}
    }

    {
	REP (i, N) {
	    const string &pat = P[best_t][i&1];
	    int tmp[2] = {};
	    REP (a, 2) {
		REP (j, M) {
		    tmp[a] += (int)(F[i][j] != pat[(j+a)&1]);
		}
	    }

	    int a = (tmp[0] > tmp[1]? 1: 0);
	    REP (j, M) F[i][j] = pat[(j+a)&1];
	}
    }
}

int N, M;

vector<string> F, G;
char buf[300111];

void MAIN() {
    scanf("%d%d", &N, &M);

    F.resize(N);
    REP (i, N) {
	scanf("%s", buf);
	F[i] = buf;
    }

    G.assign(M, string(N, '.'));
    REP (i, N) REP (j, M) G[j][i] = F[i][j];

    int f_cost, g_cost;
    solve(F, f_cost);
    solve(G, g_cost);

    if (g_cost < f_cost) {
	REP (i, N) REP (j, M) F[i][j] = G[j][i];
    }

    REP (i, N) puts(F[i].c_str());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}