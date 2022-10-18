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
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int MAXN = 3 * int(1e5) + 10;

vi coord;
int a[MAXN];
ll sum[MAXN];
int n;

int l[MAXN];
int r[MAXN];

int main() {
  scanf("%d", &n);

  forn(i, n)
    scanf("%d", &a[i]);

  sum[0] = 0ll;
  forn(i, n)
    sum[i + 1] = sum[i] + ((a[i] >= 0) ? ll(a[i]) : 0ll);
                
  forn(i, n)
    coord.pb(a[i]);

  sort(coord.begin(), coord.end());

  forn(i, n) {
    l[i] = n;
    r[i] = -1;
  }

  forn(i, n) {
    int id = lower_bound(coord.begin(), coord.end(), a[i]) - coord.begin();

    l[id] = min(l[id], i);
    r[id] = max(r[id], i);
  }

  int L = -1, R = n;
  ll ans = -ll(1e18);

  forn(i, n)
    if  (l[i] < r[i] && l[i] < n && r[i] > -1) {
      ll cur = sum[r[i] + 1] - sum[l[i]];

      if  (a[r[i]] < 0)
        cur += 2ll * ll(a[r[i]]);

      if  (cur > ans) {
        L = l[i];
        R = r[i];
        ans = cur;
      }
    }

  printf("%I64d ", ans);

  int k = 0;
  for (int i = L + 1; i < R; i++)
    if  (a[i] < 0)
      k++;

  printf("%d\n", k + L + (n - R - 1));

  forn(i, L)
    printf("%d ", i + 1);

  for (int i = L + 1; i < R; i++)
    if  (a[i] < 0)
      printf("%d ", i + 1);

  foran(i, R + 1, n)
    printf("%d ", i + 1);
  return 0;
}