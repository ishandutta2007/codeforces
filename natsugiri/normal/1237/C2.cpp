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

struct Data {
    int x, y, z, i;
    Data(){}
    Data(int x_, int y_, int z_, int i_) {
	x = x_;
	y = y_;
	z = z_;
	i = i_;
    }
    bool operator<(const Data &o) const {
	return x != o.x ? x < o.x :
	    y != o.y ? y < o.y :
	    z < o.z;
    }
} D[50011];

int N;

void check() {
#ifdef LOCAL
    for (int i=0; i<N; i+=2) {
	Data a = D[i];
	Data b = D[i+1];
	for (int j=i+2; j<N; j++) {
	    Data c = D[j];
	    if (min(a.x, b.x) <= c.x && c.x <= max(a.x, b.x)
		    && min(a.y, b.y) <= c.y && c.y <= max(a.y, b.y)
		    && min(a.z, b.z) <= c.z && c.z <= max(a.z, b.z)) {
		printf("%d %d %d\n", a.x, a.y, a.z);
		printf("%d %d %d\n", b.x, b.y, b.z);
		printf("%d %d %d\n", c.x, c.y, c.z);
		assert(false);
	    }
	}
    }
#endif
}

LL sq(LL x) { return x * x; }
LL dist(const Data &a, const Data &b) {
    return sq(a.x - b.x) + sq(a.y - b.y) + sq(a.z - b.z);
}

void move_best(const Data p, int L, int R) {
    LL d = 1LL<<60;
    int best = L;
    for (int i=L; i<R; i++) {
	LL tmp = dist(p, D[i]);
	if (tmp < d) {
	    d = tmp;
	    best = i;
	}
    }
    while (L < best) {
	swap(D[best-1], D[best]);
	best--;
    }
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	D[i] = Data(x, y, z, i);
    }

    sort(D, D+N);
    bool prv = false;
    for (int x0=0; x0<N; ) {
	int x1 = x0;
	while (x1 < N && D[x0].x == D[x1].x) x1++;
	if (prv) {
	    move_best(D[x0-1], x0, x1);
	    x0++;
	    prv = false;
	}

	for (int y0=x0; y0<x1; ) {
	    int y1 = y0;
	    while (y1 < x1 && D[y0].y == D[y1].y) y1++;
	    if (prv) {
		move_best(D[y0-1], y0, y1);
		y0++;
		prv = false;
	    }
	    while (y0+2 <= y1) y0 += 2;
	    if (y0 < y1) {
		prv = true;
		y0 = y1;
	    }
	}
	x0 = x1;
    }


    for (int i=0; i<N; i+=2) {
	printf("%d %d\n", D[i].i+1, D[i+1].i+1);
    }

    //check();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}