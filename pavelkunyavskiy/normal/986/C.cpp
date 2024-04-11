#include <iostream>
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

#ifdef LOCAL
#define eprintf(...) fprintf(stderr,__VA_ARGS__)
#else
#define eprintf(...)
#endif

#define TIMESTAMP(x) eprintf("["#x"] Time : %.3lf s.\n", clock()*1.0/CLOCKS_PER_SEC)
#define TIMESTAMPf(x,...) eprintf("[" x "] Time : %.3lf s.\n", __VA_ARGS__, clock()*1.0/CLOCKS_PER_SEC)

using namespace std;

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

const int N = 22;

bool have[1 << N];
bool used[1 << (N + 1)];
vector<int> ts;

void dfs_ts(int v) {
  if (used[v]) return;
//  eprintf("ts +%d\n", v);
  used[v] = true;
  if (v & (1 << N)) {
    for (int i = 0; i <= N; i++) {
      dfs_ts(v & ~(1 << i));
    }
  } else {
    dfs_ts(v ^ ((1 << (N + 1)) - 1));
  }
  ts.push_back(v);
//  eprintf("ts -%d\n", v);
}

bool any_small;

void dfs(int v) {
  if (used[v]) return;
//  eprintf("bk +%d\n", v);
  used[v] = true;
  if (v & (1 << N)) {
    dfs(v ^ ((1 << (N + 1)) - 1));
    for (int i = 0; i < N; i++) {
      dfs(v | (1 << i));
    }
  } else {
    any_small = true;
    dfs(v ^ (1 << N));
  }
//  eprintf("bk -%d\n", v);
}

int main() {
#ifdef LOCAL
  freopen("c.in", "r", stdin);
  freopen("c.out", "w", stdout);
#endif

  int n;
  while (scanf("%*d%d", &n) == 1) {
    memset(have, 0, sizeof(have));
    for (int i = 0; i < n; i++) {
      int a;
      scanf("%d", &a);
      have[a] = true;
    }
    memset(used, 0, sizeof(used));
    for (int i = 0; i < (1 << N); i++) {
      if (!have[i]) {
        used[i] = true;
      }
    }
    for (int i = 0; i < (1 << (N + 1)); i++) {
      dfs_ts(i);
    }

    reverse(ts.begin(), ts.end());

    memset(used, 0, sizeof(used));
    for (int i = 0; i < (1 << N); i++) {
      if (!have[i]) {
        used[i] = true;
      }
    }
    int ans = 0;
    for (int x : ts) {
      any_small = false;
      dfs(x);
      ans += any_small;
    }
    printf("%d\n", ans);
//    break;
  }

  return 0;
}