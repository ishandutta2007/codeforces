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
const int MOD = 1000000007;
const int MAXN = int(1e6) + 10;

int add (int a, int b) {
  a += b;
  if  (a >= MOD) a -= MOD;
  return a;
}

int mul (int a, int b) {
  ll M = 1ll * a * b;
  M %= 1ll * MOD;
  return int(M);
}

int mpow (int a, int p) {
  int res = 1;
  while (p > 0) {
    if  (p & 1) res = mul(res, a);
    p /= 2; a = mul(a, a);
  }
  return res;
}

int n;
int a, b;
int f[MAXN];
int invf[MAXN];

int C (int n, int k) {
  int ret = mul(f[n], invf[n - k]);
  return mul(ret, invf[k]);
}

bool good (int sum) {
  while (sum > 0) {
    if  (sum % 10 != a && sum % 10 != b) return false;
    sum /= 10;
  }
  return true;
}

int go (int ca) {
  int sum = ca * a + (n - ca) * b;
  if  (!good(sum)) return 0;

  return C(n, ca);
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d %d", &a, &b, &n);

  f[0] = 1; invf[0] = 1;
  for (int i = 1; i <= n; i++) {
    f[i] = mul(f[i - 1], i);
    invf[i] = mpow(f[i], MOD - 2);
  }

  int res = 0;
  for (int cnta = 0; cnta <= n; cnta++)
    res = add(res, go(cnta));

  printf("%d\n", res);
  return 0;
}