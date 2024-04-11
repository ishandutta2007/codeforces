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

int N;
int K;

int R[505][505];
int D[505][505];

struct Data { 
    int r1, c1, r2, c2;
    Data() {}

    void read() {
	scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
	r1--;
	c1--;
	r2--;
	c2--;
    }

    void normal() {
	if (r1 > r2 || c1 > c2) {
	    swap(r1, r2);
	    swap(c1, c2);
	}
    }

    void go() {
	normal();

	if (r1 == r2) {
	    D[r1][c2]++;
	    D[K-1-r2][K-1-c1]++;
	} else {
	    R[r2][c1]++;
	    R[K-1-r1][K-1-c2]++;
	}
    }
};

vector<Data> V;

int dist[260011];

int solve() {
    int SIZE = K+1;

    REP (i, SIZE) {
	memset(R[i], 0, sizeof (int) * SIZE);
	memset(D[i], 0, sizeof (int) * SIZE);
    }

    REP (i, V.size()) V[i].go();

    priority_queue<pair<int, int> >  Q;
    memset(dist, 0x3f, sizeof (int) * SIZE * SIZE);
    for (int j=1; j<K; j++) {
	dist[j] = 0;
	Q.emplace(0, j);
    }

    while (!Q.empty()) {
	int cst = -Q.top().first;
	int v = Q.top().second;
	Q.pop();
	if (dist[v] != cst) continue;

	int i = v / SIZE;
	int j = v % SIZE;

	if (i && i != K && j+1 < K && dist[v+1] > cst + R[i][j]) {
	    dist[v+1] = cst + R[i][j];
	    Q.emplace(-dist[v+1], v+1);
	}
	if (i && i != K && j >= 2 && dist[v-1] > cst + R[i][j-1]) {
	    dist[v-1] = cst + R[i][j-1];
	    Q.emplace(-dist[v-1], v-1);
	}

	if (i+1 < K && 1 <= j && j <= K && dist[v+SIZE] > cst + D[i][j]) {
	    dist[v+SIZE] = cst + D[i][j];
	    Q.emplace(-dist[v+SIZE], v+SIZE);
	}

	if (i >= 2 && 1 <= j && j <= K && dist[v-SIZE] > cst + D[i-1][j]) {
	    dist[v-SIZE] = cst + D[i-1][j];
	    Q.emplace(-dist[v-SIZE], v-SIZE);
	}
    }


    return dist[(K/2)*SIZE+ K/2];
}

void MAIN() {
    scanf("%d%d", &N, &K);
    V.resize(N);
    REP (i, N) {
	V[i].read();
    }

    int ans = solve();

    REP (i, V.size()) {
	swap(V[i].r1, V[i].c1);
	swap(V[i].r2, V[i].c2);
    }

    int tmp = solve();
    amin(ans, tmp);
    printf("%d\n", N - ans);
}

int main() {
    int TC = 1;
    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}