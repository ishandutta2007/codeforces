#include<queue>
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

int N, M;
bool A[411][411];
int G[411];

int bfs() {
    queue<int> qu;
    memset(G, 0x3f, sizeof G);
    G[0] = 0;
    qu.push(0);
    while (!qu.empty()) {
	int v = qu.front();
	qu.pop();
	REP (i, N) if (A[v][i] && G[i] > G[v] + 1) {
	    G[i] = G[v] + 1;
	    qu.push(i);
	}
    }
    return G[N-1];
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, M) {
	int x, y;
	scanf("%d%d", &x, &y);
	x--; y--;
	A[x][y] = A[y][x] = true;
    }

    int x = bfs();
    REP (i, N) REP (j, N) A[i][j] = !A[i][j];
    int y = bfs();

    if (x == G[N] || y == G[N]) {
	puts("-1");
    } else {
	printf("%d\n", max(x, y));
    }
    
    
    return 0;
}