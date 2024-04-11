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
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MOD = (int) 1e9 + 7;

void print() {
  for (int i = 0; i < 7; i++) {
    int mask = 0;

    int k; scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int a; scanf("%d", &a);
      mask |= (1 << a);
    }

    printf("%d, ", mask);
  }
  puts("");

  for (int i = 0; i < 7; i++) {
    int mask = 0;
    int k; scanf("%d", &k);
    for (int j = 0; j < k; j++) {
      int a; scanf("%d", &a);
      mask |= (1 << a);
    }

    printf("%d, ", mask);
  } 
}

int add(int a, int b) {
  a += b;
  if  (a >= MOD) a -= MOD;
  return a;
}

int mul(int a, int b) {
  ll M = 1ll * a * b;
  M %= 1ll * MOD;
  return (int)M;
}

int verm[7] = {0, 16, 68, 84, 325, 341, 365};
int gorm[7] = {0, 16, 257, 273, 325, 341, 455};

char s[1010][1010];
int n, m;

int a[300][300];

int getmask(int i, int j) {
  int mask = 0; int p = 0;

  for (int ii = i; ii <= i + 2; ii++)
    for (int jj = j; jj <= j + 2; jj++) {
      if  (s[ii][jj] == 'O') mask |= 1 << p;
      p++;
    }

  return mask;
}

int d[400];

bool can(int m1, int m2) {
  return m1 == m2;
}

int cnt(int i, int j, int c) {
 
  if  (c == 2) {
    for (int ii = 0; ii < 7; ii++)
      for (int jj = 0; jj < 7; jj++)
        if  (can(a[i][j], verm[ii]) && can(a[i + 1][j], verm[jj])) return 1;

    return 0;
  }

  for (int ii = 0; ii < 7; ii++)
    for (int jj = 0; jj < 7; jj++)
      if  (can(a[i][j], gorm[ii]) && can(a[i][j + 1], gorm[jj])) return 1;

  return 0;
}

int calc1(int j) {
  if  (n % 2 == 1) return 0;

  int res = 1;
  for (int i = 0; i < n; i += 2)
    res = mul(res, cnt(i, j, 2));

  return res;
}

int dp[300][300][2];

int calc2(int i, int j, bool was) {
  if  (dp[i][j][was] != -1)
    return dp[i][j][was];

  if  (i == 1)
    return dp[i][j][was] = add(cnt(i, j, 1) * cnt(i - 1, j, 1), was ? cnt(i - 1, j, 2) * cnt(i - 1, j + 1, 2) : 0);

  if  (i == 0)
    return dp[i][j][was] = cnt(i, j, 1);

  return dp[i][j][was] = add(mul(cnt(i, j, 1), calc2(i - 1, j, true)), mul(cnt(i - 1, j, 2) * cnt(i - 1, j + 1, 2), calc2(i - 2, j, was))); 
}
 
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d\n", &n, &m);
  for (int i = 0; i < 4 * n + 1; i++)
    gets(s[i]);

  
  for (int i = 1; i < 4 * n + 1; i += 4)
    for (int j = 1; j < 4 * m + 1; j += 4)
      a[(i - 1) / 4][(j - 1) / 4] = getmask(i, j);

  memset(d, 0, sizeof d);
  memset(dp, -1, sizeof dp);
  d[0] = calc1(0);
  d[1] = calc2(n - 1, 0, false);

  for (int j = 0; j < m; j++) {
    d[j + 1] = add(d[j + 1], mul(calc1(j + 1), d[j]));
    d[j + 2] = add(d[j + 2], mul(calc2(n - 1, j + 1, false), d[j]));
  }

  printf("%d\n", d[m - 1]); 
  return 0;
}