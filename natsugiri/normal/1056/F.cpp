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
double C, T;
pair<int, int> ap[111];


const int MAXN = 105;
const int SIZE = 1011;

double dp[MAXN][SIZE];

const double INF = 1e100;
const double EPS = 1e-8;

void MAIN() {
    scanf("%d%lf%lf", &N, &C, &T);
    REP (i, N) scanf("%d%d", &ap[i].first, &ap[i].second);

    sort(ap, ap+N);

    REP (i, N+1) REP (j, N*10+1) dp[i][j] = INF;
    dp[0][0] = 0;

    REP (i, N) {
	for (int j=i; j>=0; j--) REP (s, j*10+1) if (dp[j][s] < INF) {
	    amin(dp[j+1][s + ap[i].second], (dp[j][s] + ap[i].first) * 10.0 / 9.0);
	}
    }

    int ans = 0;
    REP (j, N+1) REP (s, j*10+1) {
	int e = j*10;
	double alpha = C;
	double beta = 1 + C*e - C*T;
	double gamma = dp[j][s] + e - T;

	double x = max(-beta / alpha / 2, 0.0);
	if (alpha*x*x + beta*x + gamma <= EPS) {
	    amax(ans, s);
	}
    }
    printf("%d\n", ans);


}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}