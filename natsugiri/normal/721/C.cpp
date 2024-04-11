#include<queue>
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
#define eprintf(s...)  fprintf(stderr, s)

template<class T> inline void amin(T &x, const T &y) { if (y<x) x=y; }
template<class T> inline void amax(T &x, const T &y) { if (x<y) x=y; }
typedef LL Cost; // (>), (+), INF, ZERO=Cost()
const Cost INF = 1ll<<59;
struct Edge {
    int src, dst;
    Cost cst;
    bool operator<(const Edge &y) const {
	return cst > y.cst; // reversed
    }
};
typedef vector<Edge> Edges;
typedef vector<Edges> Graph;


int N, M, T;
Graph G;
int dp[5011][5011];
int deg[5011];
short from[5011][5011];

int main() {
    scanf("%d%d%d", &N, &M, &T);
    G = Graph(N);

    REP (i, M) {
	int x, y, c;
	scanf("%d%d%d", &x, &y, &c);
	x--; y--;
	G[x].push_back((Edge){ x, y, c });
	deg[y]++;
    }

    // memset(dp, 0x3f, sizeof dp);
    REP (i, N) REP (j, N+1) dp[i][j] = T + 1;

    queue<int> qu;
    dp[0][1] = 0;
    REP (i, N) if (deg[i] == 0) qu.push(i);
    while (!qu.empty()) {
	int v = qu.front(); qu.pop();
	EACH (e, G[v]) {
	    deg[e->dst]--;
	    if (deg[e->dst] == 0) qu.push(e->dst);
	}

	REP (i, N) if (dp[v][i] <= T) EACH (e, G[v]) {
	    LL c = dp[v][i] + e->cst;
	    if (dp[e->dst][i+1] > c) {
		dp[e->dst][i+1] = c;
		from[e->dst][i+1] = v;
	    }
	}
    }


    int pos = N-1, cnt = 0;
    REP (i, N+1) if (dp[N-1][i] <= T) {
	cnt = i;
    }

    VI ans;
    while (pos != 0) {
	ans.push_back(pos);
	pos = from[pos][cnt];
	cnt--;
    }
    ans.push_back(0);
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    REP (i, ans.size()) printf("%d%c", ans[i] + 1, i == (int)ans.size() - 1? '\n': ' ');


    return 0;
}