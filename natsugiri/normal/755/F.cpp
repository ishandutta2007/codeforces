#pragma GCC optimize("O3")
#pragma GCC target("sse4.2")
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

int N, K;
int A[1000111];
int C[1000111];
bool use[1000111];

bool dp[1000111];

int main() {
    scanf("%d%d", &N, &K);
    REP (i, N) scanf("%d", A+i), A[i]--;

    REP (i, N) if (!use[i]) {
	int cur = i;
	int cnt = 0;
	while (!use[cur]) {
	    cnt++;
	    use[cur] = true;
	    cur = A[cur];
	}

	C[cnt]++;
    }

    dp[0] = true;
    REP (d, N+1) {
	if (C[d] == 1) {
	    for (int i=N-d; i>=0; i--) if (dp[i]) dp[i+d] = true;
	} else if (C[d] == 2) {
	    for (int i=N-d; i>=0; i--) if (dp[i]) dp[i+d] = true;
	    for (int i=N-d; i>=0; i--) if (dp[i]) dp[i+d] = true;
	} else if (C[d] == 3) {
	    for (int i=N-d; i>=0; i--) if (dp[i]) dp[i+d] = true;
	    for (int i=N-d*2; i>=0; i--) if (dp[i]) dp[i+d*2] = true;
	} else if (C[d]) {
	    REP (i_, d) {
		int s = N-i_;
		int e = s;
		for (; e>=0;) {
		    if (dp[e]) {
			while (e <= s) {
			    dp[s] = true;
			    s -= d;
			}
		    }

		    e -= d;
		    while (s - e > (LL)C[d] * d) s -= d;
		}
	    }
	    if (dp[K]) break;
	}
    }

    int mi = (dp[K]? K: K+1);

    int cnt = 0, one = 0;
    REP (d, N+1) {
	cnt += d / 2 * C[d];
	one += d % 2 * C[d];
    }
    amin(cnt, K);

    int ma = cnt * 2 + min(one, (K - cnt));

    amin(ma, N); amax(ma, K);
    amin(mi, N); amax(mi, K);
    printf("%d %d\n", mi, ma);


    return 0;
}