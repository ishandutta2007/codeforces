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

struct segm_tree
{
  vi t;
  int sz;

  segm_tree() {};

  segm_tree(const vi & a)
  {
      sz = 1; while (sz < (int)a.size()) sz <<= 1;
      t.assign(sz * 2, -INT_INF);
      build(a, 1, 0, sz - 1);
  };

  void build(const vi & a, int v, int tl, int tr)
  {
      if  (tl == tr) { if  (tl < (int)a.size()) t[v] = a[tl]; return; }
      int tm = (tl + tr) >> 1;
      build(a, v + v, tl, tm);
      build(a, v + v + 1, tm + 1, tr);
      t[v] = max(t[v + v], t[v + v + 1]);
  };

  int getmax(int v, int tl, int tr, int l, int r)
  {
      if  (tl == l && tr == r) return t[v];
      int tm = (tl + tr) >> 1;
      if  (r <= tm) return getmax(v + v, tl, tm, l, r);
      if  (tm < l) return getmax(v + v + 1, tm + 1, tr, l, r);
      return max( getmax(v + v, tl, tm, l, tm), getmax(v + v + 1, tm + 1, tr, tm + 1, r) );
  };

  int getmax(int l, int r)
  {
      return getmax(1, 0, sz - 1, l, r);
  };
};

segm_tree tr;
vi a;
vii sum;
int n;
char s[200500];

int LEN = 0; int CNT = 0;

void upd(int len)
{
  if  (len < LEN) return;
  if  (len == LEN) { CNT ++; return; }
  LEN = len; CNT = 1;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  gets(s); n = (int)strlen(s); a.assign(n + 1, 0);
  for (int i = 0; s[i]; i++)
  {
   if  (s[i] < 'a' || s[i] > 'z') s[i] += 'a' - 'A';
   if  (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'u' || s[i] == 'o') a[i] = -1; else a[i] = 2;
  }

  sum.assign(n + 1, mp(0, 0));
  sum[0].f = a[0]; sum[0].s = 0;
  foran(i, 1, n) sum[i].f = sum[i - 1].f + a[i], sum[i].s = i;
  sum[n] = mp(0, -1);
  sort(sum.begin(), sum.end());

  forn(i, n + 1)
   a[i] = sum[i].s;

  tr = segm_tree(a);

  forn(i, n)
      upd(tr.getmax(i + 1, n) - sum[i].s);

  if  (!LEN) puts("No solution"); else printf("%d %d\n", LEN, CNT);
  return 0;
}