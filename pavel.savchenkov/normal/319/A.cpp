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

char s[110];
int n;

int solve (int i) {
  if  (i == n)
    return 0;

  int p = n - i;

  if  (s[i] == '0')
    return mul(2, solve(i + 1));
  else {
    int res = mpow(2, 2 * (p - 1));
    res = add(res, mul(2, solve(i + 1)));
    return res;
  }
}

int main() {
  gets(s);
  n = int(strlen(s));

  printf("%d", solve(0) % MOD);
  return 0;
}