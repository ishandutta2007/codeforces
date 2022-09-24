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
int A[1011];


int nxt[8][11][1011];
void build() {
    memset(nxt, -1, sizeof nxt);
    int t[8];
    REP (k, 8) t[k] = -1;
    for (int i=N; i--;) {
	REP (k, 8) nxt[k][0][i] = t[k];
	t[A[i]] = i;
    }

    REP (k, 8) REP (z, 10) REP (i, N) {
	int p = nxt[k][z][i];
	if (p != -1) p = nxt[k][z][p];
	nxt[k][z+1][i] = p;
    }
}

int next_pos(int cur, int val, int len) {
    if (len <= 0) return cur;
    if (cur <= -1 || cur >= N) return -1;

    if (A[cur] == val) len--;

    REP (z, 11) if (len & (1 << z)) {
	cur = nxt[val][z][cur];
	if (cur == -1) return -1;
    }
    return cur+1;
}



int dp[1011][1<<8];
// 10 1000 8 256 10
int calc(int m) { // m or m+1
    memset(dp, -1, sizeof dp);

    dp[0][0] = 0;

    REP (i, N+1) {
	REP (k, 8) {
	    int p = next_pos(i, k, m);
	    if (p != -1) {
		REP (S, 1<<8) if (~S & (1<<k) && dp[i][S] != -1) {
		    amax(dp[p][S | (1<<k)], dp[i][S] + m);
		}

		if (p < N) {
		    int q = next_pos(p, k, 1);
		    if (q != -1) {
			REP (S, 1<<8) if (~S & (1<<k) && dp[i][S] != -1) {
			    amax(dp[q][S | (1<<k)], dp[i][S] + m + 1);
			}
		    }
		}
	    }
	}
    }

    int ans = -1;
    REP (i, N+1) amax(ans, dp[i][(1<<8)-1]);
    return ans;
}


int main() {
    scanf("%d", &N);
    REP (i, N) scanf("%d", A+i), A[i]--;

    build();
    
    int lo = 0, hi = N + 10;
    while (hi - lo > 1) {
	int m = (lo + hi) / 2;
	int tmp = calc(m);
	(tmp <= -1? hi: lo) = m;
    }

    int ans = calc(lo);

    printf("%d\n", ans);

    return 0;
}