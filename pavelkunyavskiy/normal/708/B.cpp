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

vector<ll> getc2(ll a) {
    if (a == 0) {
        return {0, 1};
    }
    ll x = 0;
    while (x * (x - 1) / 2 < a) {
        x++;
    }
    if (x * (x - 1) / 2 == a)
        return {x};
    return {};
}

char s[1000100];

void solve(ll a, ll b, ll c, ll d) {
    vector<ll> zss = getc2(a);
    vector<ll> oss = getc2(d);
    for (ll zs : zss)
        for (ll os : oss) {
            if (zs + os == 0) continue;
            if (zs * os != b + c) continue;
            ll tot = zs + os;
            for (int i = 0; i < tot; i++) {
                if (b >= os) {
                    s[i] = '0';
                    b -= os;
                    zs--;
                } else {
                    s[i] = '1';
                    c -= zs;
                    os--;
                }
            }
            assert(b == 0 && c == 0);
            s[tot] = 0;
            puts(s);
            return;
        }
    printf("Impossible\n");
}

int main() {
#ifdef LOCAL
    assert(freopen(TASKNAME".in", "r", stdin));
    assert(freopen(TASKNAME".out", "w", stdout));
#endif
    int a, b, c, d;

    while (scanf("%d%d%d%d", &a, &b, &c, &d) == 4) {
        solve(a, b, c, d);
    }

    return 0;
}