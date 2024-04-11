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
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1LL << 63 - 1LL;
const double PI = acos(-1.0);

using namespace std;

i64 d[2][5010];
vi c;
int a[5010];
int n;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d", &n);
  forn(i, n) scanf("%d", a + i), c.pb(a[i]);
  sort(c.begin(), c.end());
  c.resize(unique(c.begin(),c.end()) - c.begin());

  forn(j, c.size())
  {
   d[0][j] = 1LL * abs(a[0] - c[j]);
   if  (j) d[0][j] = min(d[0][j - 1], d[0][j]);
  }

  int id = 1;

  for (int i = 1; i < n; i++)
  {
   forn(j, c.size())
    d[id][j] = I64_INF;

   forn(j, c.size())
   {
       if  (j) d[id][j] = min(d[id][j], d[id][j - 1]);
       d[id][j] = min(d[id][j], d[1 - id][j] + 1LL * abs(a[i] - c[j]));
   }
   id = 1 - id;
  }

  cout << d[1 - id][(int)c.size() - 1] << '\n';

  return 0;
}