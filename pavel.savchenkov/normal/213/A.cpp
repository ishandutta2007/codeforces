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
const int MAXN = 200 + 10;

int deg[MAXN];
int c[MAXN];
vi g[MAXN];
int n;
bool ready[MAXN];

bool make(int C, int& ans) {
  bool was = false;
  forn(v, n) {
    if  (!ready[v] && c[v] == C && deg[v] == 0) {
      ++ans;
      was = true;
      for (int to : g[v]) {
        --deg[to];
      }
      ready[v] = true;
    }
  }
  return was;
}

int solve(int C) {
  memset (ready, false, sizeof ready);
  vi old_deg(n);
  forn(v, n) {
    old_deg[v] = deg[v];
  }

  int ans = 0;
  while (1) {
    while (make(C, ans)) {}

    bool was = false;
    forn(v, n) {
      if  (!ready[v]) {
        was = true;
      }
    }

    if  (!was) {
      break;
    }

    C = (C + 1) % 3;
    ++ans;
  }

  forn(v, n) {
    deg[v] = old_deg[v];
  }

  return ans;
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", &c[i]);
    --c[i];
  }

  forn(i, n) {
    int k;
    scanf("%d", &k);
    forn(j, k) {
      int from;
      scanf("%d", &from);
      --from;
      g[from].pb(i);
      ++deg[i];
    }
  }

  printf("%d\n", min(solve(0), min(solve(1), solve(2))));
  return 0;
}