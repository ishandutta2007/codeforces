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

struct person
{
    int c, f;
    person (int _c = 0, int _f = 0) { c=_c; f=_f; }
    friend bool operator <(const person & a, const person & b)
    {
        return a.f < b.f;
    }
};

int n, d, S;

vector <person> a;
vector <person> b;
vi sumb;

int maxCNT = 0; int minS = 0;

void upd(int a, int b)
{
    if  (a > maxCNT || a == maxCNT && b < minS) { maxCNT = a; minS = b; }
}

pii go(int free, int s)
{
   if  (free >= (int)b.size()) return mp((int)b.size(), 0);
   if  (b[0].f > s) return mp(free, 0);
   int r = (int)b.size() - free;
   int l = 0;

   while (l != r - 1)
   {
     int m = (l + r) >> 1;
     if  (sumb[m] <= s) l = m; else r = m;
   }
   return mp(free + l + 1, sumb[l]);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d%d%d", &n, &d, &S);
  forn(i, n)
  {
      int c, f, l; scanf("%d%d%d", &c, &f, &l);
      if  (l < d) f = S + 1;
      if  (!c) b.pb(person(c, f)); else a.pb(person(c, f));
  }
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  if  (!b.empty()) sumb.pb(b[0].f);
  foran(i, 1, b.size())
      if  (*sumb.rbegin() > S) sumb.pb(S + 1); else sumb.pb(*sumb.rbegin() + b[i].f);

  pii r = go(0, S); upd(r.f, r.s);

  int k = 0; int sum = 0; int Sum = 0;
  forn(i, a.size())
  {
      Sum += a[i].c;
      if  (Sum > n + n) break;
  }

  forn(i, a.size())
  {
      k++; sum += a[i].f;
      if  (sum > S) break;
      int x = Sum - (int)a.size() + k;
      pii r = go(x, S - sum);
      upd((int)a.size() + r.f, sum + r.s);
  }

  printf("%d %d\n", maxCNT, minS);
  return 0;
}