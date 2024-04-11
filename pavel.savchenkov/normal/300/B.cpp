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
#define forn(i, n) for (int i = 0; i < int(n); i++)
#define ford(i, n) for (int i = int(n) - 1; i >= 0; i--)
#define foran(i, a, n) for (int i = int(a); i < int(n); i++)
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;

int p[100];
int sz[100];

int get_set (int x) {
  return x == p[x] ? x : p[x] = get_set(p[x]);
}

void union_set (int x, int y) {
  y = get_set(y);
  x = get_set(x);

  if  (x == y) return;

  p[x] = y;
  sz[y] += sz[x];
}

int n, m;

vector <int> res[100];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  forn(i, 60) {
    p[i] = i;
    sz[i] = 1;
  }

  scanf("%d %d", &n, &m);
  forn(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    a--; b--;
    union_set(a, b);
  }

  forn(i, n)
    if  (sz[i] > 3) {
      puts("-1");
      return 0;
    }

  forn(i, n)
    if  (p[i] == i && sz[i] == 2) {
      bool ok = false;
      forn(j, n)
        if  (p[j] == j && sz[j] == 1) {
          union_set(i, j);
          ok = true;
          break;
        }
      if  (!ok) {
        puts("-1");
        return 0;
      }
    }
        
  forn(i, n)
    forn(j, n)
      forn(k, n)
        if  (i != j && j != k && i != k && sz[i] == 1 && sz[j] == 1 && sz[k] == 1 && p[i] == i && p[j] == j && p[k] == k) {
          union_set(i, j);
          union_set(j, k);
        }
          
  forn(i, n)
    if  (i == p[i] && sz[i] != 3) {
      puts("-1");
      return 0;
    }

  forn(i, n)
    res[get_set(i)].pb(i);

  forn(i, 60)
    if  (!res[i].empty()) {
      forn(j, 3)
        printf("%d ", res[i][j] + 1);
      puts("");
    }

  return 0;
}