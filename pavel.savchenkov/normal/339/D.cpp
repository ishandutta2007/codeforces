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
const int MAXN = (1 << 17) + 10;

int t[2 * MAXN + 10];
bool is_or[2 * MAXN + 10];
int N, n, m;
int a[MAXN];

void upd (int v, int tl, int tr, int pos, int val) {
  if  (tl == tr) {
    t[v] = val;
    return;
  }

  int tm = (tl + tr) / 2;

  if  (pos <= tm)
    upd(v * 2, tl, tm, pos, val);
  else
    upd(v * 2 + 1, tm + 1, tr, pos, val);

  if  (is_or[v])
    t[v] = t[v * 2] | t[v * 2 + 1];
  else
    t[v] = t[v * 2] ^ t[v * 2 + 1];
}

void build () {
  forn(i, N) {
    t[N + i] = a[i];
    is_or[N + i] = false;
  }

  for (int v = N - 1; v >= 1; v--)
    if  (is_or[v * 2]) {
      is_or[v] = false;

      t[v] = t[v * 2] ^ t[v * 2 + 1];
    } else {
      is_or[v] = true;

      t[v] = t[v * 2] | t[v * 2 + 1];
    }
}

void read () {
  scanf("%d%d", &n, &m);

  N = 1 << n;

  forn(i, N)
    scanf("%d", &a[i]);
}
  
int main() {
  read();

  build();

  forn(i, m) {
    int p, b;
    scanf("%d%d", &p, &b);

    p--;

    upd(1, 0, N - 1, p, b);

    printf("%d\n", t[1]);
  }

  return 0;
}