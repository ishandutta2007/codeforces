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
const int INF = 1e9;

struct SegmTreeMax {
  vector<set<int> > S;
  vi t;
  int sz;

  SegmTreeMax(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;
    t.assign(sz * 2, -INF);
    S.resize(sz);
  }

  void put(int pos, int val) {
    int v = sz + pos;
    S[pos].insert(val);
    t[v] = *S[pos].rbegin();
    v /= 2;
    while (v) {
      t[v] = max(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  void del(int pos, int val) {
    int v = sz + pos;
    S[pos].erase(val);
    t[v] = S[pos].empty() ? -INF : *S[pos].rbegin();
    v /= 2;
    while (v) {
      t[v] = max(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  int get_max(int l, int r) {
    int ans = -INF;
    l += sz;
    r += sz;
    while (l <= r) {
      ans = max(ans, t[l]);
      ans = max(ans, t[r]);
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    return ans;
  }
};

struct SegmTreeMin {
  vector<set<int> > S;
  vi t;
  int sz;

  SegmTreeMin(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;
    t.assign(sz * 2, INF);
    S.resize(sz);
  }

  void put(int pos, int val) {
    int v = sz + pos;
    S[pos].insert(val);
    t[v] = *S[pos].begin();
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  void del(int pos, int val) {
    int v = sz + pos;
    S[pos].erase(val);
    t[v] = S[pos].empty() ? INF : *S[pos].begin();
    v /= 2;
    while (v) {
      t[v] = min(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  int get_min(int l, int r) {
    int ans = INF;
    l += sz;
    r += sz;
    while (l <= r) {
      ans = min(ans, t[l]);
      ans = min(ans, t[r]);
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }
    return ans;
  }
};

const int MAXN = 2e6 + 10;

SegmTreeMax T_max;
SegmTreeMin T_min;

vi left[MAXN];
vi right[MAXN];
int n, c;

int L[MAXN];
int R[MAXN];

void go(int l, int r) {
//  printf("in %d %d\n", l, r);
  
  if  (l == r) {
    return;
  }

  int max_left = -INF;
  for (int b : left[l]) {
    max_left = max(max_left, b);
    T_max.del(b, l);
    T_min.del(b, l);
  }

  int min_right = INF;
  for (int b : right[l]) {
    min_right = min(min_right, b);
    T_max.del(b, l);
    T_min.del(b, l);
  }

  if  (left[l].empty()) {
    R[l] = l + 1;
    go(l + 1, r);
    return;  
  }

  if  (right[l].empty()) {
    L[l] = l + 1;
    go(l + 1, r);
    return;
  }

  while (1) {
    int nmax_left = T_max.get_max(l + 1, max_left);
    if  (nmax_left <= max_left) {
      break;
    }
    max_left = nmax_left;
  }

  while (1) {
    int nmin_right = T_min.get_min(min_right, r);
    if  (nmin_right >= min_right) {
      break;
    }
    min_right = nmin_right;
  }

//  printf("max_left = %d, min_right = %d\n", max_left, min_right);

  if  (max_left >= min_right) {
    puts("IMPOSSIBLE");
    exit(0);
  }

  if  (min_right == l + 1) {
    R[l] = l + 1;
    go(l + 1, r);
    return;
  }

  if  (max_left == r) {
    L[l] = l + 1;
    go(l + 1, r);
    return;
  }

  L[l] = l + 1;
  R[l] = max_left + 1;

  go(l + 1, max_left);
  go(max_left + 1, r);
}

void dfs(int v) {
  if  (v == -1) {
    return;
  }

  dfs(L[v]);

  printf("%d ", v + 1);

  dfs(R[v]);
}

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  cin >> n >> c;

//  printf("n = %d, c = %d\n", n, c);
  T_max = SegmTreeMax(n + 10);
  T_min = SegmTreeMin(n + 10);

  forn(i, c) {
    int a, b;
    char buf[10];
    scanf("%d %d %s\n", &a, &b, buf);
    --a;
    --b;
              
    if  (b <= a) {
      puts("IMPOSSIBLE");
      return 0;
    }

    if  (buf[0] == 'L') {
      left[a].pb(b);
    } else {
      right[a].pb(b);
    } 

    T_max.put(a, b);
    T_min.put(a, b);

    T_max.put(b, a);
    T_min.put(b, a);
  }

  memset (L, -1, sizeof L);
  memset (R, -1, sizeof R);

  go(0, n - 1);

  dfs(0);

  return 0;
}