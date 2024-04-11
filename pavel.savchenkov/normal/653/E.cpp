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
#include <fstream>
#include <unordered_map>
#include <unordered_set>

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
typedef pair<int,int> pii;
typedef pair<ll, ll> pll;
typedef vector<ll> vll;
typedef vector<int> vi;
typedef vector<vector <int> > vvi;
typedef vector<pii> vii;
typedef long double ld;
typedef complex<double> cd;
typedef vector<cd> vcd;

#define FILE_NAME ""

const int MAXN = 3e5 + 10;

unordered_map<int, int> g[MAXN];
int n, m, k;

bool read() {
  if  (scanf("%d%d%d", &n, &m, &k) < 3) {
    return false;
  }
  forn(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a][b] = 1;
    g[b][a] = 1;
  }
  return true;
}

int par[MAXN];
int cnt_ok;

set<int> alive;
set<int> alive0;

int get_set(int x) {
  return par[x] < 0 ? x : par[x] = get_set(par[x]);
}

void unite(int x, int y) {
  x = get_set(x);
  y = get_set(y);
  assert(x != y);
  if  (sz(g[x]) < sz(g[y])) {
    swap(x, y);
  }

  par[x] += par[y];
  par[y] = x;

  if  (!alive0.count(y)) {
    alive0.erase(x);
  }
  
  alive0.erase(y);
  alive.erase(y);
         
  g[x].erase(y);
  g[y].erase(x);
  for (const auto& it : g[y]) {
    int to = it.fst;
    int cnt = it.snd;
    g[x][to] += cnt;
    g[to][x] += cnt;
    g[to].erase(y);  
  }
  g[y].clear();
}

bool solve() {    
  forn(i, n) par[i] = -1;

  cnt_ok = 0;
  for (int i = 1; i < n; ++i) {
    cnt_ok += !g[i].count(0);
  } 

  if  (cnt_ok < k) return false;

  alive.clear();
  for (int i = 1; i < n; ++i) {
    alive.insert(i);
  }
  alive0.clear();
  for (int i = 1; i < n; ++i) {
    if  (g[i].count(0))
      alive0.insert(i);
  }

  while (!alive0.empty()) {
    int v = *alive0.begin();
    bool ok = false;
    for (int to : alive) {
      if  (to == v) {
        continue;
      }
      if  (!g[v].count(to) || g[v][to] < -par[v] * 1ll * -par[to]) {
        unite(v, to);
        ok = true;
        break;
      } 
    }         
    if  (!ok) {
 //     cerr << "gfdgf" << endl;
      return false;
    }
  }

  while (sz(alive) > k) {
    int v = *alive.begin();
    bool ok = false;
    for (int to : alive) {
      if  (to == v) {
        continue;
      }
      if  (!g[v].count(to) || g[v][to] < -par[v] * 1ll * -par[to]) {
        unite(v, to);
        ok = true;
        break;
      } 
    }         
    if  (!ok) {   
 //     cerr << "dsfgsd" << endl;
      return false;
    }   
  }

  int cnt = 0;
  for (int i = 1; i < n; ++i) {
    if  (get_set(i) == i) {
      assert(alive.find(i) != alive.end());
      if  (g[i][0] == -par[i]) return false;
      ++cnt;
    }
  }

//  cerr << cnt << endl;

  return cnt == k;
}
           
int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    puts(solve() ? "possible" : "impossible");
  }

#ifdef DEBUG
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}