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

#define y1 __y1
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

int a, b, x1, x2, y1, y2;
int x;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> a >> b >> x1 >> y1 >> x2 >> y2;
  a += a; b += b;

  x = x1;
  x1 = x1 + y1;
  y1 = x - y1;
  x = x2;
  x2 = x2 + y2;
  y2 = x - y2;

  int i1, j1, i2, j2;
  i1 = x1 / a;
  if  (x1 < 0) i1--;
  i2 = x2 / a;
  if  (x2 < 0) i2--;

  j1 = y1 / b;
  if  (y1 < 0) j1--;
  j2 = y2 / b;
  if  (y2 < 0) j2--;

  int res = min( abs(i1 - i2), abs(j1 - j2) );
  res += max( abs(i1 - i2), abs(j1 - j2) ) - min( abs(i1 - i2), abs(j1 - j2) );

  cout << res << endl;
  return 0;
}