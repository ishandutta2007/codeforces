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
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MOD = 1000000007;
const int MAXN = (int) 1e5 + 10;

int mul (int a, int b) {
  ll m = 1ll * a * b;
  m %= 1ll * MOD;
  return (int) m;
}

int add (int a, int b) {
  a += b;
  if  (a >= MOD) a -= MOD;
  return a;
}

int mpow (int a, int p) {
  int res = 1;

  while (p > 0) {
    if  (p & 1) res = mul(res, a);
    p /= 2; a = mul(a, a);
  }

  return res;
}

int f[MAXN];
int invf[MAXN];

int C (int n, int k) {
  int ret = mul(f[n], invf[n - k]);
  return mul(ret, invf[k]);
}

int n;

int calc (int cnt0) {
  int cnt = n - cnt0;

  return mul(C(n, cnt0), C(n - 1, cnt - 1));
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

  f[0] = 1; invf[0] = 1;
  for (int i = 1; i <= (int) 1e5; i++) {
    f[i] = mul(i, f[i - 1]);
    invf[i] = mpow(f[i], MOD - 2);
  }

  int res = 0;
  scanf("%d", &n);

  for (int i = 0; i < n; i++)
    res = add(res, calc(i));

  res = mul(res, 2ll);
  
  printf("%d\n", (res - n + MOD) % MOD);
  return 0;
}