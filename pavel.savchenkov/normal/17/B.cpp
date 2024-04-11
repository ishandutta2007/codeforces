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
const int mod = (int)1e8;

using namespace std;
int n, m;

int res = 0;
int ans[1010];

int main() {
  cin >> n;
  forn(i, n) scanf("%d", &ans[0]);
  forn(i, n) ans[i] = (int)1e9;
  
  cin >> m;
  forn(i, m)
  {
   int a, b, c;
   scanf("%d%d%d", &a, &b, &c);
   ans[b - 1] = min(ans[b - 1], c);
  }
  int cnt = 0;
  forn(i, n)
   cnt += (ans[i] == (int)1e9), res += (ans[i] == (int)1e9) ? 0 : ans[i];
  
  if (cnt == 1) cout << res << "\n"; else puts("-1");
  return 0;
}