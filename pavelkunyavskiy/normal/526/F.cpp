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

const int MAXN = 310000;
int a[MAXN];
long long ans;

void merge(const vector<int>& a, const vector<int>& b){
  vector<int> mins(b.size());
  vector<int> maxs(b.size());
  vector<pair<pair<int, int>, int>> lens(b.size());
  int minv, maxv;
  minv = maxv = b[0];
  for (int i = 0; i < (int)b.size(); i++){
    minv = min(minv, b[i]);
    maxv = max(maxv, b[i]);
    mins[i] = minv;
    maxs[i] = maxv;
    lens[i] = mp(mp(minv, maxv - i - 1), i);
  }
  sort(lens.begin(), lens.end());
  vector<int> bs = b;
  bs.pb(1e9);
  bs.pb(-1e9);
  sort(bs.begin(), bs.end());

  vector<int> as = a;
  as.pb(1e9);
  as.pb(-1e9);
  sort(as.begin(), as.end());

  minv = maxv = a[0];

  /*eprintf("a = ");
  for (int i = 0; i < (int)a.size(); i++)
    eprintf(" %d", a[i]);
  eprintf("\n");

  eprintf("b = ");
  for (int i = 0; i < (int)b.size(); i++)
    eprintf(" %d", b[i]);
  eprintf("\n");*/

  for (int i = 0; i < (int)a.size(); i++){
    minv = min(minv, a[i]);
    maxv = max(maxv, a[i]);

    int minv2id = lower_bound(bs.begin(), bs.end(), minv) - bs.begin();
    int maxv2id = lower_bound(bs.begin(), bs.end(), maxv) - bs.begin() - 1;
    if (minv2id <= maxv2id && minv2id != 0 && maxv2id != (int)bs.size() - 1 && 
        mins[maxv2id - minv2id] == bs[minv2id] && maxs[maxv2id - minv2id] == bs[maxv2id] &&
        maxv2id - minv2id + i + 1 == maxv - minv) {
      //eprintf("HERE! %d %d\n", minv, maxv);
      ans++;
    }

    int minpos = lower_bound(maxs.begin(), maxs.end(), maxv) - maxs.begin();
    //int maxpos = lower_bound(mins.begin(), mins.end(), minv, greater<int>()) - mins.begin();
    //eprintf("i = %d, minv = %d, maxv = %d, minv2id = %d, maxv2id = %d, minpos = %d\n", i, minv, maxv, minv2id, maxv2id, minpos);

    pair<int, int> key = mp(bs[minv2id], minv + i);
    //eprintf("searching for (%d, %d) with pos >= %d\n", key.first, key.second, minpos);
    ans += max(0, (int)(upper_bound(lens.begin(), lens.end(), mp(key, (int)1e9)) -
                  lower_bound(lens.begin(), lens.end(), mp(key, minpos))));
  }
}

void solve(int l, int r){
  if (r - l == 1){
    ans++;
    return;
  }
  if (r - l == 0) {
    return;
  }
  int m = (l + r) / 2;
  //long long ans_bef = ans;
  solve(l, m);
  solve(m, r);
  vector<int> lf(m - l), rg(r - m);
  for (int i = m - 1; i >= l; i--)
    lf[m - i - 1] = a[i];
  for (int i = m; i < r; i++)
    rg[i - m] = a[i];
  //long long ans_in = ans - ans_bef;
  //long long ans_lf = -ans;
  merge(lf, rg);
  //ans_lf += ans;
  //long long ans_rg = -ans;
  merge(rg, lf);
  //ans_rg += ans;
  //fprintf(stderr, "In [%d..%d] - %lld = %lld in + %lld left + %lld right\n", l, r, ans - ans_bef, ans_in, ans_lf, ans_rg);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++){
    int r, c;
    scanf("%d%d",&r,&c);
    --r,--c;
    a[r] = c;
  }

  solve(0, n);
  printf(LLD"\n", ans);      
  return 0;
}