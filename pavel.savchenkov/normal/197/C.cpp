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

char s[100500];
char ma[100500];
int id[100500];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  gets(s);
  int n = (int)strlen(s);
  ma[n - 1] = s[n - 1]; id[n - 1] = n - 1;

  for (int i = n - 2; i >= 0; i--)
  {
      ma[i] = s[i]; id[i] = i;
      if  (ma[i + 1] > ma[i]) { ma[i] = ma[i + 1]; id[i] = id[i + 1]; }
  }

  int i = 0;
  while (i <= n - 1)
  {
      printf("%c", ma[i]);
      i = id[i] + 1;
  }
  return 0;
}