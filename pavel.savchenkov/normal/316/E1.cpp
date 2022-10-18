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

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;
const int MOD = int(1e9);

int add (int a, int b) {
  a += b;
  if  (a >= MOD)
    a -= MOD;
  return a;
}

int mul (int a, int b) {
  ll M = 1ll * a * b;
  M %= ll(MOD);
  return int(M);
}

int a[MAXN];
int f[MAXN];
int n, m;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d", &n, &m);
  f[0] = f[1] = 1;
  for (int i = 2; i <= n; i++)
    f[i] = add(f[i - 1], f[i - 2]);

  forn(i, n)
    scanf("%d", &a[i]);

  forn(i, m) {
    int t; scanf("%d", &t);
    if  (t == 1) {
      int x, v;
      scanf("%d %d", &x, &v);
      a[x - 1] = v;
    } else {
      int l, r; scanf("%d %d", &l, &r);
      l--; r--;
      int res = 0;
      for (int j = 0; j <= r - l; j++)
        res = add(res, mul(f[j], a[l + j]));
      printf("%d\n", res);
    }
  }

  return 0;
}