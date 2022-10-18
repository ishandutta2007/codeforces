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

#define pb push_back
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = 1000000007;

using namespace std;

int add(int a, int b) {
  a += b;
  if  (a > MOD) a-= MOD;
  return a;
}

int mul(int a, int b) {
  LL M = 1LL * a * b;
  M %= (LL)MOD;
  return (int)M;
}

int mpow(int a, int p) {
  int res = 1;
  while (p > 0) {
    if  (p & 1)
      res = mul(res, a);
    a = mul(a, a);
    p /= 2;
  }

  return res;
}

int n;
int a[100500];

int divs[1000];
int szdivs;

int d[100500];
int last[100500];
int prev[100500];
int timer = 0;

int poss[1000];
int szposs = 0;

int GetPos(int x) {
  int L = 0; int R = n - 1;
  while (L != R - 1) {
    int M = (L + R) / 2;
    if  (a[M] < x) L = M; else R = M;
  }
  return a[R - 1] >= x ? R - 1 : R;
}

int calc(int cnt, int len) {
  return mpow(cnt, len);
}

int solve(int m) {
  szdivs = 0;
  for (int i = 2; i * i <= m; i++) {
    if  (m % i != 0) continue;
    divs[szdivs++] = i;
    if  (i * i != m) divs[szdivs++] = m / i;
  }
  divs[szdivs++] = 1;
  divs[szdivs++] = m;
  sort(divs, divs + szdivs);
  szdivs = unique(divs, divs + szdivs) - divs;
  timer++;

  szposs = 0;
  for (int i = szdivs - 1; i >= 0; i--) {
    int pos = GetPos(divs[i]);
    if  (last[pos] < timer) {
      d[pos] = 1;
      last[pos] = timer;
    } else d[pos]++;
    poss[szposs++] = pos;
  }

  sort(poss, poss + szposs);
  szposs = unique(poss, poss + szposs) - poss;

  int res = 1; int cnt = szdivs;
  for (int i = szposs - 1; i >= 0; i--) {
    if  (i == szposs - 1) {
      res = calc(cnt, n - poss[i]) - calc(cnt - 1, n - poss[i]);
      res += MOD; res %= MOD;
      cnt -= d[poss[i]];
      continue;
    }

    res = mul(res, calc(cnt, poss[i + 1] - poss[i]));
    cnt -= d[poss[i]]; 
  }

  return res;
}

int main() {
  scanf("%d\n", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  sort(a, a + n);

  memset(last, -1, sizeof last);
  int res = 0;
  for (int i = 1; i <= a[n - 1]; i++)
    res = add(res, solve(i));

  printf("%d\n", res);
  return 0;
}