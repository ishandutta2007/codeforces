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
 
const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
const int mod = 1000000007;
 
using namespace std;
int n, k;

bool can(int v)
{
 int r = 0;
 for (; v>0; v /= k)
  r += v;
 return r >= n;
}

int main() {
  cin >> n >> k;
  int l = 0; int r = 1000000000;
  while (l != r - 1)
  {
   int m = (l + r) >> 1;
   if (!can(m)) l = m; else r = m;
  } 
  
  cout << l + 1;
  return 0;
}