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

int n, res = int_inf;

void Go(int a, int b, int len)
{
  if  (len >= res) return;
  if  (a == 1 && b == 1) { res = len; return; }
  if  (a > b) swap(a, b);
  if  (a == 1 && b == 2) { res = min(res, len + 1); return; }
  if  ((b - a) % a == 0 && a != 1) return;
  Go(a, b - ((b - 1) / a) * a , len + (b - 1) / a);
}

int main() {
  cin >> n;
  foran(i, 1, n + 1)
   Go(i, n, 0);

  cout << res << endl;
  return 0;
}