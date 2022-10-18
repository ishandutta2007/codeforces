//HACK ME, PLEASE! ^_^
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

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);
const i64 MOD = (int)1e9 + 7;

using namespace std;

string s;
i64 d[800][800][5][5];
bool was[800][800][5][5];
int n;

void add(i64 & x, i64 y)
{
    x += y;
    x %= MOD;
}

i64 go(int l, int r, int cl, int cr)
{
  if  (was[l][r][cl][cr]) return d[l][r][cl][cr];
  was[l][r][cl][cr] = 1;

  if  (cl && cr || !cl && !cr) return d[l][r][cl][cr] = 0;
  if  (r - l == 1)
      return d[l][r][cl][cr] = 1ll;


  int b = 0; int L = l;

  if  (!was[l + 1][r - 1][1][0])
  for (int i = l + 1; i < r; i++)
  {
      if  (s[i] == '(') b++; else b--;
      if  (b) continue;
      for (int CL = 0; CL < 3; CL++)
       for (int CR = 0; CR < 3; CR++)
        go(L + 1, i, CL, CR);

      if  (L == l) { L = i; continue; }

      for (int c1 = 0; c1 < 3; c1++)
       for (int c2 = 0; c2 < 3; c2++)
        for (int c3 = 0; c3 < 3; c3++)
         for (int c4 = 0; c4 < 3; c4++)
         {
             was[l + 1][i][c1][c4] = 1;
             if  (c2 == c3 && c2 && c3) continue;
             add(d[l + 1][i][c1][c4], d[l + 1][L][c1][c2] * d[L + 1][i][c3][c4]);
         }
      L = i;
  }


  for (int CL = 0; CL < 3; CL++)
   for (int CR = 0; CR < 3; CR++)
   {
    if  (CL == cl && cl && CL) continue;
    if  (CR == cr && cr && CR) continue;
    add(d[l][r][cl][cr], d[l + 1][r - 1][CL][CR]);
   }

   return d[l][r][cl][cr];
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(d, 0, sizeof d);
  memset(was, 0, sizeof was);
  getline(cin, s);
  s = '(' + s + ')';
  n = (int)s.length();

  i64 res = go(0, n - 1, 0, 3);
  cout << res << "\n";
  return 0;
}