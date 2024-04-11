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
#define sz(A) ((int)(A).size())
#define y1 asxfdsfs
#define y0 dsfgdfggdf


const double EPS = 1e-9;
const int INT_INF = (int)1e9;
const LL LL_INF = 8 * (LL)1e18;
const double PI = acos(-1.0);

using namespace std;

int n, a, b;
int h[210];
int sum[210];

int d[203][4 * (int)1e4 + 5][2];

int main() {
  freopen("input.txt", "r", stdin);
  freopen("output.txt", "w", stdout);
  cin >> n >> a >> b;
  sum[0] = 0;
  forn(i, n) scanf("%d", &h[i]), sum[i + 1] = sum[i] + h[i];

  int res = INT_INF;
  forn(i, n)
    forn(j, a + 1)
        forn(k, 2)
            d[i][j][k] = INT_INF;
  if  (b >= h[0]) d[0][a][1] = 0;
  if  (a >= h[0]) d[0][a - h[0]][0] = 0;

  for (int i = 0; i < n; i++)
    for (int red = 0; red <= a; red++)
        for (int last = 0; last < 2; last++) {

  //          printf("%d %d %d == %d\n", i, red, last, d[i][red][last]);

            if  (i == n - 1) {
                res = min(res, d[i][red][last]);
                continue;
            }

            if  (d[i][red][last] == INT_INF) continue;

            if  (red >= h[i + 1])
                d[i + 1][red - h[i + 1]][0] =
                min(d[i + 1][red - h[i + 1]][0], d[i][red][last] + (last == 1 ? min(h[i], h[i + 1]) : 0));

            int green = b - (sum[i + 1] - (a - red));

            if  (green >= h[i + 1])
                d[i + 1][red][1] =
                min(d[i + 1][red][1], d[i][red][last] + (last == 0 ? min(h[i], h[i + 1]) : 0));
        }


  if  (res == INT_INF)
    puts("-1");
  else
    printf("%d\n", res);
  return 0;
}