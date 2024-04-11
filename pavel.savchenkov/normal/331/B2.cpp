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

int pos[MAXN];
int a[MAXN];
int n, q;
int deleted = -1;
int fenw[MAXN];

void upd (int x, int d) {
  for (int i = x; i < n; i = (i | (i + 1)))
    fenw[i] += d;
}

int sum (int r) {
  int res = 0;
  for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
    res += fenw[i];
  return res;  
}

int sum (int l, int r) {
  return sum(r) - sum(l - 1);
}

bool isBeg (int i) {
  return sum(i, i) == 1;
}

void build () {
  memset (fenw, 0, sizeof fenw);

  upd(0, 1);
  for (int i = 1; i < n; i++)
    if  (pos[i - 1] > pos[i])
      upd(i, 1);
}

void del (int val) {
  if  (val < n - 1 && pos[val] < pos[val + 1] && deleted != val + 1)
    upd(val + 1, 1);

  if  (isBeg(val))
    upd(val, -1);
}

void add (int val) {
  if  (val < n - 1 && pos[val] < pos[val + 1] && deleted != val + 1)
    upd(val + 1, -1);

  if  (0 == val || pos[val - 1] > pos[val] || deleted == val - 1)
    upd(val, 1);
}

void goSwap (int x, int y) {
  deleted = -1;
  del(a[x]);
  deleted = a[x];
  del(a[y]);

  swap(a[x], a[y]);
  pos[a[x]] = x;
  pos[a[y]] = y;

  add(a[x]);
  add(a[y]); 
}

int calc (int x, int y) {
  if  (isBeg(x))
    return sum(x, y);
  else
    return sum(x, y) + 1;
}

void output () {
  forn(i, n)
    printf("%d ", sum(i, i));
  puts("");
}

int main() {
  scanf("%d", &n);
  forn(i, n) {
    scanf("%d", a + i);
    a[i]--;
    pos[a[i]] = i;
  }

  build();

  scanf("%d", &q);
  forn(i, q) {
    int p, x, y;
    scanf("%d %d %d", &p, &x, &y);
    x--; y--;

    if  (p == 1)
      printf("%d\n", calc(x, y));
    else
      goSwap(x, y);
  }

  return 0;
}