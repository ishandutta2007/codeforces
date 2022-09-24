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
}

LL sq(LL x) { return x * x; }

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y, z;
	scanf("%d%d%d", &x, &y, &z);
	D[i] = Data(x, y, z, i);
    }

    for (int i=0; i<N; i+=2) {
	LL d = 1LL<<60;
	int best = i+1;
	for (int j=i+1; j<N; j++) {
	    LL tmp = sq(D[i].x - D[j].x) + sq(D[i].y - D[j].y) + sq(D[i].z - D[j].z);
	    if (tmp < d) {
		d = tmp;
		best = j;
	    }
	}
	swap(D[i+1], D[best]);
    }

    for (int i=0; i<N; i+=2) {
	printf("%d %d\n", D[i].i+1, D[i+1].i+1);
    }

    check();
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}