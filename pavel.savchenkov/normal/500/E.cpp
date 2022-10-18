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
#define f first
#define s second
#define mp make_pair 
#define sz(C) ((int) (C).size())
#define forn(i, n) for (int i = 0; i < (int) n; ++i)
#define ford(i, n) for (int i = ((int) n) - 1; i >= 0; --i)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define left sdhfsjkshdjkfsdfgkqqweqweh
#define right yytrwtretywretwreytwreytwr
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

struct SegmTree {
  vi t;
  int sz;

  SegmTree(int n = 0) {
    sz = 1;
    while (sz < n) sz *= 2;
    t.assign(sz * 2, -1);
  }

  void put(int pos, int val) {
    int v = sz + pos;
    t[v] = val;
    v /= 2;
    while (v) {
      t[v] = max(t[v * 2], t[v * 2 + 1]);
      v /= 2;
    }
  }

  int get(int l, int r) {
    int res = -1;
    l += sz;
    r += sz;

    while (l <= r) {
      res = max(res, t[l]);
      res = max(res, t[r]);
      l = (l + 1) / 2;
      r = (r - 1) / 2;
    }

    return res;
  }
};

const int MAXN = 2e5 + 10;

int cover[MAXN];
int len[MAXN];
int p[MAXN];
int l[MAXN];
int n;

int cost[MAXN][25];
int who[MAXN][25];

int main() {
#ifdef LOCAL
  freopen(".in", "r", stdin);
//  freopen(".out", "w", stdout);
#endif

  scanf("%d", &n);
  forn(i, n) {
    scanf("%d%d", &p[i], &l[i]);
  }

  SegmTree T_cover(n);
  SegmTree T_len(n);

  len[n - 1] = p[n - 1] + l[n - 1];
  cover[n - 1] = n - 1;
  T_cover.put(n - 1, cover[n - 1]);

  ford(i, n - 1) {
    int j = upper_bound(p, p + n, p[i] + l[i]) - p;
    --j;

    cover[i] = max(i, T_cover.get(i, j));
    len[i] = max(p[i] + l[i], T_len.get(i, j));

    T_cover.put(i, cover[i]);
    T_len.put(i, len[i]); 
  }

  int logN = 1;
  while ((1 << logN) <= n) ++logN;

  ford(i, n) {
    int j = cover[i];
    if  (j == n - 1) {
      forn(k, logN + 1) {
        cost[i][k] = 0;
        who[i][k] = n - 1;
      }
      continue;
    }

    cost[i][0] = p[j + 1] - len[i];
    who[i][0] = j + 1;
    for (int k = 1; k <= logN; ++k) {
      cost[i][k] = cost[i][k - 1] + cost[who[i][k - 1]][k - 1];
      who[i][k] = who[who[i][k - 1]][k - 1];
    }
  }

  int q;
  scanf("%d", &q);
  while (q --> 0) {
    int l, r;
    scanf("%d%d", &l, &r);
    --l;
    --r;

    if  (cover[l] >= r) {
      puts("0");
      continue;
    }

    int res = 0;
    for (int k = logN; k >= 0; --k) {
      int j = who[l][k];

      if  (cover[j] < r) {
        res += cost[l][k];
        l = j;
      } 
    }

    res += cost[l][0];

    printf("%d\n", res);
  }

  return 0;
}