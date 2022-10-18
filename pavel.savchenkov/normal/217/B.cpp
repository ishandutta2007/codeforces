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
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

int n, r;
int res = INT_INF;

char s[1005000];
int sz = 0;

void go(int a, int b, int id, int was)
{
    if  (a == 1 && b == 1 && id == 1 && res > was) { res = was; return; }
    if  (a < 1 || b < 1 || id < 1 || (a == 1 && b == 1)) return;

    if  (b == 1)
     go(1, 1, id - (a - 1), was + a - 2); else
    if  (a == 1)
     go(1, 1, id - (b - 1), was + b - 2); else
    if  (a > b)
     go(a % b, b, id - (a / b), was + (a / b) - 1);
      else
       go(a, b % a, id - (b / a), was + (b / a) - 1);
}

bool isGood(int a, int b, int id, int was)
{
   if  (was == res && a == 1 && b == 1 && id == 1)
     { s[sz++] = 'T'; return 1; }
   if  (a < 1 || b < 1 || id < 1 || (a == 1 && b == 1)) return 0;

   if  (b == 1)
   {
     if  (isGood(1, 1, id - (a - 1), was + a - 2))
      {
          char c = (s[sz - 1] == 'T') ? 'B' : 'T';
          forn(i, a - 1)
           s[sz++] = c;
         // printf("a = %d b = %d id = %d was = %d\n", a, b, id, was);
          return 1;
      }
     return 0;
   }

   else
   if  (a == 1)
   {
     if  (isGood(1, 1, id - (b - 1), was + b - 2))
     {
         char c = (s[sz - 1] == 'T') ? 'B' : 'T';
          forn(i, b - 1)
           s[sz++] = c;
        //  printf("a = %d b = %d id = %d was = %d\n", a, b, id, was);
          return 1;
     }
     return 0;
   }

   else
   if  (a > b)
   {
     if  (isGood(a % b, b, id - (a / b), was + (a / b) - 1))
     {
         char c = (s[sz - 1] == 'T') ? 'B' : 'T';
         forn(i, a / b)
          s[sz++] = c;
        //  printf("a = %d b = %d id = %d was = %d\n", a, b, id, was);
         return 1;
     }
     return 0;
   }

   else
   {
      if  (isGood(a, b % a, id - (b / a), was + (b / a) - 1))
      {
         char c = (s[sz - 1] == 'T') ? 'B' : 'T';
         forn(i, b / a)
          s[sz++] = c;
         // printf("a = %d b = %d id = %d was = %d\n", a, b, id, was);
         return 1;
      }
      return 0;
   }
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> r;
  if  (n == 1 && r == 1)
  {
    printf("0\nT"); return 0;
  }

  for (int a = 1; a < r; a++)
   go(a, r - a, n - 1, 0);

  for (int a = 1; a < r; a++)
   if  (isGood(a, r - a, n - 1, 0)) break;

  s[sz] = (s[sz - 1] == 'T') ? 'B' : 'T';
  s[sz + 1] = '\n';

  if  (res == INT_INF) puts("IMPOSSIBLE"); else printf("%d\n", res), puts(s);
  return 0;
}