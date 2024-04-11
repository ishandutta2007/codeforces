#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define mp make_pair 
#define sz(A) ((int)(A).size())
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke
#define all(A) A.begin(), A.end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = 1010;

ll a[MAXN][MAXN];
ll b[MAXN][MAXN];
ll c[MAXN][MAXN];
ll d[MAXN][MAXN];

//query[x][y] = a + b * x + c * y + d * x * y

ll mul (ll v, int C) {
  return v * (C & 1);  
}

void upd (ll f[MAXN][MAXN], int x, int y, ll v) {
  for (int i = x; i < MAXN; i = (i | (i + 1)))
    for (int j = y; j < MAXN; j = (j | (j + 1)))
      f[i][j] ^= v;  
}

ll get (ll f[MAXN][MAXN], int x, int y) {
  ll res = 0;
  for (int i = x; i >= 0; i = (i & (i + 1)) - 1)
    for (int j = y; j >= 0; j = (j & (j + 1)) - 1)
      res ^= f[i][j];
  return res;
}

void upd_sq (ll f[MAXN][MAXN], int x1, int y1, int x2, int y2, ll v) {
  upd(f, x1, y1, v);
  upd(f, x2 + 1, y1, v);
  upd(f, x1, y2 + 1, v);
  upd(f, x2 + 1, y2 + 1, v);
}

void go_xor (int x, int y, ll v) {
  upd_sq(d, 0, 0, x, y, v);

  upd_sq(b, 0, y + 1, x, MAXN - 1, mul(v, y + 1));

  upd_sq(c, x + 1, 0, MAXN - 1, y, mul(v, x + 1));

  upd_sq(a, x + 1, y + 1, MAXN - 1, MAXN - 1, mul(v, (x + 1) * (y + 1)));  
}

ll get_xor (int x, int y) {
  return get(a, x, y) ^ mul(get(b, x, y), x + 1) ^ mul(get(c, x, y), y + 1) ^ mul(get(d, x, y), (x + 1) * (y + 1));
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset (a, 0, sizeof a);
  memset (b, 0, sizeof b);
  memset (c, 0, sizeof c);
  memset (d, 0, sizeof d);

  int n, m;
  scanf("%d%d", &n, &m);
  while (m --> 0) {
    int t, x1, y1, x2, y2;
    scanf("%d", &t);

    if  (t == 1) {
      scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
      x1--; y1--;
      x2--; y2--;

      ll ans = get_xor(x2, y2);
      if  (x1) ans ^= get_xor(x1 - 1, y2);
      if  (y1) ans ^= get_xor(x2, y1 - 1);
      if  (x1 && y1) ans ^= get_xor(x1 - 1, y1 - 1);

      printf("%I64d\n", ans); 
    } else {
      ll v;
      scanf("%d%d%d%d%I64d", &x1, &y1, &x2, &y2, &v);
      x1--; y1--;
      x2--; y2--;

      go_xor(x2, y2, v);
      if  (x1) go_xor(x1 - 1, y2, v);
      if  (y1) go_xor(x2, y1 - 1, v);
      if  (x1 && y1) go_xor(x1 - 1, y1 - 1, v);
    }
  }

  return 0;
}