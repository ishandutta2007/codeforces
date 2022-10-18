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
#define y1 gftxdtrtfhyjfctrxujkvbhyjice
#define y0 ehfoiuvhefroerferjhfjkehfjke

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int,int> pii;

const double EPS = 1e-9;
const int MOD = 1000000007;

int mul (int a, int b) {
  ll m = 1ll * a * b;
  m %= 1ll * MOD;
  return (int)m;
}

int n, k;
int ans = 0;

bool was[20];
bool ok[20];
int p[20];

void dfs (int v) {
  if  (was[v])
    return;

  was[v] = true;

  dfs(p[v]);

  ok[v] |= ok[p[v]];
}

void gen (int i) {
  if  (i == k) {
    memset (was, false, sizeof was);
    memset (ok, false, sizeof ok);
    ok[0] = was[0] = true;

    for (int j = 0; j < k; j++)
      if  (!was[j]) dfs(j);

    for (int j = 0; j < k; j++)
      if  (!ok[j]) return;

    ans++;
    return;
  }

  for (int val = 0; val < k; val++)
    if  (val != 50 || i != 0) {
      p[i] = val;
      gen(i + 1);
    }
}

int res[8] = { 1, 2, 9, 64, 625, 7776, 117649, 2097152 };

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d", &n, &k);

  //gen(0);
  ans = res[k - 1];

  for (int i = k; i < n; i++)
    ans = mul(ans, n - k);

  cout << ans << '\n';
  return 0;
}