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
const int MAXN = 5100;
 
using namespace std;

int n, m;
int a[MAXN];

int d[MAXN][MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d%d", &n, &m); double x;
  for (int i = 0; i < n; i++)
    scanf("%d%lf", &a[i], &x), a[i]--;

  memset(d, 0, sizeof d);

  for (int i = 0; i < n; i++)
    for (int j = 1; j <= m; j++) {
      d[i][j] = d[i][j - 1];
      if  (i > 0) d[i][j] = max(d[i][j], d[i - 1][j]);
      if  (a[i] == j - 1) d[i][j]++;
    }

  printf("%d\n", n - d[n - 1][m]);
  return 0;
}