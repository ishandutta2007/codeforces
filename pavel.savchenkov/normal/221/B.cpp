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

bool has[10];
int x, X;
vi d;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  memset(has, 0, sizeof has);
  cin >> x;
  X = x;
  while (X) has[X % 10] = 1, X /= 10;

  for (int i = 1; i * i <= x; i++)
  {
   if  (x % i == 0) d.pb(i);
   if  (x / i != i && x % i == 0) d.pb(x / i);
  }

  int res = 0;
  forn(i, d.size())
      while (d[i])
      {
          if  (has[d[i] % 10]) { res++; break; }
          d[i] /= 10;
      }

  cout << res << '\n';
  return 0;
}