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

#define debug(x) cerr << #x" = " << x << '\n';

template <typename T>
inline T sqr(T x) {
  return x * x;
}

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;
typedef vector <vector <int> > vvi;
typedef vector <pii> vii;

const double EPS = 1e-9;
const int MAXN = 1e5 + 10;

map<pii, int> id;

set<int> g[MAXN];
set<int> gt[MAXN];
int n;

void addE(int v, int to) {
//  printf("%d -> %d\n", v, to);

  g[v].insert(to);
  gt[to].insert(v);
}

set<int> can;

void update(int v) {
  bool ok = true;
  for (int from : gt[v]) {
    if  (sz(g[from]) == 1) {
      ok = false;
    }
  }

  if  (ok) {
    can.insert(v);
  } else {
    can.erase(v);
  }
}

int main() {  
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    int x, y;
    scanf("%d%d", &x, &y);
    id[mp(x, y)] = i;
  }

  for (auto p : id) {
    int x = p.fst.fst;
    int y = p.fst.snd;
    int i = p.snd;

    if  (id.count(mp(x - 1, y - 1))) {
      addE(i, id[mp(x - 1, y - 1)]);
    }

    if  (id.count(mp(x, y - 1))) {
      addE(i, id[mp(x, y - 1)]);
    }

    if  (id.count(mp(x + 1, y - 1))) {
      addE(i, id[mp(x + 1, y - 1)]);
    }
  }

  vi ans;

  forn(v, n) {
    can.insert(v);
  }
  forn(v, n) {
    update(v);
  }

  int step = 0;
  while (!can.empty()) {
    /*
    for (int v : can) {
      printf("%d ", v);
    }
    puts("");
    */

    int v = -1;
    
    if  (step & 1) {
      v = *can.begin();
    } else {
      v = *can.rbegin();
    }
    ++step;
    can.erase(v);

//    printf("v = %d\n", v);
    ans.pb(v);

    vi from;
    for (int fr : gt[v]) {
      from.pb(fr);
      g[fr].erase(v);
    }

    vi to;
    for (int t : g[v]) {
      to.pb(t);
      gt[t].erase(v);
    }

    for (int fr : from) {
      for (int tt : g[fr]) {
        update(tt);
      }
      update(fr);
    }

    for (int t : to) {
      update(t);
    }

    g[v].clear();
    gt[v].clear();
  }

  reverse(all(ans));
  int base = n;

  int coef = 1;
  int sum = 0;

  const int MOD = 1e9 + 9;

  for (int x : ans) {
    sum = (sum + x * 1ll * coef) % MOD;
    coef = (coef * 1ll * base) % MOD;
  }

  cout << sum << endl;
  return 0;
}