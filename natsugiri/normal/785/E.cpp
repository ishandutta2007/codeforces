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

#define y0 TWILIGHT_SKY
#define y1 SPARKLING_GIRL

struct SegmentTree2D {
    typedef int Value;
    struct SegY {
	SegY *l, *r;
	Value v;
	int y0, y1; // [y0, y1];
	SegY() : l(nullptr), r(nullptr), v(0) {}
    };
    struct SegX {
	SegX *l, *r;
	SegY *y;
	int x0, x1; // [x0, x1];
	SegX() : l(nullptr), r(nullptr), y(nullptr) {}
    };

    SegX *root;

    SegmentTree2D() : root(nullptr) {}

    void build(pair<int, int> *p, int n) {
	sort(p, p+n);
	root = buildX(p, n);
    }

    SegX* buildX(pair<int, int> *p, int n) {
	if (n == 0) return nullptr;
	int cnt = 1;
	for (int i=1; i<n; i++) if (p[i-1].first != p[i].first) cnt++;

	SegX *seg = new SegX();
	seg->x0 = p[0].first; seg->x1 = p[n-1].first;
	if (cnt > 1) {
	    int half = 1;
	    for (int i=1; i<n; i++) if (p[i-1].first != p[i].first) {
		if (half * 2 >= cnt) { half = i; break; }
		half++;
	    }
	    seg->l = buildX(p, half);
	    seg->r = buildX(p+half, n - half);
	}
	sort(p, p+n, bySecond);
	seg->y = buildY(p, n);
	return seg;
    }

    SegY* buildY(pair<int, int> *p, int n) {
	if (n == 0) return nullptr;
	int cnt = 1;
	for (int i=1; i<n; i++) if (p[i-1].second != p[i].second) cnt++;

	SegY *seg = new SegY();
	seg->y0 = p[0].second; seg->y1 = p[n-1].second;
	if (cnt > 1) {
	    int half = 1;
	    for (int i=1; i<n; i++) if (p[i-1].second != p[i].second) {
		if (half * 2 >= cnt) { half = i; break; }
		half++;
	    }
	    seg->l = buildY(p, half);
	    seg->r = buildY(p+half, n - half);
	}
	return seg;
    }

    int x0, y0, x1, y1;
    Value v;
    void add(int x, int y, Value v_) {
	x0 = x; y0 = y;
	v = v_;
	addX(root);
    }

    void addX(SegX *seg) {
	if (!seg) return;
	if (seg->x0 <= x0 && x0 <= seg->x1) {
	    addY(seg->y);
	    addX(seg->l); addX(seg->r);
	}
    }
    void addY(SegY *seg) {
	if (!seg) return;
	if (seg->y0 <= y0 && y0 <= seg->y1) {
	    seg->v += v;
	    addY(seg->l); addY(seg->r);
	}
    }

    Value sum(int x0_, int y0_, int x1_, int y1_) {
	x0 = x0_; y0 = y0_; x1 = x1_; y1 = y1_;
	v = 0;
	sumX(root);
	return v;
    }
    void sumX(SegX *seg) {
	if (!seg) return;
	if (x0 <= seg->x0 && seg->x1 <= x1) { sumY(seg->y); return; }
	if (x1 < seg->x0 || seg->x1 < x0) return;
	sumX(seg->l); sumX(seg->r);
    }
    void sumY(SegY *seg) {
	if (!seg) return;
	if (y0 <= seg->y0 && seg->y1 <= y1) { v += seg->v; return; }
	if (y1 < seg->y0 || seg->y1 < y0) return;
	sumY(seg->l); sumY(seg->r);
    }

    struct BySecond {
	template<class T, class U> bool operator()(const pair<T, U> &x, const pair<T, U> &y) const {
	    return x.second < y.second;
	}
    };
    static BySecond bySecond;
};


int N, Q;
int L[50111], R[50111];
int A[200111];
vector<pair<int, int> > P;

int main() {
    scanf("%d%d", &N, &Q);
    REP (i, Q) {
	scanf("%d%d", L+i, R+i);
	L[i]--; R[i]--;
    }

    P.reserve(N + Q + Q);
    REP (i, N) {
	A[i] = i;
	P.emplace_back(i, i);
    }
    REP (i, Q) {
	swap(A[L[i]], A[R[i]]);
	P.emplace_back(L[i], A[L[i]]);
	P.emplace_back(R[i], A[R[i]]);
    }

    SegmentTree2D ST;
    ST.build(&P[0], P.size());

    LL ans = 0;
    REP (i, N) {
	A[i] = i;
	ST.add(i, i, 1);
    }
    REP (i, Q) {
	int l = L[i], r = R[i];

	if (l != r) {
	    if (l > r) swap(l, r);
	    int tmp = ST.sum(l+1, min(A[l], A[r]), r-1, max(A[l], A[r]));
	    tmp = tmp * 2 + 1;
	    if (A[l] < A[r]) ans += tmp;
	    else ans -= tmp;

	    ST.add(l, A[l], -1);
	    ST.add(l, A[r], +1);
	    ST.add(r, A[r], -1);
	    ST.add(r, A[l], +1);
	    swap(A[l], A[r]);
	}
	printf("%lld\n", ans);
    }

    return 0;
}