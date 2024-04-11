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

const int MAXN = 2e5 + 10;

vii g[MAXN];
int n;

bool read() {
  if  (scanf("%d", &n) < 1) {
    return false;
  }
  forn(i, n) {
    g[i].clear();
  }
  forn(i, n - 1) {
    int a, b;
    scanf("%d%d", &a, &b);
    --a;
    --b;
    g[a].pb(mp(b, i));
    g[b].pb(mp(a, i));
  }
  return true;
}

int dp[MAXN];

vi who[MAXN];

void dfs(int v, int p) {
  int mx = 0;
  int sons = 0;
  for (auto e : g[v]) {
    int to = e.fst;
    if  (to == p) {
      continue;
    }
    dfs(to, v);
    mx = max(mx, dp[to]);
    ++sons;
  }

  if  (sons < mx) {
    dp[v] = mx;
  } else if  (sons == mx) {
    dp[v] = mx + 1;  
  } else {
    // sons > mx
    dp[v] = sons + 1;
  }
}

void make(int v, int p, int t) {
  int sons = 0;
  int mx = 0;
  for (auto e : g[v]) {
    int to = e.fst;
    if  (to == p) {
      continue;
    }
    ++sons;
    mx = max(mx, dp[to]);
  }

  if  (t >= sons) {
    int tt = 0;
    for (auto e : g[v]) {
      int to = e.fst;
      if (to == p) {
        continue;
      }        
      who[tt].pb(e.snd);
      make(to, v, tt);
      ++tt;
    }
  } else {
    int tt = 0;
    for (auto e : g[v]) {
      int to = e.fst;
      if  (to == p) {
        continue;
      }
      if  (tt == t) {
        ++tt;
      }
      who[tt].pb(e.snd);
      make(to, v, tt);
      ++tt;
    }
  }
}

void solve() {
  int r = 0;
  dfs(r, -1);

  int mx = 0;
  int sons = 0;
  for (auto e : g[r]) {
    int to = e.fst;
    ++sons;
    mx = max(mx, dp[to]);
  }
  dp[r] = max(sons, mx);

  forn(i, n + 1) {
    who[i].clear();
  }

  int t = 0;
  for (auto e : g[r]) {
    who[t].pb(e.snd);
    make(e.fst, r, t);
    ++t;   
  }

  int ans = 0;
  forn(i, n + 1) {
    if  (!who[i].empty()) {
      ans = i + 1;
    }
  }

  printf("%d\n", ans);
  forn(t, ans) {
    printf("%d ", sz(who[t]));
    for (int id : who[t]) {
      printf("%d ", id + 1);
    }
    puts("");
  }
}

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    solve();
  }

#ifdef DEBUG
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}