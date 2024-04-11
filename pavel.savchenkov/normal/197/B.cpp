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

int n, m;
int a0;
int b0;

int gcd(int a, int b) { return (b) ? gcd(b, a%b) : a; }

int main() {
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  cin >> a0; int t;
  forn(i, n) cin >> t;
  cin >> b0;

  if  (n > m)
  {
      if  (a0 * b0 < 0) printf("-");
      puts("Infinity");
      return 0;
  }

  if  (m > n) { puts("0/1"); return 0; }

  int g = gcd(a0, b0);
  a0 /= g;
  b0 /= g;
  if  (b0 < 0) { a0 = -a0; b0 = -b0; }
  printf("%d/%d", a0, b0);

  return 0;
}