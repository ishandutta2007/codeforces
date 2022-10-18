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
const int MAXN = (int) 1e5 + 10;

int n, m, k;

int put (int a, int b, int c, int pos) {
  if  (pos < a || b < pos) return 0;

  return (c + pos - a);
}

int a[MAXN];
int b[MAXN];
int c[MAXN];

int main() {                            
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d %d", &n, &m, &k);

  for (int i = 0; i < m; i++)
    scanf("%d %d %d", &a[i], &b[i], &c[i]), a[i]--, b[i]--;

  ll ans = 0;

  for (int i = 0; i < k; i++) {
    int pos; scanf("%d", &pos); pos--;

    for (int j = 0; j < m; j++)
      ans += 1ll * put(a[j], b[j], c[j], pos); 
  }

  cout << ans << '\n';
  return 0;
}