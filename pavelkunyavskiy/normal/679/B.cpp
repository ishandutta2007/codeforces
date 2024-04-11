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

#define TASKNAME "B"

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

map<pair<ll, ll>, pair<ll, ll> > ans;

ll norm(ll a) {
    ll root = (ll) pow(a, 1.0 / 3);
    while (root * root * root < a) root++;
    while (root * root * root > a) root--;
    return root;
}

pair<ll, ll> solve(ll pos, ll m) {
    pos = min(pos, norm(m));
    assert(m <= (pos + 1) * (pos + 1) * (pos + 1));
    pair<ll,ll> &res = ans[make_pair(pos, m)];
    if (res.first != 0 || pos == 0 || m == 0) return res;
    ll cube = pos * pos * pos;
    res = max(res, solve(pos - 1, min(m, cube - 1)));
    if (m >= cube) {
        auto nres = solve(pos, m - cube);
        nres.first += 1;
        nres.second += cube;
        res = max(res, nres);
    }
    return res;
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif

    ll m;
    scanf("%lld",&m);
    auto res = solve(100000, m);
    printf("%lld %lld\n", res.first, res.second);
    return 0;
}