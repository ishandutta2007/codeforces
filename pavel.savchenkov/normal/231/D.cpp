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
#define z1 sjidhfidsjhfi

const double EPS = 1e-9;
const int INT_INF = 0x7FFFFFFF;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFF;
const double PI = acos(-1.0);

using namespace std;

int x, y, z;
int x1, y1, z1;
int a[10];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d%d%d%d%d%d", &x, &y, &z, &x1, &y1, &z1);
  forn(i, 6) scanf("%d", &a[i + 1]);
  
  int res = 0;
  if  (x > x1) res += a[6];
  if  (x < 0) res += a[5];
  if  (z > z1) res += a[4];
  if  (z < 0) res += a[3];
  if  (y > y1) res += a[2];
  if  (y < 0) res += a[1];

  printf("%d\n", res);
  return 0;
}