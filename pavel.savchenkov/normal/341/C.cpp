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
const int MAXN = 2010;
const int MOD = 1000000007;

int mul (int a, int b) {
  ll M = 1ll * a * b;
  return int(M % ll(MOD));
}

int add (int a, int b) {
  a += b;

  if  (a >= MOD)
    a -= MOD;

  return a;
}

int mpow (int a, int p) {
  int res = 1;

  while (p > 0) {
    if  (p & 1)
      res = mul(res, a);

    a = mul(a, a);
    p /= 2;
  }

  return res;
}

bool was[MAXN];
int a[MAXN];
int n, m;
int f[MAXN];
int invf[MAXN];
int Bad;

int C (int n, int k) {
  int res = mul(f[n], invf[k]);
  return mul(res, invf[n - k]);
}

map <int, int> dp;

int solve (int bad) {
  if  (dp.count(bad))
    return dp[bad];

  int all = m - (Bad - bad);

//  printf("all = %d bad = %d\n", all, bad);

  if  (bad == 0)
    return dp[bad] = 1;

  int has = 0;
  for (int cnt = 1; cnt <= bad; cnt++) {
    int toadd = mul(C(bad, cnt), solve(bad - cnt));
    has = add(has, toadd);      
  }

  return dp[bad] = add(mul(f[all], invf[all - bad]), -has + MOD);
}

int main() {
  f[0] = 1;
  invf[0] = 1;
  for (int i = 1; i < MAXN; i++) {
    f[i] = mul(i, f[i - 1]);
    invf[i] = mpow(f[i], MOD - 2);
  }

  scanf("%d", &n);
  m = 0;
  forn(i, n) {
    scanf("%d", &a[i]);

    if  (a[i] != -1)
      was[a[i] - 1] = true;
    else
      m++;
  }

  Bad = 0;
  forn(i, n)
    if  (a[i] == -1 && !was[i])
      Bad++;

  int ans = solve(Bad);
  ans = mul(ans, f[m - Bad]);

  printf("%d\n", ans);
  return 0;
}