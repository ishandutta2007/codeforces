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
const int MAXN = int(1e5) + 10;
                                    
int mul (int a, int b, int mod = MOD) {
  ll M = 1ll * a * b;
  M %= ll(mod);
  return int(M);
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
    a = mul(a, a); p /= 2; 
  }
  return res;
}

int L;
char a[MAXN];

int calc (int k) {
  if  (k == 0)
    return 1;

  if  (!(k & 1)) {
    return add(calc(k - 1), mpow(2, mul(k, L, MOD - 1)));
  }

  int res = calc(k / 2);
  res = add(res, mul(res, mpow(2, mul((k + 1) / 2, L, MOD - 1))));
  return res;
}

int clc;

int Calc (int p, int k) {
  int res = clc;
  return mul(res, mpow(2, p)); 
}

int main() {
  gets(a);
  L = int(strlen(a));
  
  int k;
  scanf("%d", &k);
  k--;

  int ans = 0; clc = calc(k);
  for (int i = 0; i < L; i++)
    if  (a[i] == '0' || a[i] == '5')
      ans = add(ans, Calc(i, k));

  printf("%d\n", ans);
  return 0;
}