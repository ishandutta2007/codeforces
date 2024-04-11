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

const double EPS = 1e-9;
const int MAXN = int(1e5) + 10;

struct line {
  ll M, B;

  line (ll M = 0, ll B = 0) : M(M), B(B) {}

  ll calc (ll x) {
    return B + M * x;
  }
};

vector <line> st;

bool norm_order (line l1, line l2, line l3) {
  return double(l2.B - l1.B) * double(l2.M - l3.M) <= double(l3.B - l2.B) * double(l1.M - l2.M) - EPS;
}

//x < intersect(l1, l2).x
bool cmp (line l1, line l2, ll x) {
  return double(x) * double(l1.M - l2.M) < double(l2.B - l1.B) - EPS;  
}

void add_line (line l) {
  while (sz(st) >= 2) 
    if  (!norm_order(st[sz(st) - 2], st[sz(st) - 1], l))
      st.pop_back();
    else
      break;

  st.pb(l);
}

ll find_ans (ll x) {
  if  (sz(st) == 1) {
    return st[sz(st) - 1].calc(x);
  }

  if  (cmp(st[0], st[1], x)) {
    return st[0].calc(x);
  }

  int L = 0; int R = sz(st) - 1;
  while (L != R - 1) {
    int M = (L + R) / 2;
    if  (!cmp(st[M], st[M + 1], x))
      L = M;
    else
      R = M;
  }

  return st[R].calc(x);
}

int n;
int a[MAXN];
int b[MAXN];
ll dp[MAXN];
 
int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  for (int i = 0; i < n; i++)
    scanf("%d", &b[i]);

  dp[0] = 0;
  add_line(line(ll(b[0]), dp[0]));

  for (int i = 1; i < n; i++) {
    dp[i] = find_ans(ll(a[i]));
    add_line(line(ll(b[i]), dp[i]));
  }

  printf("%I64d\n", dp[n - 1]);
  return 0;
}