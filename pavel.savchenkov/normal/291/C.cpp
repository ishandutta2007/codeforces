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
const int MAXN = (int) 1e5 + 10;

int n, k;
int IP[MAXN];

int GetMask (int cnt) {
  int m = 0;
  int p = 31 - cnt;
  for (int i = p + 1; i <= 31; i++)
    m |= (1 << i);

  return m; 
}

int c[MAXN];
int sz = 0;

bool check (int cnt) {
  int m = GetMask(cnt);
  sz = 0;

  for (int i = 0; i < n; i++)
    c[sz++] = IP[i] & m;

  sort(c, c + sz);
  return (unique(c, c + sz) - c) == k;
}

int main() {
  scanf("%d %d", &n, &k);
  for (int i = 0; i < n; i++) {
    int a, b, c, d;
    scanf("%d.%d.%d.%d", &a, &b, &c, &d);

    IP[i] = (a << 24) + (b << 16) + (c << 8) + d;
  }

  for (int i = 1; i <= 32; i++)
    if  (check(i)) {
      int m = GetMask(i);
      int a = (m >> 24) & 255;
      int b = (m >> 16) & 255;
      int c = (m >> 8) & 255;
      int d = m & 255;

      printf("%d.%d.%d.%d\n", a, b, c, d);
      return 0; 
    }

  puts("-1");
  return 0;
}