#pragma GCC optimize ("O3")
// #pragma GCC target ("avx")
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

struct IntPoint {
    LL x, y;
    IntPoint() {
	x = y = 0;
    }
    IntPoint(LL x_, LL y_) {
	x = x_;
	y = y_;
    }

    IntPoint& operator+=(const IntPoint &r) {
	x += r.x;
	y += r.y;
	return *this;
    }
    IntPoint& operator-=(const IntPoint &r) {
	x -= r.x;
	y -= r.y;
	return *this;
    }
    IntPoint& operator*=(const IntPoint &r) {
	return *this = *this * r;
    }
    IntPoint operator-() const {
	return IntPoint(-x, -y);
    }
    friend IntPoint operator+(IntPoint l, const IntPoint &r) {
	return l += r;
    }
    friend IntPoint operator-(IntPoint l, const IntPoint &r) {
	return l -= r;
    }
    friend IntPoint operator*(const IntPoint &l, const IntPoint &r) {
	return IntPoint(l.x * r.x - l.y * r.y, l.x * r.y + l.y * r.x);
    }
    friend bool operator<(const IntPoint &l, const IntPoint &r) {
	return l.x != r.x? l.x < r.x: l.y < r.y;
    }
    friend bool operator>(const IntPoint &l, const IntPoint &r) { return r < l; }
    friend bool operator<=(const IntPoint &l, const IntPoint &r) { return !(r < l); }
    friend bool operator>=(const IntPoint &l, const IntPoint &r) { return !(l < r); }
    friend bool operator==(const IntPoint &l, const IntPoint &r) {
	return l.x == r.x && l.y == r.y;
    }
    friend bool operator!=(const IntPoint &l, const IntPoint &r) { return !(l == r); }
};

const IntPoint ZERO = IntPoint();

LL dot(const IntPoint &l, const IntPoint &r) {
    return l.x * r.x + l.y * r.y;
}
LL cross(const IntPoint &l, const IntPoint &r) {
    return l.x * r.y - l.y * r.x;
}

int ccw(const IntPoint &a, IntPoint b, IntPoint c) {
    b -= a; c -= a;
    LL l = b.x * c.y;
    LL r = b.y * c.x;
    if (l < r) return -1; // cw;
    if (l > r) return 1; // ccw;
    return 0; // on a line;
}

int ccw_zero(const IntPoint &b, const IntPoint &c) {
    LL l = b.x * c.y;
    LL r = b.y * c.x;
    if (l < r) return -1; // cw;
    if (l > r) return 1; // ccw;
    return 0; // on a line;
}

// (1, 0) -> (0, 1);
// (0, 1) -> (-1, 0);
IntPoint rot90(const IntPoint &p) {
    return IntPoint(-p.y, p.x);
}
// (1, 0) -> (0, -1);
// (0, -1) -> (-1, 0);
IntPoint rot270(const IntPoint &p) {
    return IntPoint(p.y, -p.x);
}

//          U
//         +y
//          |
//          |
// L -x ----O---- +x R
//          |
//          |
//         -y
//          D
enum class Orthant {
    O, L, LD, D, RD, R, RU, U, LU
};

Orthant orthant(const IntPoint &p) {
    if (p.x == 0 && p.y == 0) return Orthant::O;
    if (p.x < 0 && p.y == 0) return Orthant::L;
    if (p.x < 0 && p.y < 0) return Orthant::LD;
    if (p.x == 0 && p.y < 0) return Orthant::D;
    if (p.x > 0 && p.y < 0) return Orthant::RD;
    if (p.x > 0 && p.y == 0) return Orthant::R;
    if (p.x > 0 && p.y > 0) return Orthant::RU;
    if (p.x == 0 && p.y > 0) return Orthant::U;
    if (p.x < 0 && p.y > 0) return Orthant::LU;
    assert(false);
}

namespace SORT_BY_ARG {
IntPoint buf[100011]; // Maximum size;

void sort_by_arg(IntPoint *a, IntPoint *end) {
    int n = end - a;
    int c[9] = {}, d[9] = {};
    REP (i, n) c[(int)orthant(a[i])]++;
    REP (t, 8) d[t+1] = d[t] + c[t];
    REP (i, n) buf[d[(int)orthant(a[i])]++] = a[i];
    for (int t=2; t<=8; t+=2) {
	sort(buf + d[t-1], buf + d[t], [](const IntPoint &l, const IntPoint &r) {
		return cross(l, r) > 0;
		});
    }
    REP (i, n) a[i] = buf[i];
}

void sort_by_arg_idx(IntPoint *a, IntPoint *end, int *idx) {
    int n = end - a;
    int c[9] = {}, d[9] = {};
    REP (i, n) c[(int)orthant(a[i])]++;
    REP (t, 8) d[t+1] = d[t] + c[t];
    REP (i, n) idx[d[(int)orthant(a[i])]++] = i;
    for (int t=2; t<=8; t+=2) {
	sort(idx + d[t-1], idx + d[t], [&](int i, int j) { return cross(a[i], a[j]) > 0; });
    }
}
}; // namespace SORT_BY_ARG;

