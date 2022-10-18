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
const int MAXN = (int) 1e4 + 10;
const int MAXK = 22;

int ans[MAXN][MAXK];
int n, k;

int t;

void put (int p) {
  int prev = (1 << p) - 1;

  for (int i = (1 << p); i < n; i++)
    ans[i][t] = prev; 
}

void go (int p) {
  for (int i = (1 << p) + 1; i < min(n, (1 << (p + 1))); i++)
    ans[i][t] = i - (1 << p);
}

int main() {
  memset (ans, 0, sizeof ans);

  scanf("%d %d", &n, &k);

  t = 0;

  put(1); t++;
  for (int p = 2; (1 << p) < n; p++) {
    put(p);
    go(p - 1);
    t++;
  }

  int p = 1;
  while ((1 << p) < n) p++;
  go(p - 1);

  for (int i = 0; i < k; i++, puts(""))
    for (int j = n - 1; j >= 0; j--)
      printf("%d ", n - ans[j][i]);
  return 0;
}