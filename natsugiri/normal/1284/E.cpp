#include<cmath>
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

LL dot(const IntPoint &l, const IntPoint &r) {
    return l.x * r.x + l.y * r.y;
}
LL cross(const IntPoint &l, const IntPoint &r) {
    return l.x * r.y - l.y * r.x;
}
int ccw_zero(const IntPoint &b, const IntPoint &c) {
    LL l = b.x * c.y;
    LL r = b.y * c.x;
    if (l < r) return -1; // cw;
    if (l > r) return 1; // ccw;
    return 0; // on a line;
}
int ccw(const IntPoint &a, IntPoint b, IntPoint c) {
    b -= a; c -= a;
    LL l = b.x * c.y;
    LL r = b.y * c.x;
    if (l < r) return -1; // cw;
    if (l > r) return 1; // ccw;
    return 0; // on a line;
}

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

const IntPoint ZERO = IntPoint(0, 0);

IntPoint buf[2511];
void sort_by_arg(IntPoint *a, IntPoint *end) {
    int n = end - a;
    int c[9] = {}, d[10] = {};
    REP (i, n) c[(int)orthant(a[i])]++;
    REP (t, 8) d[t+1] = d[t] + c[t];
    REP (i, n) buf[d[(int)orthant(a[i])]++] = a[i];
    REP (t, 8) d[t+1] = d[t] + c[t];
    d[9] = n;
    for (int t=2; t<=8; t+=2) {
	sort(buf + d[t], buf + d[t+1], [](const IntPoint &l, const IntPoint &r) {
		return cross(l, r) > 0;
		});
    }
    REP (i, n) a[i] = buf[i];
}

int idx[2511];
void sort_by_arg2(IntPoint *a, IntPoint *end) {
    static long double val[2511];
    int n = end - a;
    REP (i, n) {
	val[i] = atan2l(a[i].y, a[i].x);
	idx[i] = i;
    }
    sort(idx, idx+n, [](int i, int j) { return val[i] < val[j]; });
    REP (i, n) buf[i] = a[idx[i]];
    REP (i, n) a[i] = buf[i];
}

void sort_by_arg3(IntPoint *a, IntPoint *end) {
    sort(a, end, [](const IntPoint &l, const IntPoint &r) {
	    double la = atan2(l.y, l.x);
	    double ra = atan2(r.y, r.x);
	    if (abs(la - ra) > 1) return la < ra;
	    else return l.x * r.y > l.y * r.x;
	    });
}

int divide17(const IntPoint &p) {
    if (p.y < 0) {
	if (p.x < 0) {
	    if (p.x < p.y) return 2;
	    if (p.x > p.y) return 4;
	    return 3;
	}
	if (p.x > 0) {
	    if (p.y < -p.x) return 6;
	    if (p.y > -p.x) return 8;
	    return 7;
	}
	return 5;
    }
    if (p.y > 0) {
	if (p.x > 0) {
	    if (p.y < p.x) return 10;
	    if (p.y > p.x) return 12;
	    return 11;
	}
	if (p.x < 0) {
	    if (p.y > -p.x) return 14;
	    if (p.y < -p.x) return 16;
	    return 15;
	}
	return 13;
    }
    if (p.x < 0) return 1;
    if (p.x > 0) return 9;
    return 0;
}

void sort_by_arg4(IntPoint *a, IntPoint *end) {
    int n = end - a;
    static int di[2511];
    REP (i, n) di[i] = divide17(a[i]);
    static int c[17], d[18];
    memset(c, 0, sizeof c);
    REP (i, n) c[di[i]]++;
    d[0] = 0;
    REP (t, 17) d[t+1] = d[t] + c[t];
    REP (i, n) idx[d[di[i]]++] = i;
    REP (t, 17) d[t+1] = d[t] + c[t];
    for (int t=2; t<=16; t+=2)
	sort(idx+d[t], idx+d[t+1], [&](int i, int j) { return cross(a[i], a[j]) > 0; });
    REP (i, n) buf[i] = a[idx[i]];
    REP (i, n) a[i] = buf[i];
}

void sort_by_arg5(IntPoint *a, IntPoint *end) {
    int n = end - a;
    static int di[2511];
    REP (i, n) di[i] = divide17(a[i]);
    static int c[17], d[18];
    memset(c, 0, sizeof c);
    REP (i, n) c[di[i]]++;
    d[0] = 0;
    REP (t, 17) d[t+1] = d[t] + c[t];
    REP (i, n) buf[d[di[i]]++] = a[i];
    REP (t, 17) d[t+1] = d[t] + c[t];
    for (int t=2; t<=16; t+=2)
	sort(buf+d[t], buf+d[t+1], [&](const IntPoint &l, const IntPoint &r) {
		return cross(l, r) > 0;
		});
    REP (i, n) a[i] = buf[i];
}

void sort_by_arg6(IntPoint *a, IntPoint *end) {
    int n = end - a;
    int c0 = 0, c1 = 0;
    REP (i, n) {
	if (a[i].y <= 0) c0++;
	else c1++;
    }
    int d0 = 0, d1 = c0;
    REP (i, n) {
	if (a[i].y <= 0) buf[d0++] = a[i];
	else buf[d1++] = a[i];
    }
    sort(buf, buf+c0, [](const IntPoint &l, const IntPoint &r) { return cross(l, r) > 0; });
    sort(buf+c0, buf+c0+c1, [](const IntPoint &l, const IntPoint &r) { return cross(l, r) > 0; });
    REP (i, n) a[i] = buf[i];
}

int N;
IntPoint P[2511];
IntPoint A[5011];

void MAIN() {
    scanf("%d", &N);
    REP (i, N) {
	int x, y;
	scanf("%d%d", &x, &y);
	P[i] = IntPoint(x, y);
    }

#ifdef MYTEST
    N = 2500;
    REP (i, N) P[i] = IntPoint(rand(), rand());
#endif

    LL ans = 0;

    LL base = (LL)(N-1) * (N-2) / 2 * (N-3) / 3 * (N-4) / 4;

    REP (s, N) {
	LL len = 0;
	REP (i, N) if (i != s) A[len++] = P[i] - P[s];
	//sort(A, A+len, byArg);
	sort_by_arg6(A, A+len);

	REP (i, len) A[i+len] = A[i];

	LL tmp = 0;
	int j = 0;
	REP (i, len) {
	    amax(j, i+1);
	    while (j < i + len && ccw_zero(A[i], A[j]) == 1) j++;

	    LL m = j-i-1;
	    if (m >= 3) {
		tmp += m * (m-1) / 2 * (m-2) / 3;
	    }
	}

	ans += base - tmp;
    }

    printf("%lld\n", ans);
}

int main() {
    int TC = 1;
//    scanf("%d", &TC);
    REP (tc, TC) MAIN();
    return 0;
}