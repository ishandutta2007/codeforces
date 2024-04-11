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
const int MAXN = (int) 1e5 + 10;

using namespace std;

int d[MAXN];
int n;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  memset(d, 0, sizeof d);
  int ans = 1;

  for (int i = 0; i < n; i++) {
    int a;
    scanf("%d", &a);
    if  (a == 1) continue;

    int res = 1;
    for (int j = 2; j * j <= a; j++) {
      if  (a % j != 0) continue;
      res = max(res, d[a / j] + 1);
      res = max(res, d[j] + 1);
    }
    res = max(d[a] + 1, res);

    for (int j = 2; j * j <= a; j++) {
      if  (a % j != 0) continue;
      d[j] = max(d[j], res);
      d[a / j] = max(d[a / j], res);
    }
    d[a] = max(d[a], res);

    ans = max(res, ans);
  }

  printf("%d\n", ans);
  return 0;
}