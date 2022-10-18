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

int a[100500];
int n, m;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;

  if  (m % 2 == 1)
  {
  int r = ((m + 1) / 2) - 1;
  int l = r - 1;

  int i = 0;
  while (i != n)
  {
     a[i] = r; r++; i++;
     if  (i == n) break;

     if  (l != -1)
      a[i] = l, l--, i++;

     if  (r == m)
     {
         r = ((m + 1) / 2) - 1;
         l = r - 1;
     }
  }
  } else
  {
   int l = ((m + 1) / 2) - 1;
   int r = l + 1;

  int i = 0;
  while (i != n)
  {
     a[i] = l; l--; i++;
     if  (i == n) break;
     a[i] = r; r++; i++;

     if  (r == m)
     {
         l = ((m + 1) / 2) - 1;
         r = l + 1;
     }
  }
  }
  forn(i, n)
   printf("%d\n",a[i] + 1);
  return 0;
}