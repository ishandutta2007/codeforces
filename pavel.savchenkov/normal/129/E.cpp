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
const i64 mod = (int)1e9 + 7;

using namespace std;

int c[3010][3010];
int n, m, k;

int main() {
 // freopen("input.txt","r",stdin);
  memset(c, 0, sizeof c);
  forn(i, 3001)
   c[i][i] = 1;
  forn(i, 3001)
   c[i][0] = 1;

  foran(i, 1, 3001)
   foran(j, 1, i)
    c[i][j] = (c[i - 1][j] + c[i - 1][j - 1]) % mod;

  cin >> n >> m >> k;


  i64 res = c[n - 1][k + k];
  res *= (i64)c[m - 1][k + k];
  res %= mod;

  cout << res << endl;
  return 0;
}