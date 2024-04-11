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
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

#if ( ( _WIN32 || __WIN32__ ) && __cplusplus < 201103L)
    #define LLD "%I64d"
#else
    #define LLD "%lld"
#endif

using namespace std;

#define TASKNAME "C"

#ifdef LOCAL
static struct __timestamper {
    string what;
    __timestamper(const char* what) : what(what){};
    __timestamper(const string& what) : what(what){};
	~__timestamper(){
        TIMESTAMPf("%s", what.data());
	}
} __TIMESTAMPER("end");
#else 
struct __timestamper {};
#endif

typedef long long ll;
typedef long double ld;

const int MAXN = 100100;

const int INF = (const int) 1e9;

pair<int, int> pts[MAXN];
int smax[MAXN];
int smin[MAXN];
int n;

long long sqr(long long x){
    return x * x;
}


bool check(ll maxd) {
    int lmaxd = (int)sqrt(maxd);
    while (sqr(lmaxd) <= maxd) lmaxd++;
    while (sqr(lmaxd) > maxd) lmaxd--;
    if (sqr(pts[n-1].first - pts[0].first) <= maxd) return true;
    if (sqr(smax[0] - smin[0]) <= maxd) return true;

    int maxy = -INF;
    int miny = +INF;
    for (int i = 0; i < n; i++) {
        int limit = min(abs(pts[i].first), pts[i].first + lmaxd);
        int ptr = upper_bound(pts, pts+n, limit, [](int a, const pair<int,int>& b) { return a < b.first;}) - pts;
        int cmaxy = max(maxy, smax[ptr]);
        int cminy = min(miny, smin[ptr]);
        if (sqr(pts[i].first) + max(sqr(cmaxy), sqr(cminy)) <= maxd && sqr(cmaxy - cminy) <= maxd) return true;
        maxy = max(maxy, pts[i].second);
        miny = min(miny, pts[i].second);
    }
    return false;
}

long long solve() {
    sort(pts, pts+n);

    smax[n] = -INF;
    smin[n] = +INF;
    for (int i = n - 1; i >= 0; i--) {
        smax[i] = max(smax[i+1], pts[i].second);
        smin[i] = min(smin[i+1], pts[i].second);
    }

    check(8);

    ll lf = -1;
    ll rg = (ll)1e18;

    while (rg - lf > 1) {
        ll m = (lf + rg) / 2;
        if (check(m))
            rg = m;
        else
            lf = m;
    }

    return rg;
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    scanf("%d",&n);
    for (int i = 0; i < n; i++) {
        scanf("%d%d",&pts[i].first, &pts[i].second);
    }

    ll ans1 = solve();
    for (int i = 0; i < n; i++)
        pts[i].first *= -1;
    ll ans2 = solve();

    printf("%lld\n", min(ans1, ans2));

    return 0;
}