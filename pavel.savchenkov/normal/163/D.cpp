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
#include <ctime>

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
const ll INF = ll(4e18);
const int INT_INF = int(2e9);

ll ans;     
int A, B;
ll C;
ll v;
int sqv3;

ll p[80];
int st[80];
int szp;
int P[80][80];

int mul (int a, int b) {
  if  (ll(a) * ll(b) > ll(1e9) || a == -1 || b == -1)
    return -1;

//  if  (INT_INF / a <= b || b == -1 || a == -1)
//    return -1;

  return a * b; 
}

void go_b (int max_b, int i, int b, int a) {
  if  (b > max_b || b == -1)
    return;

  if  (i == szp) {
    ll ab = ll(a) * ll(b);
    ll c = v / ab;

    assert(v % ab == 0);

    ll f = ll(a) * ll(b) + ll(a) * c + ll(b) * c;

    if  (f < ans) {
      ans = f;
      A = a;
      B = b;
      C = c;
    }

    return; 
  }

  for (int j = 0; j <= st[i]; j++) {
    go_b(max_b, i + 1, mul(b, P[i][j]), a);
  }
}

void go_a (int max_a, int i, int a) {
  if  (a > max_a || a == -1)
    return;

  if  (i == szp) {
    int max_b = int(sqrt((double) v / ll(a)));

    if  (2ll * ll(a) * ll(max_b - 1) + ll(max_b - 1) * ll(max_b - 1) > ans)
      return;

    go_b(max_b + 1, 0, 1, a);
    return;
  }

  for (int j = st[i]; j >= 0; j--) {
    st[i] -= j;

    go_a(max_a, i + 1, mul(a, P[i][j]));

    st[i] += j;
  }
}

void solve () {
  sqv3 = 1;
  while (ll(sqv3) * ll(sqv3) * ll(sqv3) < v) sqv3++;
  
  ans = INF;

  go_a(sqv3 + 1, 0, 1);
}

map < ll, pair < pair <ll, int> , pair <int, ll> > > dp;

int main() {
  int t;
  scanf("%d", &t);

  while ((t--) > 0) {
    scanf("%d", &szp);
    forn(i, szp) {
      cin >> p[i] >> st[i];
    }

    v = 1ll;

    forn(i, szp)
      foran(j, i + 1, szp)
        if  (p[i] < p[j]) {
          swap(p[i], p[j]);
          swap(st[i], st[j]);
        }

    forn(i, szp) {
      P[i][0] = 1;

      for (int j = 1; j <= st[i]; j++) {
        if  (p[i] < ll(INT_INF))
          P[i][j] = mul(P[i][j - 1], int(p[i]));
        else
          P[i][j] = -1;
      }

      forn(j, st[i]) {
        v *= p[i];
      }
    }

    if  (dp.count(v)) {
      ans = dp[v].f.f;
      A = dp[v].f.s;
      B = dp[v].s.f;
      C = dp[v].s.s;
    } else {
      solve();
    }

    assert(ll(A) * ll(B) + ll(A) * C + ll(B) * C == ans);
    assert(ll(A) * ll(B) * C == v);

    cout << 2ll * ans << " " << A << " " << B << " " << C << '\n';

    dp[v] = mp(mp(ans, A), mp(B, C)); 
  }
  return 0;
}