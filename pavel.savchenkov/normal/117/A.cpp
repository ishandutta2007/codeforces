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
int n, m;

int min_after(int s, int t)
{
    int up = (t - s + 1 + m + m - 3) / (m + m - 2);
    up = s - 1 + 2 * up * (m - 1);
    int down = (t - 2 * (m - 1) + s - 1 + m + m - 3) / (m + m - 2);
    down = 2 * (m - 1) - s + 1 + 2 * down * (m - 1);
    return min(up, down);
}

int go(int s, int f, int t)
{
 if  (s == f) return t;
 int t1 = min_after(s, t);
 return min_after(f, t1);
}

int main() {
  cin >> n >> m;

  forn(i, n)
  {
      int s, f, t;
      scanf("%d%d%d", &s, &f, &t);
      printf("%d\n", go(s, f, t));
  }

  return 0;
}