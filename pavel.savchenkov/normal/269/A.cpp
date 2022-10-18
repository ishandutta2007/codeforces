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

using namespace std;

pair <int, LL> c[MAXN];
int n;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++)
    scanf("%d%I64d", &c[i].f, &c[i].s);

  sort(c, c + n);

  for (int i = 0; i < n - 1; i++) {
    LL can = 1LL * c[i + 1].s; int st = c[i].f;
    while (can < c[i].s && st < c[i + 1].f) {
      can *= 4LL;
      st++;
    }
    c[i].s -= min(can, c[i].s);

    st = c[i].f; LL a = c[i].s;
    while (st < c[i + 1].f && a > 1LL) {
      a = (a + 3LL) / 4LL;
      st++;
    }

    c[i + 1].s += a;
  }

  int p = c[n - 1].f + 1; LL cnt = 4LL;
  while (cnt < c[n - 1].s) { p++; cnt *= 4LL; }

  printf("%d\n", p);
  return 0;
}