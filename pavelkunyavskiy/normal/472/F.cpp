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

#define TASKNAME "F"

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


void make_op(vector<int>& x, vector<pair<int,int>>& ans, int i, int j) {
    x[i] ^= x[j];
    ans.pb(mp(i, j));
}

void make_swap(vector<int>& x, vector<pair<int,int>>& ans, int i, int j) {
    if (i == j) return;
    #ifdef LOCAL
    int tmpi = x[i], tmpj = x[j];
    #endif
    make_op(x, ans, i, j);
    make_op(x, ans, j, i);
    make_op(x, ans, i, j);
    #ifdef LOCAL
    assert(x[i] == tmpj);
    assert(x[j] == tmpi);
    #endif
}

int n;


int make_iter(vector<int>& x, vector<pair<int, int>>& ans, int pos) {
    int mid = max_element(x.begin() + pos, x.end()) - x.begin();
    make_swap(x, ans, mid, pos);
    if (x[pos] == 0) return -1;
    int bit = 31 - __builtin_clz(x[pos]);
    for (int j = 0; j < n; j++)
        if (j != pos && (x[j] & (1<<bit)))
            make_op(x, ans, j, pos);
    return bit;
}


void solve(){
    vector<int> xs(n), ys(n);
    for (int& x : xs)
        scanf("%d",&x);
    for (int& y : ys)
        scanf("%d",&y);
    #ifdef LOCAL
    vector<int> xb, yb;
    xb = xs, yb = ys;
    #endif
    vector<pair<int, int>> ans1, ans2;

    for (int i = 0; i < n; i++) {
        int b1 = make_iter(xs, ans1, i);
        int b2 = make_iter(ys, ans2, i);
        if (b1 == -1 && b2 == -1) 
            break;
        if (b1 == b2) 
            continue;
        if (b2 > b1) {
            printf("-1\n");
            return;
        }
        for (int j = 0; j < i; j++) {
            if (ys[j] & (1<<b1))
                make_op(xs, ans1, j, i);
        }
        make_op(xs, ans1, i, i);
        i--;
    }
    if (xs != ys) {
        printf("-1\n");
        return;
    }
    ans1.insert(ans1.end(), ans2.rbegin(), ans2.rend());
    printf("%d\n", ans1.size());
    for (auto x : ans1)
        printf("%d %d\n", x.first + 1, x.second + 1);
    #ifdef LOCAL
        for (auto x : ans1)
            xb[x.first] ^= xb[x.second];
        assert(xb == yb);
    #endif
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

    while (scanf("%d",&n) == 1) {
        solve();
    }

      
  return 0;
}