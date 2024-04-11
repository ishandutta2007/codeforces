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

ll gcd (ll a, ll b) {
  return b != 0ll ? gcd(b, a % b) : a;
}

ll get (ll l, ll x, ll n) {
  ll xx = (l + 1ll) / 2ll;

  if  (xx >= x)
    return 0;

  if  (x - xx + l > n)
    return n - l;

  return x - xx; 
}      

ll x, y, n, m, a, b;
 
int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> m >> x >> y >> a >> b;

  ll g = gcd(a, b);
  a /= g;
  b /= g;

  ll lx = min(n / a, m / b) * a;
  ll ly = (lx * b) / a;

  ll x1 = get(lx, x, n);
  ll y1 = get(ly, y, m);

  cout << x1 << " " << y1 << " " << x1 + lx << " " << y1 + ly << '\n';
  return 0;
}