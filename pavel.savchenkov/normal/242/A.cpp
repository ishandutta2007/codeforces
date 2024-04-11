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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 2 * (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);

using namespace std;

int x, y, a, b;
vii r;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> x >> y >> a >> b;


  for (int x1 = a; x1 <= x; x1++)
    for (int x2 = b; x2 <= y; x2++)
        if  (x1 > x2) r.pb(mp(x1, x2));

  sort(r.begin(), r.end());
  printf("%d\n", (int)r.size());
  forn(i, r.size())
    printf("%d %d\n", r[i].f, r[i].s);
  return 0;
}