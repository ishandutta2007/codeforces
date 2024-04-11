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
char S[100111];
int dp[100111][3];
bool pre[100111][3];

int main() {
    scanf("%s", S);
    N = strlen(S);
    
    memset(dp, 0xc0, sizeof dp);
    REP (i, N) {
	int c = (S[i] - '0') % 3;
	if (S[i] != '0' && dp[i+1][c] < 1) {
	    dp[i+1][c] = 1;
	    pre[i+1][c] = true;
	}
	REP (d, 3) if (dp[i][d] >= 0) {
	    if (dp[i+1][d] < dp[i][d]) {
		dp[i+1][d] = dp[i][d];
		pre[i+1][d] = false;
	    }
	    int nd = (d + c) % 3;
	    if (dp[i+1][nd] < dp[i][d] + 1) {
		dp[i+1][nd] = dp[i][d] + 1;
		pre[i+1][nd] = true;
	    }
	}
    }

    string ans;
    if (dp[N][0] < 0) {
	if (find(S, S+N, '0') == S+N) ans = "-1";
	else ans = "0";
    } else {
	int c = 0;
	for (int i=N; i; i--) {
	    if (pre[i][c]) {
		ans.push_back(S[i-1]);
		c = (c - (S[i-1] - '0') + 33) % 3;
	    }
	}
	reverse(ans.begin(), ans.end());
    }
    puts(ans.c_str());

    return 0;
}