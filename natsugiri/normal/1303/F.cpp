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

const int dy[] = {0, 1, 0, -1};
const int dx[] = {1, 0, -1, 0};
struct UnionFind {
    int n, cc, *u;
    UnionFind() : n(0), cc(0), u(NULL) {}
    UnionFind(int n_) : n(n_), cc(n_) {
	u = new int[n_];
	memset(u, -1, sizeof (int) * n);
    }
    UnionFind(const UnionFind &y) : n(y.n), cc(y.cc) {
	u = new int[y.n];
	memcpy(u, y.u, sizeof (int) * n);
    }
    ~UnionFind() {
	delete[] u; u = NULL;
	n = cc = 0;
    }
    friend void swap(UnionFind &x, UnionFind &y) {
	swap(x.n, y.n); swap(x.cc, y.cc); swap(x.u, y.u);
    }
    UnionFind& operator=(UnionFind y) { 
	swap(*this, y);
	return *this;
    }
    void init() {
	cc = n;
	memset(u, -1, sizeof (int) * n);
    }
    int root(int x) {
	int y = x, t;
	while (u[y] >= 0) y = u[y];
	while (x != y) { t = u[x]; u[x] = y; x = t; }
	return y;
    }
    bool link(int x, int y) {
	x = root(x); y = root(y);
	if (x == y) return false;
	if (u[y] < u[x]) swap(x, y);
	u[x] += u[y]; u[y] = x; cc--;
	return true;
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -u[root(x)]; }
    int count() { return cc; }
};

int N, M;
int Q;
vector<pair<int, int> > H[311][311]; // (time, color);

bool in(int y, int x) {
    return 0 <= y && y < N && 0 <= x && x < M;
}

struct Data {
    int y, x;
    int start, end;
    Data(){}
    Data(int y_, int x_, int start_, int end_) {
	y = y_;
	x = x_;
	start = start_;
	end = end_;
    }
};
vector<Data> C[2000011];

struct ByStart {
    bool operator()(const Data &a, const Data &b) const {
	return a.start < b.start;
    }
} byStart;

struct ByEndRev {
    bool operator()(const Data &a, const Data &b) const {
	return a.end > b.end;
    }
} byEndRev;

int F[2000011];
int name[311][311];
int mark[311][311];

void MAIN() {
    scanf("%d%d%d", &N, &M, &Q);
    REP (i, N) REP (j, M) H[i][j].emplace_back(0, 0);

    REP (i, Q) {
	int x, y, c;
	scanf("%d%d%d", &y, &x, &c);
	x--; y--;
	if (H[y][x].back().second != c) {
	    H[y][x].emplace_back(i+1, c);
	}
    }

    REP (y, N) REP (x, M) {
	REP (k, H[y][x].size()) {
	    int start = H[y][x][k].first;
	    int color = H[y][x][k].second;
	    int end;
	    if (k+1 == (int)H[y][x].size()) end = Q+1;
	    else end = H[y][x][k+1].first;

	    C[color].emplace_back(y, x, start, end);
	}
    }

    int marker = 0;
    REP (color, 2000011) if (!C[color].empty()) {
	auto V = C[color];
	int mid = V[0].end;
	EACH (e, V) amin(mid, e->end);

	// TASK 1;
	sort(V.begin(), V.end(), byStart);

	int cc = 0;
	int cnt = 0;
	marker++;
	UnionFind U(V.size());

	for (int z=0; z<(int)V.size(); ) {
	    int i = z;
	    while (i < (int)V.size() && V[z].start == V[i].start) {
		int y = V[i].y, x = V[i].x;
		name[y][x] = cnt++;
		cc++;
		mark[y][x] = marker;
		REP (d, 4) {
		    int yy = y + dy[d];
		    int xx = x + dx[d];
		    if (in(yy, xx) && mark[yy][xx] == marker) {
			if (!U.same(name[y][x], name[yy][xx])) {
			    U.link(name[y][x], name[yy][xx]);
			    cc--;
			}
		    }
		}

		i++;
	    }

	    int end;
	    if (i == (int)V.size()) end = mid;
	    else end = V[i].start;
	    F[V[z].start] += cc;
	    F[end] -= cc;
	    z = i;
	}

	int cc_task_1 = cc;

	// TASK 2;
	sort(V.begin(), V.end(), byEndRev);
	cc = 0;
	cnt = 0;
	marker++;
	U.init();

	for (int z=0; z<(int)V.size(); ) {
	    int i = z;
	    while (i < (int)V.size() && V[z].end == V[i].end) {
		int y = V[i].y, x = V[i].x;
		name[y][x] = cnt++;
		cc++;
		mark[y][x] = marker;
		REP (d, 4) {
		    int yy = y + dy[d];
		    int xx = x + dx[d];
		    if (in(yy, xx) && mark[yy][xx] == marker) {
			if (!U.same(name[y][x], name[yy][xx])) {
			    U.link(name[y][x], name[yy][xx]);
			    cc--;
			}
		    }
		}

		i++;
	    }

	    int start;
	    if (i == (int)V.size()) start = mid;
	    else start = V[i].end;
	    F[start] += cc;
	    F[V[z].end] -= cc;
	    z = i;
	}

	assert(cc_task_1 == cc);
    }

    REP (i, Q+1) F[i+1] += F[i];
    for (int i=1; i<=Q; i++) printf("%d\n", F[i]);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}