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
const int MAXN = 150;

int p[MAXN];

int get_set(int x) {
  return p[x] == x ? x : p[x] = get_set(p[x]);
}

void union_set(int x, int y) {
  x = get_set(x);
  y = get_set(y);
  p[x] = y;
}

int n, m;
int cnt0 = 0;
int a[MAXN];
set <int> s;
bool was[MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset(was, false, sizeof was);

  scanf("%d %d", &n, &m);

  for (int i = 0; i < m; i++)
    p[i] = i;

  for (int i = 0; i < n; i++) {
    int k; scanf("%d", &k);
    if  (k == 0) cnt0++;

    for (int j = 0; j < k; j++) {
      scanf("%d", &a[j]);
      a[j]--;
      was[a[j]] = true;
    }

    for (int j = 0; j < k; j++)
      for (int jj = j + 1; jj < k; jj++)
        union_set(a[j], a[jj]); 
  }

  for (int i = 0; i < m; i++)
    if  (was[i]) s.insert(get_set(i));


  printf("%d\n", cnt0 + max(sz(s) - 1, 0));  
  return 0;
}