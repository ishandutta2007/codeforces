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
const int MAXN = int(1e6) + 10;

int a[MAXN];
int c[50];
int used[50];
int n, m;

int go (int p) {
  if  (a[n - 1] == 0)
    return 0;

  int ans = 0;

  forn(i, n)
    if  ((a[i] & 1) && c[p] > 0) {
      a[i]--;
      c[p]--;
      ans++;
    }

  forn(i, n)
    if  (c[p] >= a[i]) {
      ans += a[i];
      c[p] -= a[i];
      a[i] = 0;  
    } else break;

  if  (c[p] & 1)
    forn(i, n)
      if  (a[i] > 0) {
        ans++;
        a[i]--;
        c[p]--;
        break;
      }

  used[p] = ans;

  c[p + 1] += c[p] / 2;
  forn(i, n)
    a[i] /= 2;

  ans += go(p + 1);
  ans += min(c[p] / 2, used[p + 1]);

  return ans; 
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset (c, 0, sizeof c);

  scanf("%d %d", &n, &m);
  forn(i, n) scanf("%d", &a[i]);
  sort(a, a + n);
  forn(i, m) {
    int b; scanf("%d", &b);
    c[b]++;
  }

  printf("%d\n", go(0));
  return 0;
}