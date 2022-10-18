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
#define all(A) A.begin(), A.end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;
typedef pair <ll, ll> pll;
typedef vector <ll> vll;
typedef vector <int> vi;

const double EPS = 1e-9;
const int INF = int(1e9);

int n;
ll a[9];

int min_cnt[1 << 9];
bool was_cnt[1 << 9];
int mem_root[1 << 9];
map <ll, int> rem;

bool norm (ll x, ll y) {
  if  (x == 0 || y == 0)
    return false;

  ll m = x * y;

  if (m / x != y || m / y != x || m == 0)
    return false;

  return true; 
}

int calc_cnt(int);

int get_root (int mask) {
  if  (mem_root[mask] != -1)
    return mem_root[mask];

  int root = -1;

  forn(i, n)
    if  ((mask & (1 << i)) && (root == -1 || a[i] > a[root]))
      root = i;

  return mem_root[mask] = root; 
}

int get_rem (ll val) {
  if  (rem.count(val))
    return rem[val];

  int res = 0;
  ll Val = val;
  for (int i = 2; ll(i) * ll(i) <= Val; i++) {
    while (val % ll(i) == 0) {
      res++;
      val /= ll(i);
    } 
  }
  if  (val > 1ll)
    res++;

  return rem[Val] = res;
}

int go (int root, int mask, ll cur_mul, int cur_cnt) {
  if  (get_rem(a[root]) == 1)
    return 1;

  if  (mask == 0)
    return cur_cnt + get_rem(a[root] / cur_mul) + 1;

  int res = INF;

  for (int nmask = mask; nmask != 0; nmask = (nmask - 1) & mask) {
    int cur_root = get_root(nmask);

    if  (!norm(a[cur_root], cur_mul) || a[root] % (a[cur_root] * cur_mul) != 0)
      continue;

    if  (calc_cnt(nmask) < INF)
      res = min(res, go(root, mask ^ nmask, cur_mul * a[cur_root], cur_cnt + calc_cnt(nmask)));
  }

  return res;  
}

int calc_cnt (int mask) {
  if  (was_cnt[mask])
    return min_cnt[mask];
  was_cnt[mask] = true;

  if  (mask == 0)
    return min_cnt[0] = 0;

  int root = get_root(mask);

  forn(i, n)
    if  (((mask >> i) & 1) && a[root] % a[i] != 0)
      return min_cnt[mask] = INF;

  return min_cnt[mask] = go(root, mask ^ (1 << root), 1ll, 0);    
}

int Go (int mask, int cur_cnt) {
  if  (mask == 0)
    return cur_cnt + 1;

  int res = INF;

  for (int nmask = mask; nmask != 0; nmask = (nmask - 1) & mask) {
    if  (calc_cnt(nmask) < INF)
      res = min(res, Go(mask ^ nmask, cur_cnt + calc_cnt(nmask)));
  }

  return res;  
}

int main() {
  cin >> n;

  forn(i, n)
    cin >> a[i];

  memset (mem_root, -1, sizeof mem_root);
  memset (was_cnt, false, sizeof was_cnt);

  int ans = min(calc_cnt((1 << n) - 1), Go((1 << n) - 1, 0));

  printf("%d\n", ans);
  return 0;
}