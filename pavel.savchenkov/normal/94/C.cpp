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

int n, m, a, b;

int solve()
{
  int res = 1;
  if  ((a - 1) % m != 0) res++;
  if  (b % m != 0) res++;
  
  if  ((a - 1) / m == (b - 1) / m) return 1;
  if  ( abs((a - 1) / m - (b - 1) / m) == 1)
  {
   if  ((a - 1) % m == 0 && b % m == 0) return 1;
   return 2;
  }
  if  (res < 3) return res;
  if  (a % m == (b + 1) % m) return 2;
  return res;
}

int main() {
  cin >> n >> m >> a >> b;
  if  (b == n)
   while  (b % m != 0) b++;
  
  cout << solve() << endl;
  return 0;
}