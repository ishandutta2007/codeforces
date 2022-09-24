#include<cstdio>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cstring>
using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)
#define eprintf(s...) fprintf(stderr, s)

template<class T> inline void amin(T &a, const T &b) { if (b<a) a=b; }
template<class T> inline void amax(T &a, const T &b) { if (a<b) a=b; }

int N;
VI G[200111];
LL X, Y;

int dp[200111][3];
void rec(int v, int p) {
    EACH (e, G[v]) if (*e != p) {
	rec(*e, v);

	int buf[3] = {};

	REP (i, 3) amax(buf[0], dp[*e][i]);
	buf[1] = buf[2] = buf[0];
	REP (i, 3) buf[i] += dp[v][i];
	
	amax(buf[2], dp[v][1] + dp[*e][1] + 1);
	amax(buf[2], dp[v][1] + dp[*e][0] + 1);
	
	REP (i, 2) amax(buf[1], dp[v][0] + dp[*e][i] + 1);
	REP (i, 3) amax(dp[v][i], buf[i]);
    }
}

int main() {
    scanf("%d%lld%lld", &N, &X, &Y);
    REP (i, N-1) {
	int a, b;
	scanf("%d%d", &a, &b);
	a--; b--;
	G[a].push_back(b);
	G[b].push_back(a);
    }

    int d = 0;
    REP (i, N) amax<int>(d, G[i].size());
    LL ans;
    if (d == N-1) ans = Y*(N-2) + X;
    else ans = Y*(N-1);

    rec(0, 0);
    int k = 0;
    REP (i, 3) amax(k, dp[0][i]);
    // REP (i, 3) eprintf("%d ", dp[0][i]); eprintf("\n");
    amin(ans, k*X + (N-1-k)*Y);
    printf("%lld\n", ans);
    
    return 0;
}