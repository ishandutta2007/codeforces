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
const int MAXN = int(1e5) + 10;
const int MAXM = int(1e6) + 10;
const int MOD = 1000000007;

int add (int a, int b) {
  if  (b < 0) b += MOD;
  a += b;
  if  (a >= MOD)
    a -= MOD;
  return a;
}      

int mul (int a, int b) {
  ll M = 1ll * a * b;
  M %= ll(MOD);
  return int(M);
}

int f[MAXM];

int ans[MAXN];
int a[MAXN];
int n;

int sum (int r) {
  int res = 0;
  for (int i = r; i >= 0; i = (i & (i + 1)) - 1)
    res = add(res, f[i]);
  return res;
}

int sum (int l, int r) {
  return add(sum(r), -sum(l - 1));
}

void upd (int j, int val) {
  for (int i = j; i < MAXM; i = (i | (i + 1)))
    f[i] = add(f[i], val);
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);

  scanf("%d", &n);
  
  forn(i, n) {
    scanf("%d", &a[i]);

    ans[i] = mul(a[i], sum(a[i]));
    ans[i] = add(ans[i], a[i]);

    int old = sum(a[i], a[i]);

    upd(a[i], MOD - old);
    upd(a[i], ans[i]);
  }

  printf("%d\n", sum(MAXM - 1));                     
  return 0;
}