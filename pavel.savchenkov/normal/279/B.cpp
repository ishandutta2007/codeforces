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
const int MAXN = (int) 1e5 + 10;

int n, t;
int a[MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d", &n, &t);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);

  int r = -1, cur = 0, res = 0;

  for (int i = 0; i < n; i++) {
    if  (a[i] > t) continue;

    if  (r < i) {
      cur = a[i];
      r = i;
    }

    while (r < n - 1 && cur + a[r + 1] <= t) { r++; cur += a[r]; }

    res = max(res, r - i + 1);

    cur -= a[i];
  }

  printf("%d\n", res);
  return 0;
}