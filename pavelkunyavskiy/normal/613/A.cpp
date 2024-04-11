//#include <iostream>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>
#include <algorithm>
#include <sstream>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <cstdlib>
#include <cstdio>
#include <iterator>
#include <functional>
#include <bitset>

#define mp make_pair
#define pb push_back

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x, ...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ((_WIN32 || __WIN32__) && __cplusplus < 201103L)
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "A"

#ifdef LOCAL

static struct __timestamper {
    string what;

    __timestamper(const char *what) : what(what) { };

    __timestamper(const string &what) : what(what) { };

    ~__timestamper() {
        TIMESTAMPf("%s", what.data());
    }
} __TIMESTAMPER("end");

#else
struct __timestamper {};
#endif

#ifndef M_PI
# define M_PI       3.14159265358979323846  /* pi */ // wtf???
#endif

typedef long long ll;
typedef long double ld;

struct point {
    int x, y;
    point() { x = y = 0; }
    point(int x, int y) :x(x), y(y) {}
};

point operator-(const point& a, const point& b) {
    return point(a.x - b.x, a.y - b.y);
}

long long sp(const point& a, const point& b) {
    return a.x * 1LL * b.x + a.y * 1LL * b.y;
}

long long vp(const point& a, const point& b) {
    return a.x * 1LL * b.y - a.y * 1LL * b.x;
}

double len(const point& a) {
    return sqrt(sp(a, a));
}

double dist(const point& a, const point& b) {
    if (sp(b - a, point() - a) > 0 && sp(a - b, point() - b) > 0) {
        return abs(vp(a, b)) / len(b - a);
    }
    return min(len(a), len(b));
}


int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    int n;
    scanf("%d",&n);
    point p;
    scanf("%d%d",&p.x, &p.y);

    vector<point> v(n);
    for (point& pt : v) {
        scanf("%d %d",&pt.x, &pt.y);
        pt = pt - p;
    }

    double mind = 1e100, maxd = -1e100;

    for (int i = 0; i < n; i++) {
        maxd = max(maxd, len(v[i]));
        mind = min(mind, dist(v[i], v[(i+1) % n]));
    }
    eprintf("%f %f\n", mind, maxd);

    printf("%.10f\n", M_PI * (maxd * maxd - mind * mind));

    return 0;
}