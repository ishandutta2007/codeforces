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
const int INT_INF = 0x7FFFFFFE;
const i64 I64_INF = 0x7FFFFFFFFFFFFFFELL;
const double PI = acos(-1.0);

using namespace std;

i64 n;

i64 gcd(i64 a, i64 b) { 
 return (b == 0) ? a : gcd(b, a % b); 
}

i64 lcm(i64 a, i64 b) {
 return a * (b / gcd(a , b));
}

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;

  i64 res = 1LL;
  
  for (i64 a = n; a >= max(1LL, n - 300LL); a--)
   for (i64 b = max(a - 1LL, 1LL); b >= max(1LL, n - 300LL); b--)
    for (i64 c = max(1LL, b - 1LL); c >= max(1LL, n - 300LL); c--)
    res = max(res, lcm(lcm(a, b), c));

  
  cout << res << '\n';
  return 0;
}