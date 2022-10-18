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

int c[300];
int k;
char s[1050];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(c, 0, sizeof c);
  scanf("%d\n", &k);
  gets(s);
  for (int i = 0; s[i]; i++)
   c[ s[i] ]++;

  bool ok = 1;
  for (int i = 'a'; i <= 'z'; i++)
   if  (c[i] % k != 0 && c[i]) ok = 0;

  if  (!ok && k != 1) puts("-1"); else
   for (int j = 0; j < k; j++)
    for (int i = 'a'; i <= 'z'; i++)
     for (int z = 0; z < c[i] / k; z++)
      printf("%c", i);

  return 0;
}