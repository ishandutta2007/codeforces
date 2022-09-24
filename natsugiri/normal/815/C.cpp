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
VI G[5011];
LL B;
LL C[5011], D[5011];
int X[5011];

LL dp_c[5011][5011];
LL dp_d[5011][5011];

int sz[5011];


void MAIN() {
    scanf("%d%lld", &N, &B);
    REP (i, N) {
	if (i == 0) scanf("%lld%lld", C+i, D+i);
	else scanf("%lld%lld%d", C+i, D+i, X+i), X[i]--;
    }

    for (int i=1; i<N; i++) G[X[i]].push_back(i);

    memset(dp_c, 0x3f, sizeof dp_c);
    memset(dp_d, 0x3f, sizeof dp_d);
    vector<pair<int, int> > ch(N);

    REP (i_, N) {
	int v = N-1-i_;
	sz[v] = 1;
	dp_c[v][0] = 0;
	dp_c[v][1] = C[v];
	dp_d[v][1] = C[v] - D[v];


	ch.clear();
	EACH (e, G[v]) {
	    ch.emplace_back(sz[*e], *e);
	}

	sort(ch.begin(), ch.end());

	EACH (e, ch) {
	    int w = e->second;

	    for (int i=sz[v]; i>=0; i--) {
		for (int j=1; j<=sz[w]; j++) {
		    amin(dp_c[v][i+j], dp_c[v][i] + dp_c[w][j]);

		    amin(dp_d[v][i+j], dp_d[v][i] + dp_c[w][j]);
		    amin(dp_d[v][i+j], dp_d[v][i] + dp_d[w][j]);
		}
	    }
	    sz[v] += sz[w];
	}
    }


    int ans = 0;
    REP (i, N+1) {
	if (dp_c[0][i] <= B) ans = i;
	if (dp_d[0][i] <= B) ans = i;
    }

    printf("%d\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}