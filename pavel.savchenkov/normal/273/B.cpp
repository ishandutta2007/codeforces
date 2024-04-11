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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e5 + 10;

int f[MAXN * 3];
int need[MAXN * 3];
int val[MAXN * 3];
int n, m;
int a[MAXN];
int b[MAXN];
LL pow2 = 0;

int v[MAXN * 3];

int mul(int x, int y) {
  LL M = 1LL * x * y;
  M %= 1LL * m;
  return (int)M;
}

int mpow(int x, LL p) {
  int res = 1;
  while (p > 0) {
    if  (p % 2LL == 1LL) res = mul(res, x);
    p /= 2LL; x = mul(x, x);
  }

  return res;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; i++) {
    scanf("%d", &b[i]);
    if  (a[i] == b[i]) pow2++;
  }

  memset(f, 0, sizeof f);
  for (int i = 0; i < n; i++) {
    v[i] = a[i];
    v[n + i] = b[i];
  }

  sort(v, v + 2 * n);

  int len = 1;
  for (int i = 1; i < 2 * n; i++)
    if  (v[i] != v[i - 1]) {
      f[len]++;
      len = 1;
    } else len++;
  f[len]++;

  int want = 0;
  for (int i = 2 * n; i >= 1; i--) {
    want += f[i];
    need[i] = want;
    val[i] = i;
  }

  scanf("%d", &m);

  LL haspow2 = 0;
  for (int i = 1; i <= 2 * n; i++) {
    while (val[i] % 2 == 0) {
      val[i] /= 2;
      haspow2 += need[i];
    }
  }        

  pow2 = haspow2 - pow2;

  int res = 1;
  for (int i = 1; i <= 2 * n; i++)
    res = mul(res, mpow(val[i], need[i]));

  res = mul(res, mpow(2, pow2));

  printf("%d\n", res);
  return 0;
}