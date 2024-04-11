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

vector<int> v;
vector<int> used;
int usedptr;
int n;

bool use(int x) {
  int id = lower_bound(v.begin(), v.end(), x) - v.begin();
  while (id != n && v[id] == x && used[id] == usedptr) id++;
  if (id != n && v[id] == x) {
    used[id] = usedptr;
    return true;
  }
  return false;
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  scanf("%d",&n);
  v = vector<int>(n);
  used = vector<int>(n);
  for (int& x : v)
    scanf("%d", &x);

  sort(v.begin(), v.end());
  vector<int> vals = v;
  vals.erase(unique(vals.begin(), vals.end()), vals.end());

  int ans = 1;
  for (int i = 0; i < (int)vals.size(); i++)
    for (int j = 0; j < (int)vals.size(); j++) {
      usedptr++;
      int a, b;
      a = vals[i];
      b = vals[j];
      if (!use(a) || !use(b)) continue;
      ans = max(ans, 2);
      for (int k = 3; use(a+b); k++) {
        ans = max(ans, k);
        int t = a + b;
        a = b;
        b = t;
      }
    }

  printf("%d\n", ans);

      
  return 0;
}