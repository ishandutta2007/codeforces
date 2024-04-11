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

vector<int> v;

void solve(int l, int r) {
  vector<int> res;
  for (int i = l + 1; i < r; i++) {
    res.push_back (abs (v[i] - v[i - 1]));
  }
  /*long long ans = 0;
  for (int i = 0; i < (int)res.size(); i++) {
    int cur = res[i];
    for (int j = i; j < (int)res.size(); j++) {
      cur = max(cur, res[j]);
      ans += cur;
    }
  }*/
  vector<int> lf (res.size ());
  vector<int> rg (res.size ());
  vector<int> st;
  for (int i = 0; i < (int)res.size (); i++) {
    while (!st.empty () && res[st.back ()] < res[i]) {
      rg[st.back ()] = i;
      st.pop_back ();
    }
    if (st.empty ()) {
      lf[i] = -1;
    } else {
      lf[i] = st.back ();
    }
    st.push_back (i);
  }
  for (int x : st)
    rg[x] = (int)res.size ();

  long long ans = 0;
  for (int i = 0; i < (int)res.size (); i++)
    ans += (i - lf[i]) * 1LL * (rg[i] - i) * 1LL * res[i];
  printf ("%lld\n", ans);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, q;
  scanf("%d%d",&n,&q);
  v = vector<int>(n);
  for (int& x : v) scanf("%d",&x);

  for (int i = 0; i < q; i++) {
    int l, r;
    scanf("%d%d",&l,&r);
    solve(l-1, r);
  }


      
  return 0;
}