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

#define set set_aaa

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

const int MAXN = 200100;

const char* chars = "ATGC";

typedef unsigned int uint;

vector<int> read(){
  static char buf[MAXN];
  scanf("%s", buf);
  vector<int> res(strlen(buf));
  for (int i = 0; i < (int)res.size(); i++){
    res[i] = strchr(chars, buf[i]) - chars;
  }
  return res;
}

uint masks[4][32][MAXN / 32];
uint maskt[4][MAXN / 32];

void set(uint mask[][MAXN / 32], int id){
  for (int shift = 0; shift < 32; shift++){
    mask[shift][(id + shift) / 32] |= 1u << ((id + shift) & 31);
  }
}

bool check(uint* masks, uint* maskt, int cnt){
  for (int i = 0; i < cnt; i++){
    if (masks[i] & maskt[i]) 
      return 0;
  }
  return 1;
}

int main(){
  #ifdef LOCAL
    assert(freopen(TASKNAME".in","r",stdin));
    assert(freopen(TASKNAME".out","w",stdout));
  #endif

  int n, m, k;
  scanf("%d%d%d",&n,&m,&k);

  vector<int> s = read();
  vector<int> t = read();
  assert((int)s.size() == n);
  assert((int)t.size() == m);

  for (int i = 0; i < 4; i++){
    int last = - k - 1;
    for (int j = 0; j < n; j++){
      if (s[j] == i) last = j;
      if (last >= j - k){
        set(masks[i], j);
      }
    }
    last = n + k;
    for (int j = n - 1; j >= 0; j--){
      if (s[j] == i) last = j;
      if (last <= j + k){
        set(masks[i], j);
      }
    }
  }

  for (int a = 0; a < 4; a++)
    for (int i = 0; i < 32; i++)
      for (int j = 0; j <= (n + 31)/ 32; j++)
        masks[a][i][j] ^= -1;

  for (int i = 0; i < m; i++)
    maskt[t[i]][i / 32] |= (1<<(i & 31));

  int ans = 0;

  for (int i = 0; i <= n - m; i++){
    for (int j = 0; j <= 4; j++){
      if (j == 4) {
        ans++;
      } else {
        if (!check(masks[j][-i & 31] + (i + (-i & 31)) / 32 , maskt[j], (m + 31) / 32))
          break;
      }
    }
  }

  printf("%d\n", ans);
      
  return 0;
}