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
const int mod = (int)1e9 + 7;

using namespace std;
int n, m;
pii a[1000];
int r[1000];

int solve()
{
 forn(i, m) a[i].f = -a[i].f;
 sort(a, a + m);
 forn(i, m) a[i].f = -a[i].f;
 forn(i, n) r[i] = -1;

 for (int i = 0; i < n; i += 2)
  for (int j = 0; j < m; j++)
   if  (a[j].f > 0 && a[j].s != r[(i - 1 + n)%n] && a[j].s != r[(i + 1)%n])
    { a[j].f--; r[i] = a[j].s; break; }
 
 for (int i = 1; i < n; i += 2)
  for (int j = 0; j < m; j++)
   if  (a[j].f > 0 && a[j].s != r[(i - 1 + n)%n] && a[j].s != r[(i + 1)%n])
    { a[j].f--; r[i] = a[j].s; break; }
 
 forn(i, n)
  if  (r[i] == r[i + 1] || r[i] == -1) return -1;
 if  (r[n - 1] == r[0]) return -1;

 return 1;
}

int main() {
  cin >> n >> m;
  forn(i, m)
   scanf("%d", &a[i].f), a[i].s = i + 1;
  
  
  if  (solve() == -1) { puts("-1"); return 0; }
  
  
  forn(i, n)
   printf("%d ", r[i]);
  return 0;
}