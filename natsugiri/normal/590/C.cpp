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

const int dy[] = { 0, 1, 0, -1 };;
const int dx[] = { 1, 0, -1, 0 };;

int N, M;
char F[1011][1011];
int D[3][1011][1011];
int A[3][3];
int INF;

bool in(int y,int x) {
    return 0 <= y && y < N && 0 <= x && x < M; 
}
void dist(int c_) {
    char c = c_ + '1';
    queue<int> qX, qY;
    
    REP (i, N) REP (j, M) {
	if (F[i][j] == c) {
	    D[c_][i][j] = 0;
	    qY.push(i);
	    qX.push(j);
	}
    }

    while (!qX.empty()) {
	int y = qY.front(); qY.pop();
	int x = qX.front(); qX.pop();
	REP (d, 4) {
	    int yy = y + dy[d];
	    int xx = x + dx[d];
	    if (in(yy, xx) && F[yy][xx] != '#' && D[c_][yy][xx] > D[c_][y][x] + 1) {
		D[c_][yy][xx] = D[c_][y][x] + 1;
		qX.push(xx);
		qY.push(yy);
	    }
	}
    }
}

int main() {
    scanf("%d%d", &N, &M);
    REP (i, N) scanf("%s", F[i]);

    memset(D, 0x3f, sizeof D);
    memset(A, 0x3f, sizeof A);
    memset(&INF, 0x3f, sizeof INF);
    
    REP (i, 3) dist(i);

    REP (f, 3) REP (t, 3) {
	REP (i, N) REP (j, M) if (F[i][j] == t+'1')
	    amin(A[f][t], D[f][i][j]);
    }
    
    int ans = INF;
    if (A[0][1] != INF && A[1][2] != INF) amin(ans, A[0][1] + A[1][2] - 2);
    if (A[0][2] != INF && A[2][1] != INF) amin(ans, A[0][2] + A[2][1] - 2);
    if (A[1][0] != INF && A[0][2] != INF) amin(ans, A[1][0] + A[0][2] - 2);

    REP (i, N) REP (j, M) {
	LL tmp = 0;
	REP (g, 3) tmp += D[g][i][j];
	if (tmp < INF) amin(ans, (int)tmp-2);;
    }

    if (ans == INF) ans = -1;
    printf("%d\n", ans);
    return 0;
}