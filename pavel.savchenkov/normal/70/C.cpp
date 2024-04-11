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

int maxx, maxy, w;
int rev[100500];

int Rev(int a)
{
  int res = 0;
  while (a) res = res * 10 + a % 10, a /= 10;
  return res;
}

map <pii, int> m1;
map <pii, int> m2;

int gcd(int a, int b) { return (b) ? gcd(b, a % b) : a; }

void inc(map <pii, int> & m, int a, int b)
{
   int g = gcd(a, b);
   a /= g; b /= g;
   m[mp(a, b)]++;
}

void dec(map <pii, int> & m, int a, int b)
{
   int g = gcd(a, b);
   a /= g; b /= g;
   m[mp(a, b)]--;
}

int get(map <pii, int> & m, int a, int b)
{
   int g = gcd(a, b);
   a /= g; b /= g;
   return m[mp(a, b)];
}

int X = -1, Y = -1;

void upd(int x, int y, int W)
{
   if  (W < w || 1LL * x * y >= 1LL * X * Y && X != -1) return;
   X = x; Y = y;
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> maxx >> maxy >> w;
  for (int i = 1; i <= (int)1e5; i++)
   rev[i] = Rev(i);

  int x; int y = 0; int W = 0;
  for (x = 1; x <= maxx; x++)
   inc(m1, x, rev[x]);
  x--;

  while (x > 0)
  {
     while (W < w && y < maxy)
     {
         y++;
         inc(m2, rev[y], y);
         W += get(m1, rev[y], y);
     }
     upd(x, y, W);
     dec(m1, x, rev[x]);
     W -= get(m2, x, rev[x]);
     x--;
  }

  if  (X == -1) puts("-1"); else printf("%d %d\n", X, Y);
  return 0;
}