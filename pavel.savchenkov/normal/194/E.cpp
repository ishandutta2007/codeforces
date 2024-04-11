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

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

string s[4];
int h12, h13, h14, h23, h24, h34;

vi r;

bool can(int len)
{
  double a[7][8] =
  {
  { 1, 1, 1, 1, 0, 0, 0, h12 },
  { 1, 1, 0, 0, 1, 1, 0, h13 },
  { 1, 0, 1, 0, 1, 0, 1, h14 },
  { 0, 0, 1, 1, 1, 1, 0, h23 },
  { 0, 1, 0, 1, 1, 0, 1, h24 },
  { 0, 1, 1, 0, 0, 1, 1, h34 },
  { 1, 1, 1, 1, 1, 1, 1, len }
  };

  for (int row = 0, col = 0; row < 7 && col < 8; col++)
  {
          int sel = row;
          for (int i = row + 1; i < 7; i++)
           if  (fabs(a[i][col]) > fabs(a[sel][col])) sel = i;
          if  (fabs(a[sel][col]) < eps) return 0;

          for (int i = 0; i < 8; i++)
           swap(a[sel][i], a[row][i]);

          double c = a[row][col];
          for (int i = 0; i < 8; i++)
           a[row][i] /= c;

          for (int i = 0; i < 7; i++)
          {
              if  (i == row) continue;
              double c = a[i][col];
              for (int j = col; j < 8; j++)
               a[i][j] -= c * a[row][j];
          }

          row++;
  }

  for (int i = 0; i < 7; i++)
   if  ( fabs(((int)a[i][7]) - a[i][7]) > eps || (int)a[i][7] < 0) return 0;

  forn(i, 7)
   r.pb((int)a[i][7]);
  int sum = 0;
  forn(i, r.size())
   sum += r[i];

  assert(sum == len);
  return 1;
}

string g[] = { "bbb", "bba", "bab", "baa", "abb", "aba", "aab" };

int main() {
  cin >> h12 >> h13 >> h14 >> h23 >> h24 >> h34;

  for (int i = 0; i <= 300000; i++)
   if  (can(i))
   {
       int len = i;
       printf("%d\n", len);
       forn(j, len) printf("a"); puts("");

       forn(j, r.size())
       {
         for (int k = 0; k < r[j]; k++)
          for (int c = 1; c <= 3; c++)
           s[c] += g[j][c - 1];
       }

       forn(j, 3)
        printf("%s\n", s[j + 1].c_str());
       return 0;
   }

  puts("-1");
  return 0;
}