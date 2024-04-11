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

#define TASKNAME "E"

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



int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, k;
  scanf("%d%d",&n, &k);
  vector<int> v(n);
  vector<int> c(n);
  for (int& x : v) {
    scanf("%d",&x);
    x *= 100;
  }
  for (int& x : c) {
    scanf("%d",&x);
  }

  for (int i = 0; i < n; i++) {
    v[i] = min(v[i], c[i]);
  }

  deque<int> q;

  vector<int> ans;

  for (int i = n - 1; i >= 0; i--) {
    while (q.size() && q.front() < v[i]) q.pop_front();
    q.push_front(v[i]);
    bool any = false;
    while (q.size() && q.back() > c[i]) {
      any = true;
      q.pop_back();
    }
    if (any) {
      q.push_back(c[i]);
    }
    assert(!q.empty());
    ans.push_back(q.back());
#ifdef LOCAL
    int maxx = v[i];
    int minx = c[i];
    int result = min(minx, maxx);
    for (int j = i; j < n; j++) {
      maxx = max(maxx, v[j]);
      minx = min(minx, c[j]);
      result = max(result, min(minx, maxx));
    }
    eprintf("%d %d %d\n", i, result, q.back());
    assert(result == q.back());
#endif
  }

  sort(ans.begin(), ans.end());

  double res = 0;
  double cur = k * 1.0 / n;

  double sumcur = 0;

  for (int i = 0; i <= n - k; i++) {
    sumcur += cur;
    res += cur * ans[i];
    cur /= (n - i - 1);
    cur *= (n - i - k);
  }

  eprintf("%.10f\n", sumcur);

  printf("%.10f\n", res);

  return 0;
}