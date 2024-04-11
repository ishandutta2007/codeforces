#include<stack>
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
int K[2], S[2][7077];

int dp[2][7077];
int buf[2][7077];
int ans[2][7077];

int main() {
    scanf("%d", &N);
    REP (t, 2) {
	scanf("%d", K+t);
	REP (i, K[t]) scanf("%d", S[t]+i);
    }

    REP (t, 2) {
	int e = 1 - t;

	memset(dp, 0, sizeof dp);
	memset(buf, 0, sizeof buf);
	dp[0][0] = 1;
	dp[1][0] = -1;
	stack<int, VI> st;
	st.push(0);
	st.push(1);
	while (!st.empty()) {
	    int v = st.top(); st.pop();
	    int k = v & 1; v >>= 1;

	    if (k == 0) {
		if (dp[0][v] == 1) {
		    REP (i, K[t]) {
			int w = (v + S[t][i]) % N;
			if (dp[1][w] == 0) {
			    dp[1][w] = 1;
			    st.push(w << 1 | 1);
			}
		    }
		}

		if (dp[0][v] == -1) {
		    REP (i, K[t]) {
			int w = (v + S[t][i]) % N;
			buf[1][w]++;
			if (buf[1][w] == K[t] && dp[1][w] == 0) {
			    dp[1][w] = -1;
			    st.push(w << 1 | 1);
			}
		    }
		}
	    } else {
		if (dp[1][v] == -1) {
		    REP (i, K[e]) {
			int w = (v + S[e][i]) % N;
			if (dp[0][w] == 0) {
			    dp[0][w] = -1;
			    st.push(w << 1);
			}
		    }
		}

		if (dp[1][v] == 1) {
		    REP (i, K[e]) {
			int w = (v + S[e][i]) % N;
			buf[0][w]++;
			if (buf[0][w] == K[e] && dp[0][w] == 0) {
			    dp[0][w] = 1;
			    st.push(w << 1);
			}
		    }
		}
	    }
	}

	REP (v, N) ans[t][v] = dp[1][v];
    }

    REP (t, 2) {
	for (int i_=1; i_<N; i_++) {
	    int i = N - i_;

	    printf("%s%c", ans[t][i]==1 ? "Win": ans[t][i]==-1 ? "Lose" : "Loop",
		    i_==N-1?'\n':' ');
	}
    }
    return 0;
}