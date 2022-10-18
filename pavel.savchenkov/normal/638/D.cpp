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

const int MAXN = 1e2 + 10;

int n, m, k;
bool alive[MAXN * MAXN * MAXN];

int code(int x, int y, int z) {
  return x * m * k + y * k + z;
}

bool read() {
  if  (scanf("%d%d%d\n", &n, &m, &k) < 3) {
    return false;
  }
  memset (alive, 1, sizeof alive);
  forn(x, n) {
    scanf("\n");
    forn(y, m) {
      static char s[MAXN];
      gets(s);
      forn(z, k) {
        alive[code(x, y, z)] = s[z] == '1';
      }
    }           
  }
  return true;
}

vi g[MAXN * MAXN * MAXN];
vi gt[MAXN * MAXN * MAXN];

bool path(int v, int to) {
  for (int u : g[v]) {
    if  (!alive[u]) {
      continue;
    }
    for (int to_u : g[u]) {
      if  (alive[to_u] && to_u == to) return true;
    } 
  } 
  return false;
}

bool check(int v) {
  alive[v] = false;
  for (int from : gt[v]) {
    for (int to : g[v]) {
      if  (!path(from, to)) {
        alive[v] = true;
        return true; 
      } 
    }
  } 
  alive[v] = true;
  return false;
}

void addE(int v, int to) {
  if  (!alive[to]) {
    return;
  }
  g[v].pb(to);
  gt[to].pb(v);
}           

int solve() {
  forn(x, n) forn(y, m) forn(z, k) {
    int v = code(x, y, z);
    if  (!alive[v]) {
      continue;
    }
    if  (x + 1 < n) {
      addE(v, code(x + 1, y, z));
    }
    if (y + 1 < m) {
      addE(v, code(x, y + 1, z));
    }
    if  (z + 1 < k) {
      addE(v, code(x, y, z + 1));
    }
  }

  int ans = 0;
  forn(i, n * m * k) {
    if  (alive[i]) {
      ans += check(i);
    }
  }
  return ans;
}                            

int main() {
#ifdef LOCAL
  freopen(FILE_NAME ".in", "r", stdin);
  //freopen(FILE_NAME ".out", "w", stdout);
#endif

  while (read()) {
    printf("%d\n", solve());
  }

#ifdef DEBUG
  cerr << "Time: " << (double) clock() / CLOCKS_PER_SEC << endl;
#endif
  return 0;
}