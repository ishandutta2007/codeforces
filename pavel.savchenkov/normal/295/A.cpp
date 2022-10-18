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

ll a[MAXN];

int cnt[MAXN];

int l[MAXN];
int r[MAXN];
ll d[MAXN];

ll add[MAXN];

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < n; i++)
    scanf("%I64d", &a[i]);

  for (int i = 0; i < m; i++)
    scanf("%d %d %I64d", &l[i], &r[i], &d[i]), l[i]--, r[i]--;

  for (int i = 0; i < k; i++) {
    int x, y; scanf("%d %d", &x, &y);
    x--; y--;

    cnt[x]++; cnt[y + 1]--;
  }

  int sum = 0;
  for (int i = 0; i < m; i++) {
    sum += cnt[i];

    d[i] *= 1ll * sum;
    
    add[l[i]] += d[i];
    add[r[i] + 1] -= d[i];
  }

  ll Sum = 0;
  for (int i = 0; i < n; i++) {
    Sum += add[i];

    a[i] += Sum;
  }

  for (int i = 0; i < n; i++)
    printf("%I64d ", a[i]);
  return 0;
}