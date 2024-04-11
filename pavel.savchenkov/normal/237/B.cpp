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
const int INT_INF = 2*(int)1e9;
const i64 I64_INF = (i64)1e18;
const double PI = acos(-1.0);

using namespace std;

int a[100][100];
int n;
int c[100];
pii w[50 * 50 + 100];
int s;
vector < pair <pii, pii> > r;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n; s = 0;
  forn(i, n) { scanf("%d", &c[i]); s += c[i]; }
  forn(i, n)
   forn(j, c[i]) {
    int x;
    scanf("%d", &x);
    w[x] = mp(i, j);
    a[i][j] = x;
   }

  int curi = 0;
  int curj = 0;
  int x = 1;

  while (x <= s) {
   if  (curi != w[x].f || curj != w[x].s)
    r.pb(mp(mp(curi, curj), w[x]));
   
   int y = a[curi][curj];

   swap(a[curi][curj], a[w[x].f][w[x].s]);
   swap(w[y], w[x]);
   

   if  (curj == c[curi] - 1)
    curj = 0, curi++;
   else
    curj++;
   x++;
  }

  printf("%d\n", (int)r.size());
  forn(i, r.size())
   printf("%d %d %d %d\n", r[i].f.f+1, r[i].f.s+1, r[i].s.f+1, r[i].s.s+1);
  return 0;
}