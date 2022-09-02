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

vector<vector<vector<int>>> g;

vector<string> s;

void build(int aid, int bid, vector<vector<int>> &ga) {
  string str = s[bid] + '$' + s[aid];
  vector<int> p(str.size());
//  if (aid != bid) {
    ga[0].push_back(bid);
//  }
  for (int i = 1; i < (int)str.size(); i++) {
    int j = p[i - 1];
    while (j && str[i] != str[j]) {
      j = p[j - 1];
    }
    if (str[i] == str[j]) j++;
    p[i] = j;
    if (p[i] == (int)s[bid].size() && (s[aid].size() != s[bid].size() || j != (int)s[aid].size())) {
      int len = (int) (str.size()) - i + (int)(s[bid].size()) - 1;
      assert(len >= 0 && len <= (int)s[aid].size());
      ga[len].push_back(bid);
//      fprintf(stderr, "%d,%d match %d\n", aid, len, bid);
    }
  }

  int j = p.back();

  if (j == (int)s[bid].size()) {
    j = p[j - 1];
  }

  while (j) {
    ga[j].push_back(bid);
//    fprintf(stderr, "%d,%d match %d\n", aid, j, bid);
    j = p[j - 1];
  }
}

vector<bool> enabled;
vector<vector<int>> used;
int n;

bool dfs(int id, int len) {
  if (used[id][len] == 1) return true;
  if (used[id][len] == 2) return false;
  used[id][len] = 1;
  for (int nid : g[id][len]) {
    if (enabled[nid]) {
      if (len >= (int) s[nid].size()) {
//        eprintf("%d,%d->%d,%d\n", id, len, id, len - (int) s[nid].size());
        if (dfs(id, len - (int) s[nid].size())) {
          return true;
        }
      } else {
//        eprintf("%d,%d->%d,%d\n", id, len, nid, - len + (int) s[nid].size());
        if (dfs(nid, (int) s[nid].size() - len)) {
          return true;
        }
      }
    }
  }
  used[id][len] = 2;
  return false;
}

bool check() {
//  eprintf( "check\n");
  for (int i = 0; i < n; i++) {
    used[i] = vector<int>(s[i].size() + 1, 0);
  }
  for (int i = 0; i < n; i++) {
    if (enabled[i]) {
      for (int j = 0; j <= (int)s[i].size(); j++) {
//        eprintf("dfs\n");
        if (dfs(i, j)) {
          return false;
        }
      }
    }
  }
  return true;
}

int main() {
#ifdef LOCAL
  assert(freopen(TASKNAME".in", "r", stdin));
  assert(freopen(TASKNAME".out", "w", stdout));
#endif

  cin >> n;
  s.resize(n);
  g.resize(n);
  enabled.resize(n);
  used.resize(n);
  for (int i = 0; i < n; i++) {
    cin >> s[i];
    g[i].resize(s[i].size() + 1);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      build(i, j, g[i]);
    }
  }

  int ans = 0;
  int ptr = 0;
  for (int i = 0; i < n; i++) {
    enabled[i] = 1;
    while (!check()) {
      enabled[ptr++] = 0;
      assert(ptr <= i + 1);
    }
//    eprintf("%d..%d\n", ptr, i);
    ans += i - ptr + 1;
  }

  printf("%d\n", ans);
  return 0;
}