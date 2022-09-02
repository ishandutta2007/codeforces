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

#define TASKNAME "C"

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

const int MAXN = 1100;

char s[MAXN][MAXN];
char temp[MAXN][MAXN];
int n, m;


int solve(){
  int sx = -1, sy = -1;
  for (int i = 0; i < n && sx == -1; i++)
     for (int j = 0; j < m && sx == -1; j++)
        if (s[i][j] == 'X') 
            sx = i, sy = j;
  int h = 0;
  while (s[sx+h][sy] == 'X') h++;
  int w1 = 0;
  while (s[sx][sy+w1] == 'X') w1++;
  int w = 1;
  while (w <= w1 && s[sx + h][sy + w1 - w - 1] == 'X') w++;
  if (w > w1) return -1;
  memset(temp, '.', sizeof(temp));

  for (int i = 0; i < n; i++)
    temp[i][m] = 0;
  for (int i = 0; i < h; i++)
    for (int j = 0; j < w; j++)
        temp[sx + i][sy + j] = 'X';
  while (true) {
//    eprintf("%d %d\n", sx, sy);
//      for (int i = 0; i < n; i++)
//          eprintf("%s\n", temp[i]);
//      eprintf("\n");
    if (s[sx][sy + w] == 'X') {
        for (int i = 0; i < h; i++)
            temp[sx + i][sy + w] = 'X';
        sy++;
    } else if (s[sx + h][sy] == 'X') {
        for (int i = 0; i < w; i++)
            temp[sx + h][sy + i] = 'X';
        sx++;
    } else 
        break;
  }


  for (int i = 0; i < n; i++)
     for (int j = 0; j < m; j++)
        if (s[i][j] != temp[i][j])
            return -1;
  return w * h;
}


int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  scanf("%d%d",&n,&m);
  for (int i = 0; i < n; i++)
    scanf("%s",s[i]);

  int ans1 = solve();
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
        temp[j][i] = s[i][j];
  swap(n, m);
  for (int i = 0; i < n; i++) {
    s[i][m] = 0;
    for (int j = 0; j < m; j++)
        s[i][j] = temp[i][j];
  }
  for (int j = 0; j < m; j++)
    s[n][j] = 0;
  int ans2 = solve();
  if (ans1 == -1) printf("%d\n", ans2);
  else if (ans2 == -1) printf("%d\n", ans1);
  else printf("%d\n", min(ans1, ans2));
      
  return 0;
}