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
const int MAXN = int(1e5) + 10;

ll gcd (ll a, ll b) { return b ? gcd(b, a % b) : a; }
ll lcm (ll a, ll b) { return (a / gcd(a, b)) * b; }

struct frac {
  ll a, b;

  void norm () {
    ll g = gcd(a, b);
    a /= g;
    b /= g;
  }

  frac () {}

  frac (ll a, ll b): a(a), b(b) {
    norm();
  }

  void output () {
    cout << a << ' ' << b << '\n';
  }
};

frac operator * (frac x, ll y) {
  return frac(x.a * y, x.b);   
}

frac operator + (frac x, frac y) {
  ll l = lcm(x.b, y.b);

  return frac(x.a * (l / x.b) + y.a * (l / y.b), l);
}

frac operator * (frac x, frac y) {
  return frac(x.a * y.a, x.b * y.b);
}

int a[MAXN];
int n;
ll sum_dist[MAXN];

int main() {
  scanf("%d", &n);

  forn(i, n)
    scanf("%d", &a[i]);

  sort(a, a + n);

  sum_dist[0] = 0;
  ll sum = 0;

  for (int i = 1; i < n; i++) {
    sum_dist[i] = sum_dist[i - 1] + ll(a[i] - a[i - 1]) * ll(i);
    sum += sum_dist[i];
  }

  frac res = frac(sum, ll(n)) * 2ll;
  forn(i, n)
    res = res + frac(ll(a[i]), ll(n));

  res.output();
  return 0;
}