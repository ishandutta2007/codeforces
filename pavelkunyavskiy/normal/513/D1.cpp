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

void error(){
  puts("IMPOSSIBLE");
  exit(0);
}

struct rest {
  int l, r;
  int ty;
  bool operator<(const rest& a){
    return l < a.l;
  }
};

const int MAXN = 1100000;

rest rs[1100000];
int firstR[MAXN];
vector<int> ans;

void solve(int l, int r, int cl, int cr){
 // eprintf("[%d, %d) [%d, %d)", l, r, cl, cr);
  if (l == r) return;
  if (l == r - 1){
    ans.pb(l);
    return;
  }
  int lastL = l;
  int i;
  for (i = cl; i < cr; i++) {
  //  eprintf("%d %d %d\n", rs[i].l, rs[i].r, rs[i].ty);
    if (rs[i].l == l && rs[i].ty == 1)
      continue;
    else if (rs[i].l <= lastL)
      lastL = max(lastL, rs[i].r);
    else
      break;
  }
  //eprintf("l =%d, lastL = %d; i = %d\n", l, lastL, i);
  if (firstR[l] <= lastL)
    error();
  while (cl < cr && rs[cl].l == l) cl++;
  solve(l+1, lastL+1, cl, i);
  ans.pb(l);
  solve(lastL+1, r, i, cr);
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, c;
  scanf("%d%d",&n,&c);
  for (int i = 0; i < c; i++) {
    scanf("%d%d",&rs[i].l, &rs[i].r);
    --rs[i].l, --rs[i].r;
    if (rs[i].l >= rs[i].r){
      error();
    }
    char buf[10];
    scanf("%s", buf);
    if (!strcmp(buf, "LEFT"))
      rs[i].ty = 0;
    else
      rs[i].ty = 1;
  }
  sort(rs, rs + c);
  for (int i = 0; i < n; i++)
    firstR[i] = 1e9;
  for (int i = 0; i < c; i++)
    if (rs[i].ty == 1)
      firstR[rs[i].l] = min(firstR[rs[i].l], rs[i].r);
  solve(0, n, 0, c );      
  for (int i = 0; i < (int)ans.size(); i++)
    printf("%d ", ans[i] + 1);
  printf("\n");
  return 0;
}