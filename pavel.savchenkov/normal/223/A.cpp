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

pair <char, int> st[100500];
int sz = 0;

char s[100500];
int f[100500];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  gets(s);
  memset(f, -1, sizeof f);

  for (int i = 0; s[i]; i++)
  {
      if  (!sz) st[sz++] = mp(s[i], i); else
       if  (s[i] == ')' && st[sz - 1].f == '(' || s[i] == ']' && st[sz - 1].f == '[')
        f[i] = st[sz - 1].s, f[ st[sz - 1].s ] = i, sz--; else
         st[sz++] = mp(s[i], i);
  }

  for (int i = 0; s[i]; i++)
   if  (f[i] > i)
   {
       int j = f[i];
       while (1)
       {
           j++;
           if  (f[j] > j) j = f[j]; else break;
       }
       f[i] = j - 1;
       i = j - 1;
   }

  int best = -1;
  int ma = 0;

  for (int i = 0; s[i]; i++)
   if  (f[i] > i)
   {
     int now = 0;
     for (int j = i; j <= f[i]; j++)
      now += (s[j] == '[');
     if  (now > ma) { best = i; ma = now; }
     i = f[i];
   }

//  for (int i = 0; s[i]; i++)
//   printf("%d ", f[i]);

  printf("%d\n", ma);
  if  (best != -1)
   for (int i = best; i <= f[best]; i++)
    putchar(s[i]);
  return 0;
}