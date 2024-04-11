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

struct dsu {
    vector<int> p;
    vector<int> size;

    dsu(int n):p(n), size(n, 1){
        for (int i = 0; i < n; i++) p[i] = i;
    }

    int get(int v) {
        if (p[v] == v) return v;
        return p[v] = get(p[v]);
    }

    ll join(int a, int b){
        a = get(a);
        b = get(b);
        if (a == b) return 0;
        ll temp = size[a] * 1LL * size[b];
        if (size[a] > size[b]) swap(a, b);
        p[a] = b;
        size[b] += size[a];
        return temp;
    }
};


vector<int> cnt;

bool cmp(const pair<int,int>& a, const pair<int,int>& b){
    return min(cnt[a.first], cnt[a.second]) < min(cnt[b.first], cnt[b.second]);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, m;
  while (scanf("%d %d",&n,&m) == 2){
      vector< pair<int, int> > v(m);
      cnt = vector<int>(n);
      for (int i = 0; i < n; i++)
          scanf("%d",&cnt[i]);

      for (int i = 0; i < m; i++) {
        scanf("%d %d",&v[i].first, &v[i].second);
        --v[i].first, --v[i].second;
      }
      sort(v.rbegin(), v.rend(),cmp);


      dsu d(n);
      ll tot = 0;
      for (int i = 0; i < m; i++)
        tot += min(cnt[v[i].first], cnt[v[i].second]) * d.join(v[i].first, v[i].second);
      printf("%.18lf\n", (double)tot / (double)(n * 1LL * (n - 1) / 2));
  }
      
  return 0;
}