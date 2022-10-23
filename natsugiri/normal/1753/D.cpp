#pragma GCC optimize ("O3")
#pragma GCC target ("sse4")
#pragma GCC optimize("unroll-loops")
#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<queue>

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
#define rprintf(fmt, begin, end) do { const auto end_rp = (end); auto it_rp = (begin); for (bool sp_rp=0; it_rp!=end_rp; ++it_rp) { if (sp_rp) putchar(' '); else sp_rp = true; printf(fmt, *it_rp); } putchar('\n'); } while(0)

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};

int H, W;
LL P, Q;

char buf[300011];
string S[300011];
vector<LL> D[300011];
const LL INF = 1LL<<60;

bool in(int y, int x) {
    return 0 <= y && y < H && 0 <= x && x < W;
}

struct Data {
    int y, x;
    LL cst;
    Data() {}
    Data(int y_, int x_, LL cst_): y(y_), x(x_), cst(cst_) {}

    bool operator<(const Data &o) const {
	return cst > o.cst;
    }
};

void MAIN() {
    scanf("%d%d%lld%lld", &H, &W, &P, &Q);
    REP (i, H) {
	scanf("%s", buf);
	S[i] = buf;
    }

    REP (i, H) D[i].assign(W, INF);

    priority_queue<Data> pq;

    REP (i, H) REP (j, W) if (S[i][j] == '.') {
	D[i][j] = 0;
	pq.emplace(i, j, 0);
    }

    while (!pq.empty()) {
	int y = pq.top().y;
	int x = pq.top().x;
	LL cst = pq.top().cst;
	pq.pop();
	
	if (D[y][x] != cst) continue;

	REP (d, 4) {
	    int y1 = y + dy[d];
	    int x1 = x + dx[d];
	    if (in(y1, x1) && isalpha(S[y1][x1])) {
		int y2 = y1, x2 = x1;
		if (S[y1][x1] == 'L') x2 = x1 + 1;
		if (S[y1][x1] == 'R') x2 = x1 - 1;
		if (S[y1][x1] == 'U') y2 = y1 + 1;
		if (S[y1][x1] == 'D') y2 = y1 - 1;
		
		if (x == x2 && y == y2) continue;

		LL add;
		if (x == x2 || y == y2) add = Q;
		else add = P;

		if (D[y2][x2] > D[y][x] + add) {
		    D[y2][x2] = D[y][x] + add;
		    pq.emplace(y2, x2, D[y2][x2]);
		}
	    }
	}
    }

    LL ans = INF;
    REP (i, H) REP (j, W) {
	if (i + 1 < H) amin(ans, D[i][j] + D[i+1][j]);
	if (j + 1 < W) amin(ans, D[i][j] + D[i][j+1]);
    }
    if (ans == INF) {
	puts("-1");
    } else {
	printf("%lld\n", ans);
    }
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}