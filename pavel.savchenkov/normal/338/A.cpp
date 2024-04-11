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
const int MOD = 1000000009;

int n, m, k;

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

int main() {
  scanf("%d%d%d", &n, &m, &k);
  
  int b = n / k;
  while ((b - 1) * k + k - 1 <= n) b++;
  b--;

  int a = max(0, n - b * k);

  if  (m <= b * (k - 1) + a) {
    printf("%d\n", m % MOD);
    return 0;
  }

  int x = m - b * (k - 1) - a;

  printf("%d\n", add(mul(add(mpow(2, x + 1), -2 + MOD), k), m - x * k));
  return 0;
}