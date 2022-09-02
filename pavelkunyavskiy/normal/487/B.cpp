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
                          

struct SegTree {
    vector<int> tree;
    int lst;
    SegTree(){}
    SegTree(vector<int> a) {
        int n = a.size();
        lst = 2;
        while (lst < n) lst *= 2;
        tree.resize(2*lst, 1e9);
        for (int i = 0; i < n; i++)
            tree[i+lst] = a[i];
        for (int j = lst - 1; j > 0; j--)
            tree[j] = min(tree[2*j], tree[2*j+1]);
    }
    void update(int pos, int val) {
        pos += lst;
        tree[pos] = val;
        for (pos /= 2; pos> 0; pos /= 2)
            tree[pos] = min(tree[2*pos], tree[2*pos+1]);
    }
    int get(int l, int r) {
        l = l + lst;
        r = r + lst;
        int ans = 1e9;
         while (l <= r) {
             if (l & 1) ans = min(ans, tree[l]), l++;
             if (!(r & 1)) ans = min(ans, tree[r]), r--;
             l /= 2;
             r /= 2;
         }
         return ans;
    }
};


 


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif
     int n, s, l;
     while (scanf("%d%d%d",&n,&s,&l) == 3) {
        SegTree tmin, tmax;
        {
        vector<int> a(n), nega(n);
        for (int i = 0; i < n; i++)
            scanf("%d",&a[i]), nega[i] = -a[i];
        tmin = SegTree(a);
        tmax = SegTree(nega);
        }
        SegTree dp(vector<int>(n+1, 1e9));
        dp.update(0, 0);
        for (int i = 0; i < n; i++) {
            int lf = 1;
            int rg = i+2;
            while (rg - lf > 1) {
                int mid = (lf + rg) / 2;
//              eprintf("mid = %d, val = %d\n", mid, -tmax.get(i - mid + 1, i) - tmin.get(i - mid + 1, i));
                if (-tmax.get(i - mid + 1, i) - tmin.get(i - mid + 1, i) <= s)
                    lf = mid;
                else
                    rg = mid;
            }
//          eprintf("i = %d, [%d..%d], val = %d, \n", i, i - lf + 1, i - l + 1, dp.get(i - lf + 1, i - l + 1));
            dp.update(i+1, dp.get(i - lf + 1, i - l + 1) + 1);
        }
        if (dp.get(n, n) > n)
            printf("-1\n");
        else
            printf("%d\n", dp.get(n, n));
     }
      
  return 0;
}