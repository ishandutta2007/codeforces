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

#define TASKNAME "D"

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


const int MAXN = 1100000;

pair<int, int> max1[MAXN], max2[MAXN];
int p[MAXN];


void updateOne(int v, pair<int, int> res) { 
    pair<int,int>& v1 = max1[v];
    pair<int,int>& v2 = max2[v];
    if (v1.second == res.second) {
        v1 = res;
        return;
    } else if (v2.second == res.second) {
        v2 = res;
        if (v1.first < v2.first) swap(v1, v2);
        return;
    }
    if (v2.first < res.first) swap(v2, res);
    if (v1.first < v2.first) swap(v1, v2);
}

int get(int v) {
    return max1[v].first + (max1[v].first == max2[v].first && v != 0);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

   max1[0] = max2[0] = mp(0, -1);

   int n;
   scanf("%d",&n);
   for (int i = 1; i <= n; i++) {
       scanf("%d",&p[i]);
       --p[i];
       max1[i] = max2[i] = mp(0, -1);
       int t = i;
       while (t != 0) {
           int curv = get(p[t]);
           updateOne(p[t], mp(get(t), t));
           int newv = get(p[t]);
           if (newv == curv) break;
           t = p[t];
       }
       eprintf("0 : (%d, %d); (%d, %d)\n", max1[0].first, max1[0].second, max2[0].first, max2[0].second);
       printf("%d ", get(0));
   }
      
   return 0;
}