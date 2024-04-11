#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define i64 long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) (x) * (x)
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

pii a[100500];
vi r;
int n;
int ok[200500];
int bad[200500];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n)
   scanf("%d%d", &a[i].f, &a[i].s), r.pb(a[i].f), r.pb(a[i].s);
  sort(r.begin(), r.end());
  r.resize( unique(r.begin(), r.end()) - r.begin());
  forn(i, n)
   a[i].f = lower_bound(r.begin(), r.end(), a[i].f) - r.begin(),
   a[i].s = lower_bound(r.begin(), r.end(), a[i].s) - r.begin();

  memset(ok, 0, sizeof ok);
  memset(bad, 0, sizeof bad);
  forn(i, n)
  {
   ok[ a[i].f ]++;
   if  (a[i].f != a[i].s) bad[ a[i].s ]++;
  }

  int res = INT_INF;
  int mid = n / 2 + n % 2;

  forn(i, r.size())
  {
      if  (ok[i] + bad[i] < mid) continue;
      if  (ok[i] >= mid) res = 0; else res = min(res, mid - ok[i]);
  }

  if  (res == INT_INF) puts("-1"); else cout << res << "\n";
  return 0;
}