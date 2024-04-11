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
const int MAXN = 80;
const int INF = 0x3f3f3f3f;
char S[MAXN + 11];
int dp[MAXN][MAXN][MAXN][3];
int sumsV[MAXN], sumsK[MAXN], sumsO[MAXN];
VI posV, posK, posO;

int main() {
    scanf("%d%s", &N, S);

    memset(dp, 0x3f, sizeof dp);
    REP (i, N) {
	sumsV[i+1] = sumsV[i];
	sumsK[i+1] = sumsK[i];
	sumsO[i+1] = sumsO[i];
	(S[i] == 'V'? sumsV[i+1]: (S[i] == 'K'? sumsK[i+1]: sumsO[i+1]))++;
	(S[i] == 'V'? posV: (S[i] == 'K'? posK: posO)).push_back(i);
    }

    dp[0][0][0][2] = 0;
    int V = sumsV[N];
    int K = sumsK[N];
    int O = sumsO[N];
    REP (v, V+1) REP (k, K+1) REP (o, O+1) {
	if (v < V) {
	    int pos = posV[v];
	    int remK = max(0, sumsK[pos] - k);
	    int remO = max(0, sumsO[pos] - o);
	    REP (i, 3) amin(dp[v+1][k][o][0], dp[v][k][o][i] + remK + remO);
	}

	if (k < K) {
	    int pos = posK[k];
	    int remV = max(0, sumsV[pos] - v);
	    int remO = max(0, sumsO[pos] - o);
	    REP (i, 2) amin(dp[v][k+1][o][1], dp[v][k][o][i+1] + remV + remO);
	}

	if (o < O) {
	    int pos = posO[o];
	    int remV = max(0, sumsV[pos] - v);
	    int remK = max(0, sumsK[pos] - k);
	    REP (i, 3) amin(dp[v][k][o+1][2], dp[v][k][o][i] + remV + remK);
	}
    }


    int ans = INF;
    REP (i, 3) amin(ans, dp[V][K][O][i]);

    printf("%d\n", ans);


    return 0;
}