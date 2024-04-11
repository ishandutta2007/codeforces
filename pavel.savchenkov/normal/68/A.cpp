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

const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

int a, b;
int p[4];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  forn(i, 4) cin >> p[i]; cin >> a >> b;

  int res = 0;
  for (int x = a; x <= b; x++)
  {
   int cnt = 0;

   sort(p, p + 4);
   do
   {
     int X = x;
     forn(i, 4) X %= p[i];
     cnt += X == x;
   } while (next_permutation(p, p + 4));

   res += cnt >= 7;
  }

  printf("%d\n", res);
  return 0;
}