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

const double EPS = 1e-7;

int K, Q;
pair<int, int> P[1011];
double dp[1111];
int ans[1111];

int main() {
    scanf("%d%d", &K, &Q);
    REP (i, Q) scanf("%d", &P[i].first), P[i].second = i;
    sort(P, P+Q);

    int cnt = 0;
    dp[0] = 1.0;
    double invK = 1.0 / K;
    REP (q, Q) {
	double pr = (P[q].first - EPS) / 2000.0;
	while (dp[K] < pr) {
	    cnt++;
	    for (int i=K; i--;) {
		dp[i+1] += dp[i] * (K-i) * invK;
		dp[i] = dp[i] * i * invK;
	    }
	}

	ans[P[q].second] = cnt;
    }

    REP (i, Q) printf("%d\n", ans[i]);

    return 0;
}