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
#define ui64 unsigned long long
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
const int INT_INF = 0x7FFFFFFE;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFELL;
const double PI = acos(-1.0);

using namespace std;

int d[110][10100];
bool a[110][10100];
int n, m;

int main() {
 // freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> m;
  forn(i, n)
   forn(j, m)
    { d[i][j] = INT_INF; int x; scanf("%1d", &x); a[i][j] = x; }

  bool ok = 1;
  forn(i, n)
  {
    int last = -1;
    forn(j, m)
     if  (a[i][j])
      d[i][j] = 0, last = j;
     else
      if  (last != -1) d[i][j] = j - last;

    ford(j, m)
     if  (a[i][j]) { last = j; break; }

    if  (last == -1) ok = 0;

    forn(j, m)
     if  (!a[i][j]) { d[i][j] = m - last + j; } else break;


    last = -1;
    ford(j, m)
     if  (a[i][j])
      d[i][j] = 0, last = j;
     else
      if  (last != -1) d[i][j] = min(d[i][j], last - j);

    forn(j, m)
     if  (a[i][j]) { last = j; break; }

    ford(j, m)
     if  (!a[i][j]) d[i][j] = min(d[i][j], m - j + last); else break;
  }

  int res = INT_INF;
  forn(j, m)
  {
      int cur = 0;
      forn(i, n)
       cur += d[i][j];

      res = min(res, cur);
  }

  if  (!ok)
   puts("-1");
  else
   printf("%d\n", res);
  return 0;
}