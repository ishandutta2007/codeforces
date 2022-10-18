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
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = 2 * (int) 1e5 + 10;

int n, q;
int a[MAXN];
int add[MAXN];
vector <int> v;

int main() { 
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  memset(add, 0, sizeof add);

  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]);
  sort(a, a + n);

  for (int i = 0; i < q; i++) {
    int l, r; scanf("%d%d", &l, &r);
    l--; r--;
    add[l]++;
    add[r + 1]--;
  }

  int cur = 0;
  for (int i = 0; i < n; i++) {
    cur += add[i];
    v.pb(cur);  
  }

  sort(v.begin(), v.end());

  ll res = 0;
  for (int i = 0; i < n; i++)
    res += 1ll * a[i] * v[i];

  printf("%I64d\n", res);
  return 0;
}