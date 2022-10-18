#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <cstdlib>
#include <memory>
#include <queue>
#include <cassert>
#include <cmath>
#include <ctime>
#include <complex>
#include <bitset>

using namespace std;

#define pb push_back
#define fst first
#define snd second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
#define next jskdfksdhfjkdsjksdjkgf
#define prev koeuigrihjdkjdfj
#define hash kjfdkljkdhgjdkfhgurehg
#define all(C) begin(C), end(C)

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const ld EPS = 1e-9;
const int MAXN = 2e5 + 10;

int pos[MAXN];
int pos_neg[MAXN];
vi v[MAXN];
int n, m;
bool ready[MAXN]; // 0 .. n - 1
bool used[MAXN]; // 0 .. m - 1
int val[MAXN];
int Pos[MAXN];
int Pos_neg[MAXN];

bool read() {
  if  (scanf("%d%d", &n, &m) < 2) {
    return false;
  }
  forn(i, n) {
    int k;
    scanf("%d", &k);
    forn(j, k) {
      int who;
      scanf("%d", &who);
      v[i].pb(who);
    }
  }
  return true;
}

void dfs(int i) {
  if  (used[i]) {
    return;
  }
  used[i] = true;

  if  (pos[i] != -1) {
    val[i] = 1;
    ready[pos[i]] = true;
    for (int who : v[pos[i]]) {
      int j = abs(who) - 1;
      if  (used[j]) {
        continue;
      }
      if  (pos[j] == pos[i]) {
        pos[j] = -1;
        if  (pos_neg[j] == -1) {
          continue;
        }
        dfs(j);
      } else {
        pos_neg[j] = -1;
        if  (pos[j] == -1) {
          continue;
        }
        dfs(j);
      }
    }
  } else {
    assert(pos_neg[i] != -1);
    ready[pos_neg[i]] = true;
    for (int who : v[pos_neg[i]]) {
      int j = abs(who) - 1;
      if  (used[j]) {
        continue;
      } 
      if  (pos[j] == pos_neg[i]) {
        pos[j] = -1;
        if  (pos_neg[j] == -1) {
          continue;
        }
        dfs(j);
      } else {
        pos_neg[j] = -1;
        if  (pos[j] == -1) {
          continue;
        }
        dfs(j);
      }
    }
  }
}

vi g[MAXN];
vi var[MAXN];
vi id[MAXN];
int es;

vi vect_pos[MAXN];
vi vect_pos_neg[MAXN];

void addE(int a, int b, int v) {
//  printf("%d <-> %d, var=%d\n", a, b, v);

  g[a].pb(b);
  id[a].pb(es);
  var[a].pb(v);

  g[b].pb(a);
  id[b].pb(es);
  var[b].pb(v);
  ++es;
}

int col[MAXN];
vi st;
vi cycle;

void dfs_cycle(int v, int prev_id = -1) {
  if  (!cycle.empty()) {
    return;
  }
  st.pb(v);
//  printf("push %d\n", v);
  col[v] = 1;
  forn(i, sz(g[v])) {
    int to = g[v][i];
    int id_to = id[v][i];
    if  (!cycle.empty()) {
      return;
    }
    if  (id_to == prev_id) {
      continue;
    }
    if  (!col[to]) {
      dfs_cycle(to, id_to);
      continue;
    }
    if  (col[to] == 2) {
      continue;
    }
    /*
    printf("cycle found: v=%d, to=%d\n", v, to);
    printf("st:");
    for (int x : st) printf("%d ", x);
    puts("");
    */
    while (st.back() != to) {
      cycle.pb(st.back());
      st.pop_back();
      assert(!st.empty());
    }
    cycle.pb(to);
    return;
  }

  st.pop_back();
//  printf("pop %d\n", v);
  col[v] = 2;
}

void NO() {
  puts("NO");
  exit(0);
}

void assign(int v, int, int va) {
  assert(!used[va]);
  used[va] = true;
//  printf("assign v=%d, var=%d, pos[var]=%d\n", v, va, pos[va]);
  if  (Pos[va] == v) {
    val[va] = 1;
  } else {
    assert(Pos_neg[va] == v);
    val[va] = 0;
  }
}

void dfs2(int v) {
  ready[v] = true;

  forn(i, sz(g[v])) {
    int to = g[v][i];
    if  (ready[to]) {
      continue;
    }
    if  (used[var[v][i]]) {
      continue;
    }
    assign(to, v, var[v][i]);
    dfs2(to);
  }
}

void make(int v) {
  cycle.clear();
  st.clear();

  // col[*] = 0
  dfs_cycle(v);    

  if  (cycle.empty()) {
    NO();
  }

 /* 
  puts("cycle:");
  for (int v : cycle) {
    printf("%d ", v);
  }
  puts("");
 */
  forn(i, sz(cycle)) {
    ready[cycle[i]] = true;
    int v = cycle[i];
    int to = cycle[(i + 1) % sz(cycle)];
    bool was = false;
    forn(j, sz(g[v])) {
      if  (g[v][j] == to && !used[var[v][j]]) {
        assign(v, to, var[v][j]);
        was = true;
        break;
      }
    }
    assert(was);
  }

  for (int v : cycle) {
    dfs2(v);
  }
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
//  freopen(FILE_NAME ".out", "w", stdout);
#endif

  assert(read());

  memset (pos, -1, sizeof pos);
  memset (pos_neg, -1, sizeof pos_neg);

  forn(i, n) {
    for (int who : v[i]) {
      if  (who < 0) {
        pos_neg[-who - 1] = i;
        vect_pos_neg[-who - 1].pb(i);
      } else {
        pos[who - 1] = i;
        vect_pos[who - 1].pb(i);
      }
    }
  }

  forn(i, m) {
    Pos[i] = pos[i];
    Pos_neg[i] = pos_neg[i];
  }

  memset (used, false, sizeof used);

  forn(i, m) {
    if  (sz(vect_pos[i]) == 2 || sz(vect_pos_neg[i]) == 2) {
      if  (sz(vect_pos[i]) == 2) {
        val[i] = 1;
      }
      used[i] = true;
      for (int j : vect_pos[i]) {
        ready[j] = true;
        for (int who : v[j]) {
          if  (who > 0) {
            pos[who - 1] = -1;
          } else {
            pos_neg[-who - 1] = -1;
          }
        }
      }
      for (int j : vect_pos_neg[i]) {
        ready[j] = true;
        for (int who : v[j]) {
          if  (who > 0) {
            pos[who - 1] = -1;
          } else {
            pos_neg[-who - 1] = -1;
          }
        }
      }
    }       
  }

  forn(i, m) {
    if  (pos[i] == -1 && pos_neg[i] == - 1) {
      continue;
    }
    
    if  (pos[i] != -1 && pos_neg[i] != -1) {
      continue;
    }

    dfs(i);
  }

  /*
  puts("ready:");
  forn(i, n) {
    printf("%d ", ready[i]);
  }
  puts("");
  */

  forn(i, m) {
    if  (pos[i] == -1 || pos_neg[i] == -1) {
      continue;
    }
    addE(pos[i], pos_neg[i], i);
  }

  forn(i, n) {
    if  (!ready[i]) {
      make(i);
    }
  }

  /*
  puts("final ready:");
  forn(i, n) {
    printf("%d ", ready[i]);
  }
  puts("");
  */

  puts("YES");
  forn(i, m) {
    printf("%d", val[i]);
  }
  puts("");

  return 0;
}