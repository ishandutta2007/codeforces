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
const int MAXK = int(1e6) + 10;
const int MAXV = int(1e7) + 10;

ll get_cnt (ll n, int p) {
  ll ans = 0;
  while (n > 0) {
    n /= 1ll * p;
    ans += n;
  }

  return ans;
}

ll get (int p, ll cnt) {
  if  (cnt == 0)
    return 1ll;

//  printf("p = %d cnt = %d\n", p, cnt);

  ll L = 1ll; ll R = ll(1e16);
  while (L != R - 1ll) {
    ll M = (L + R) / 2ll;
    if  (get_cnt(M, p) >= cnt)
      R = M;
    else
      L = M;
  }

  return R;
}

int k;                  
ll cnt[MAXV];
bool pr[MAXV];

ll get_c (int n, int p) {
  ll ans = 0;
  while (n % p == 0) {
    ans++;
    n /= p;
  }
  return ans;
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset (cnt, 0, sizeof cnt);
  memset (pr, true, sizeof pr);

  scanf("%d", &k);
  forn(i, k) {
    int a;
    scanf("%d", &a);
    cnt[a]++;
  }

  ll n = 1ll;
  for (int i = MAXV - 2; i > 1; i--)
    cnt[i] += cnt[i + 1];

  for (int i = 2; i < MAXV; i++)
    if  (pr[i]) {
      int c = 1;
      for (int j = i + i; j < MAXV; j += i) {
        pr[j] = false;
        cnt[i] += cnt[j] * get_c(j, i);
      }                          

      n = max(n, get(i, cnt[i]));
    }


  cout << n << '\n';
  return 0;
}