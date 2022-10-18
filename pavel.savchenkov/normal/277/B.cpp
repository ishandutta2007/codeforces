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

int n, m;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d", &n, &m);

  if  (m == 3 && n >= 5) {
    puts("-1");
    return 0;
  }

  for (int i = 0; i < m; i++) {
    double r = 1e8 - 10.0;
    double a = (2.0 * M_PI / (double)m) * i;

    double x = r * cos(a);
    double y = r * sin(a);

    printf("%d %d\n", (int)x, (int)y);
  }

  for (int i = 0; i < n - m; i++) {
    double r = 1e7;
    double a = (2.0 * M_PI / (double)(n - m)) * i;

    a += 0.1;

    double x = r * cos(a);
    double y = r * sin(a);

    printf("%d %d\n", (int)x, (int)y);
  }

  return 0;
}