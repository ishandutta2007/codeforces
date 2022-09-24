#include<queue>
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


int N, M;
VI G[5001];
int mat[5001][5001];
int dist[5001][5001];
const int INF = 1<<29;
bool use[5001];

int len[5001];
void bfs(int s) {
    REP (i, N) len[i] = INF;
    queue<int> Q, L;
    Q.push(s);
    L.push(0);
    while (!Q.empty()) {
	int v = Q.front(); Q.pop();
	int l = L.front(); L.pop();
	EACH (e, G[v]) {
	    if (len[*e] > l + 1) {
		len[*e] = l + 1;
		Q.push(*e);
		L.push(len[*e]);
	    }
	}
    }
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) REP (j, N) mat[i][j] = INF;
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	G[x].push_back(y);
	mat[x][y] = 1;
    }

    REP (i, N) {
	bfs(i);
	REP (j, N) dist[i][j] = len[j];
    }

    int ans = N;
    REP (s, N) if (!use[s]) {
	int cycle = INF;
	REP (i, N) {
	    if (dist[s][i] < INF && dist[i][s] == INF) {
		cycle = INF;
		break;
	    }
	    if (i == s || (dist[i][s] != INF && dist[s][i] != INF)) {
		use[i] = true;
		amin(cycle, dist[i][i]);
	    }
	}

	if (cycle < INF) {
	    ans += 998 * cycle + 1;
	}
    }

    printf("%d\n", ans);
    
    return 0;
}