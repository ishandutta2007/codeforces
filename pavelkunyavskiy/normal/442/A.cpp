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

#define TASKNAME "A"

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



bool check(vector<pair<int, int> > v, int mask) {
    sort(v.begin(), v.end());
    if (v.empty() || v[0] == v.back()) return true;
    if (!mask) return false;
    int id = __builtin_ctz(mask);
    mask ^= (1<<id);
    int ty = id / 5;
    id = id % 5;
    vector<pair<int, int> > nv[2];
    for (int i = 0; i < (int)v.size(); i++)
        nv[(ty ? v[i].first : v[i].second) == id].pb(v[i]);
    return check(nv[0], mask) && check(nv[1], mask);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    int n;
    while (scanf("%d",&n) == 1) {
        vector<pair<int, int> > v(n);
        for (int i = 0; i < n; i++) {
            char buf[4];
            scanf("%s", buf);
            const char* names = "RGBYW";
            v[i] = mp(strchr(names, buf[0]) - names, buf[1] - '1');
        }
        int ans = 10;
        for (int i = 0; i < (1<<10); i++)
            if (check(v, i))
                ans = min(ans, __builtin_popcount(i));
        printf("%d\n", ans);
    }

      
  return 0;
}