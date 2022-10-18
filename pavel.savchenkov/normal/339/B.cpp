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

int n, m;
int a[MAXN];

ll get (int a, int b) {
  if  (a <= b)
    return 1ll * (b - a);

  return 1ll * (n - a + b);
}

int main() {
  scanf("%d%d", &n, &m);

  forn(i, m) {
    scanf("%d", &a[i]);
    a[i]--;
  }

  ll res = 0;
  res += get(0, a[0]);
  forn(i, m - 1)
    res += get(a[i], a[i + 1]);

  printf("%I64d\n", res);
  return 0;
}