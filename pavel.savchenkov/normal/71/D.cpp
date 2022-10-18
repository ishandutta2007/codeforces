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

using namespace std;

char dost[] = { '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K', 'A' };
char mast[] = { 'C', 'D', 'H', 'S' };
bool has[13][4];
int n, m;

char s[55][55][2];

bool in(int x, int y, int x1, int y1)
{
   return x1 >= x && x1 <= x + 2 && y1 >= y && y1 <= y + 2;
}

bool ok(int i, int j)
{
    int OK = 1;
    for (int ii = i; ii < i + 3; ii++)
     for (int jj = j; jj < j + 3; jj++)
      if  (s[ii][jj][1] != s[i][j][1]) OK = 0;
    if  (OK) return 1;

    string str = "";
    for (int ii = i; ii < i + 3; ii++)
     for (int jj = j; jj < j + 3; jj++)
      str += s[ii][jj][0];

    sort(str.begin(), str.end());
    str.resize( unique(str.begin(), str.end()) - str.begin());
    return (int)str.length() == 9;
}

int I1, J1, I2, J2;

bool check()
{
  for (int i1 = 0; i1 < n - 2; i1++)
   for (int j1 = 0; j1 < m - 2; j1++)
    for (int i2 = 0; i2 < n - 2; i2++)
     for (int j2 = 0; j2 < m - 2; j2++)
     {
         if  (in(i1, j1, i2, j2) || in(i1, j1, i2 + 2, j2) || in(i1, j1, i2, j2 + 2)
              || in(i1, j1, i2 + 2, j2 + 2))
          continue;

         if  (ok(i1, j1) && ok(i2,  j2)) { I1 = i1; J1 = j1; I2 = i2; J2 = j2; return 1; }
     }
  return 0;
}

void solve0()
{
    if  (!check()) return;
    puts("Solution exists.");
    puts("There are no jokers.");
    printf("Put the first square to (%d, %d).\n", I1 + 1, J1 + 1);
    printf("Put the second square to (%d, %d).\n", I2 + 1, J2 + 1);
    exit(0);
}

void solve1()
{
    bool OK = 0;
    int II, JJ;
    char num;

    forn(i, n)
     forn(j, m)
      if  (s[i][j][0] == 'J' && (s[i][j][1] == '1' || s[i][j][1] == '2'))
        for (int ii = 0; ii < 13 && !OK; ii++)
         for (int jj = 0; jj < 4 && !OK; jj++)
          if  (!has[ii][jj])
          {
              num = s[i][j][1];
              s[i][j][0] = dost[ii];
              s[i][j][1] = mast[jj];
              if  (check()) { OK = 1; II = ii; JJ = jj; }
              s[i][j][1] = num;
          }

    if  (!OK) return;
    puts("Solution exists.");
    printf("Replace J%c with %c%c.\n", num, dost[II], mast[JJ]);
    printf("Put the first square to (%d, %d).\n", I1 + 1, J1 + 1);
    printf("Put the second square to (%d, %d).\n", I2 + 1, J2 + 1);
    exit(0);
}

void solve2()
{
  int joki1, jokj1, joki2, jokj2;
  forn(i, n)
   forn(j, m)
    if  (s[i][j][0] == 'J' && s[i][j][1] == '1') joki1 = i, jokj1 = j;
    else if  (s[i][j][0] == 'J' && s[i][j][1] == '2') joki2 = i, jokj2 = j;

 for (int ii1 = 0; ii1 < 13; ii1++)
  for (int jj1 = 0; jj1 < 4; jj1++)
   for (int ii2 = 0; ii2 < 13; ii2++)
    for (int jj2 = 0; jj2 < 4; jj2++)
    {
        if  (ii1 == ii2 && jj1 == jj2) continue;
        if  (has[ii1][jj1] || has[ii2][jj2]) continue;
        s[joki1][jokj1][0] = dost[ii1];
        s[joki1][jokj1][1] = mast[jj1];
        s[joki2][jokj2][0] = dost[ii2];
        s[joki2][jokj2][1] = mast[jj2];

        if  (check())
        {
           puts("Solution exists.");
           printf("Replace J1 with %c%c and J2 with %c%c.\n", dost[ii1], mast[jj1], dost[ii2], mast[jj2]);
           printf("Put the first square to (%d, %d).\n", I1 + 1, J1 + 1);
           printf("Put the second square to (%d, %d).\n", I2 + 1, J2 + 1);
           exit(0);
        }
    }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(has, 0, sizeof has);
  scanf("%d%d\n", &n, &m);

  bool was1 = 0; bool was2 = 0;
  forn(i, n)
   forn(j, m)
   {
      scanf("%c%c ", &s[i][j][0], &s[i][j][1]);
      if  (s[i][j][0] == 'J' && s[i][j][1] == '1') was1 = 1;
      if  (s[i][j][0] == 'J' && s[i][j][1] == '2') was2 = 1;
      for (int ii = 0; ii < 13; ii++)
       for (int jj = 0; jj < 4; jj++)
        if  (dost[ii] == s[i][j][0] && mast[jj] == s[i][j][1])
            has[ii][jj] = 1;
   }

  if  (!was1 && !was2) solve0(); else
   if  (was1 && was2) solve2(); else solve1();

  puts("No solution.");
  return 0;
}