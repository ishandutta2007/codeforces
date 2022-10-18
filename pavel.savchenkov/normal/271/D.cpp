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
const int MOD1 = (int) 1e9 + 17;
const int MOD2 = (int) 1e4 + 7;
const int P = 29;
const int MAXN = 1600;

int mul1(int a, int b) {
  LL M = 1LL * a * b;
  M %= 1LL * MOD1;
  return (int)M;
}

int add1(int a, int b) {
  while (a < 0) a += MOD1;
  while (b < 0) b += MOD1;
  a += b;
  if  (a >= MOD1) a -= MOD1;
  return a;
}

int mul2(int a, int b) {
  return (a * b) % MOD2;
}

int add2(int a, int b) {
  a += b;
  while (a < 0) a += MOD2;
  while (a >= MOD2) a -= MOD2;
  return a;
}

int p1[MAXN];
int p2[MAXN];
int h1[MAXN];
int h2[MAXN];
int n, k;

int hash1(int l, int r) {
  if  (l == 0)
    return mul1(h1[r], p1[n - 1]);

  return mul1(add1(h1[r], -h1[l - 1]), p1[n - 1 - l]);
}

int hash2(int l, int r) {
  if  (l == 0)
    return mul2(h2[r], p2[n - 1]);

  return mul2(add2(h2[r], -h2[l - 1]), p2[n - 1 - l]);
}

bool bad[40];

pair <int, pii> vals[MAXN * MAXN + 10];
int sz = 0;

char s[MAXN];

int main() {
  gets(s); n = (int)strlen(s);

  p1[0] = 1;
  for (int i = 1; i < n; i++)
    p1[i] = mul1(p1[i - 1], P);

  p2[0] = 1;
  for (int i = 1; i < n; i++)
    p2[i] = mul2(p2[i - 1], P);

  h1[0] = s[0] - 'a' + 1;
  for (int i = 1; i < n; i++)
    h1[i] = add1(h1[i - 1], mul1(s[i] - 'a' + 1, p1[i]));

  h2[0] = s[0] - 'a' + 1;
  for (int i = 1; i < n; i++)
    h2[i] = add2(h2[i - 1], mul2(s[i] - 'a' + 1, p2[i]));

  for (int i = 0; i < 26; i++) {
    char c = getchar();
    if  (c == '0') 
      bad[i] = true; 
    else 
      bad[i] = false;
  }
  scanf("%d\n", &k);

  for (int i = 0; i < n; i++) {
    int bd = 0;

    for (int j = i; j < n; j++) {
      int c = s[j] - 'a';
      bd += bad[c];

      if  (bd > k) break;

      vals[sz++] = mp(j - i + 1, mp(hash1(i, j), hash2(i, j))); 
    }
  }

  sort(vals, vals + sz);

  printf("%d\n", unique(vals, vals + sz) - vals);
  return 0;
}