struct ByArg {
    int cmp(const IntPoint &l, const IntPoint &r) const {
	if (l == r) return 0;
	if (l.x == 0 && l.y == 0) return -1;
	if (r.x == 0 && r.y == 0) return 1;
	Orthant lval = orthant(l), rval = orthant(r);
	if (lval != rval) return lval < rval? -1: 1;
	switch (lval) {
	    case Orthant::O:
	    case Orthant::L:
	    case Orthant::D:
	    case Orthant::R:
	    case Orthant::U:
		return 0;
	    default:
		break;
	}
	return ccw_zero(r, l);
    }

    bool operator()(const IntPoint &l, const IntPoint &r) const {
	return cmp(l, r) < 0;
    }
} byArg;

struct Data {
    IntPoint p;
    int add;
    Data() {}
    Data(const IntPoint p_, int add_): p(p_), add(add_) {}

    bool operator<(const Data &o) const {
	return ByArg()(p, o.p);
    }
};

template<class Iter> vector<IntPoint> convex_hull(Iter a, Iter a_end, bool allow_180=false) {
    int n = a_end - a, len = 0;
    assert(n >= 3);
    sort(a, a_end);
    vector<IntPoint> h(n*2);
    const int allow = (allow_180? 0: 1);
    REP (i, n) {
	while (len >= 2 && ccw(h[len-2], h[len-1], a[i]) < allow) len--;
	h[len++] = a[i];
    }
    for (int i=n-2, t=len+1; i>=0; i--) {
	while (len >= t && ccw(h[len-2], h[len-1], a[i]) < allow) len--;
	h[len++] = a[i];
    }
    h.resize(len-1);
    return h;
}

double eval(const IntPoint &p, const IntPoint &v) {
    double rate = (double)p.y / -v.y;
    return p.x + v.x * rate;
}


const int MAXN = 2011;
int N;
LL XL[MAXN], XR[MAXN], Y[MAXN];

bool line() {
    return *min_element(Y, Y+N) == *max_element(Y, Y+N);
}

void MAIN() {
    scanf("%d", &N);
    REP (i, N) scanf("%lld%lld%lld", XL+i, XR+i, Y+i);

    if (line()) {
	LL ans = *max_element(XR, XR+N) - *min_element(XL, XL+N);

	printf("%lld\n", ans);

	return;
    }

    vector<Data> V;
    REP (i, N) REP (j, N) if (Y[i] < Y[j]) {
	IntPoint a(XR[i] - XL[j], Y[i] - Y[j]);
	IntPoint b(XL[i] - XR[j], Y[i] - Y[j]);
	V.emplace_back(b, 1);
	V.emplace_back(a, -1);
    }


    sort(V.begin(), V.end());

    vector<IntPoint> VECS;

    int sum = 0;
    for (int i=0; i<(int)V.size(); ) {
	int j = i;
	IntPoint p = V[i].p;

	while (j < (int)V.size() && cross(p, V[j].p) == 0) {
	    j++;
	}

	for (int k=i; k<j; k++) {
	    if (V[k].add < 0) sum += V[k].add;
	}
	if (sum == 0) {
	    VECS.push_back(p);
	}

	for (int k=i; k<j; k++) {
	    if (V[k].add > 0) sum += V[k].add;
	}
	if (sum == 0) {
	    VECS.push_back(p);
	}

	i = j;
    }

    //SORT_BY_ARG::sort_by_arg(VECS.data(), VECS.data() + VECS.size());

    vector<IntPoint> PS;
    REP (i, N) {
	PS.emplace_back(XL[i], Y[i]);
	PS.emplace_back(XR[i], Y[i]);
    }
    PS = convex_hull(PS.begin(), PS.end());

    vector<double> ans(VECS.size(), 0.0);

    REP (t, 2) {
	int sgn = (t? 1: -1);
	int index = 0;
	REP (i, VECS.size()) {
	    const IntPoint &v = VECS[i];
	    double best = sgn*eval(PS[index], v);
	    while (1) {
		int left = index-1;
		if (left < 0) left += PS.size();
		double tmp = sgn*eval(PS[left], v);
		if (best < tmp) {
		    index = left;
		    best = tmp;
		} else {
		    break;
		}
	    }

	    while (1) {
		int right = index+1;
		if (right >= (int)PS.size()) right -= PS.size();
		double tmp = sgn*eval(PS[right], v);
		if (best < tmp) {
		    index = right;
		    best = tmp;
		} else {
		    break;
		}
	    }

	    ans[i] += best;
	}
    }

    printf("%.20f\n", *min_element(ans.begin(), ans.end()));
    //rprintf("%f", ans.begin(), ans.end());
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}