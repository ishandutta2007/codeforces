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

int N, M, K;
char F[1011][1011];
int H[26][1011][1011];
LL Hs[26][1011][1011];
LL G[1011][1011];
int C[26];

struct Photo {
    int a, b, c, d;
    char e;
    Photo(){}
    Photo(int a_, int b_, int c_, int d_, char e_) :
	a(a_), b(b_), c(c_), d(d_), e(e_) {}
} P[300111];

int main() {
    scanf("%d%d%d", &N, &M, &K);
    REP (i, N) scanf("%s", F[i]);

    REP ($, K) {
	int a, b, c, d;
	char e[9];
	scanf("%d%d%d%d%s", &a, &b, &c, &d, e);
	a--; b--;
	H[*e - 'a'][a][b]++;
	H[*e - 'a'][a][d]--;
	H[*e - 'a'][c][b]--;
	H[*e - 'a'][c][d]++;
	P[$] = Photo(a, b, c, d, *e);
    }

    REP (t, 26) REP (i, N+1) REP (j, M+1) H[t][i][j+1] += H[t][i][j];
    REP (t, 26) REP (i, N+1) REP (j, M+1) H[t][i+1][j] += H[t][i][j];

    REP (i, N) REP (j, M) {
	int re = K;
	REP (t, 26) {
	    C[t] = H[t][i][j];
	    re -= H[t][i][j];
	}
	C[F[i][j] - 'a'] += re;
	LL cst = 0;
	REP (t, 26) cst += llabs(t - (F[i][j]-'a')) * C[t];

	G[i+1][j+1] = cst;
	REP (t, 26) Hs[t][i+1][j+1] += C[t];
    }

    REP (t, 26) REP (i, N+2) REP (j, M+2) 
	Hs[t][i+1][j+1] += Hs[t][i][j+1] + Hs[t][i+1][j] - Hs[t][i][j];


    REP (i, N+2) REP (j, M+2) {
	G[i][j+1] += G[i][j];
	G[i+1][j] += G[i][j];
	G[i+1][j+1] -= G[i][j];
    }



    LL ans = 1LL<<60;

    REP (k, K) {
	LL base = G[N][M];
	int a, b, c, d;
	a = P[k].a;
	b = P[k].b;
	c = P[k].c;
	d = P[k].d;
	char e = P[k].e;
	base -= G[a][b] - G[a][d] - G[c][b] + G[c][d];
	REP (t, 26) {
	    LL cnt = Hs[t][a][b] - Hs[t][a][d] - Hs[t][c][b] + Hs[t][c][d];

	    base += llabs(t - (e - 'a')) * cnt;
	}

	amin(ans, base);
    }

    printf("%lld\n", ans);

    return 0;
}