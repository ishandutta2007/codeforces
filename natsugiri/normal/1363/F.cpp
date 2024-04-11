#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define NDEBUG
#define eprintf(...) do {} while (0)
#endif
#include<cassert>

using namespace std;

typedef long long LL;
typedef vector<int> VI;

#define REP(i,n) for(int i=0, i##_len=(n); i<i##_len; ++i)
#define EACH(i,c) for(__typeof((c).begin()) i=(c).begin(),i##_end=(c).end();i!=i##_end;++i)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
template<class Iter> void rprintf(const char *fmt, Iter begin, Iter end) {
    for (bool sp=0; begin!=end; ++begin) { if (sp) putchar(' '); else sp = true; printf(fmt, *begin); }
    putchar('\n');
}

// matchM[v] = u  <=> mathcW[u] = v
// O(E sqrt(V));
struct Matching2 { // for bipartite graph
    static const int INF = 1<<29;
    const VI* G;
    VI matchM, matchW, dist;
    int ans;
    int SNK;

    bool dfs(int v) {
	if (v == SNK) return true;
	EACH (e, G[v]) if (dist[matchW[*e]] == dist[v]+1 && dfs(matchW[*e])) {
	    matchM[v] = *e;
	    matchW[*e] = v;
	    return true;
	}
	dist[v] = INF;
	return false;
    }

    Matching2(const VI G_[], int sizeM, int sizeW): G(G_), matchM(sizeM, -1), matchW(sizeW, sizeM), dist(sizeM+1), ans(0), SNK(sizeM) {
	VI qu; qu.reserve(sizeM+1);
	while (1) {
	    dist[SNK] = INF;
	    REP (i, sizeM) {
		if (matchM[i] == -1) { dist[i] = 0; qu.push_back(i); }
		else dist[i] = INF;
	    }
	    for (int i=0; i<(int)qu.size(); i++) {
		int v = qu[i];
		if (dist[v] < dist[SNK]) {
		    EACH (e, G[v]) if (dist[matchW[*e]] == INF) {
			dist[matchW[*e]] = dist[v] + 1;
			qu.push_back(matchW[*e]);
		    }
		}
	    }
	    if (dist[SNK] == INF) break;
	    qu.clear();
	    REP (i, sizeM) if (matchM[i] == -1 && dfs(i)) ans++;
	}
	REP (i, sizeW) if (matchW[i] == SNK) matchW[i] = -1;
    }
};

int N;
string S, T;
char buf[2011];

int Ssum[2011][26];
int Tsum[2011][26];

const int INF = 0x3f3f3f3f;
int dp[2011][2011];

void MAIN() {
    scanf("%d", &N);
    scanf("%s", buf);
    S = buf;
    scanf("%s", buf);
    T = buf;

    REP (c, 26) {
	if (count(S.begin(), S.end(), 'a' + c) != count(T.begin(), T.end(), 'a' + c)) {
	    puts("-1");
	    return;
	}
    }

    REP (i, N) {
	REP (c, 26) {
	    Ssum[i+1][c] = Ssum[i][c];
	    Tsum[i+1][c] = Tsum[i][c];
	}
	Ssum[i+1][S[i]-'a']++;
	Tsum[i+1][T[i]-'a']++;
    }

    REP (i, N+1) REP (j, N+1) dp[i][j] = INF;
    dp[0][0] = 0;

    REP (i, N+1) REP (j, N+1) {
	if (i < N && j < N && S[i] == T[j]) {
	    amin(dp[i+1][j+1], dp[i][j]);
	}
	if (i < N && Ssum[i][S[i]-'a'] < Tsum[j][S[i]-'a']) {
	    amin(dp[i+1][j], dp[i][j] + 1);
	}
	amin(dp[i][j+1], dp[i][j]);
    }

    int ans = dp[N][N];
    printf("%d\n", ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}