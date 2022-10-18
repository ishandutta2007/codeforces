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
const int MAXN = 2 * (int) 1e5 + 10;

int n;                 
int a[MAXN];
ll d[MAXN];
int color[MAXN];

void calc (int x) {
//  printf("x = %d\n", x);  

  if  (color[x] != 0) return;
  color[x] = 1;

  int X = x;


  int y = 0;
  int ax = a[x];

  y = ax;
  x -= ax;

  if  (x <= 0) {
    d[X] = 1ll * y;
    color[X] = 2;
    return; 
  }

  if  (x == 1) {
    return;
  }


  ax = a[x];
  x += ax;
  y += ax;

  if  (x > n) {
    d[X] = 1ll * y;
    color[X] = 2;
    return;
  }

  calc(x);
  if  (color[x] == 1) return;

  d[X] = 1ll * y + d[x];
  color[X] = 2;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d", &n);
  for (int i = 2; i <= n; i++)
    scanf("%d", &a[i]);

  for (int i = 2; i <= n; i++) {
    d[i] = -1ll;
    color[i] = 0;
  }

  for (int i = 2; i <= n; i++)
    calc(i);

  for (int i = 1; i < n; i++) {
    int x = 1; int y = 0; int ax = i;
    x += ax;
    y += ax;

    if  (x > n || color[x] == 1)
      puts("-1");
    else
      printf("%I64d\n", 1ll * y + d[x]);
  }

  return 0;
}