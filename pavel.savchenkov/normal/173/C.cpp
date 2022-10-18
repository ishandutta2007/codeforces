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
 
using namespace std;
int n,m;
int a[550][550];
int d[550][550][2];

int s[550][550];
int ans = -int_inf;

int sum(int x1, int y1, int x2, int y2)
{
    int res = s[y2][x2];
    if (x1 > 0 && y1 > 0) res += s[y1-1][x1-1];
    if (x1 > 0) res -= s[y2][x1-1];
    if (y1 > 0) res -= s[y1-1][x2];
    return res;
}

void calc()
{
    int c = 0;
    forn(i,n)
        forn(j,m) d[i][j][c] = a[i][j];
    c = 1;
    for (int k=3; k<=max(n,m); k+=2, c=1-c)
     forn(i,n)
      forn(j,m)
      {
        if (i + k > n) continue;
        if (j + k > m) continue;
        d[i][j][c] = sum(j,i,j+k-1,i+k-1) - d[i+1][j+1][1-c] - a[i+1][j];
        ans = max(ans,d[i][j][c]);
      }
}

int main() {
  cin >> n >> m;
  forn(i,n) forn(j,m) 
  {
    scanf("%d",&a[i][j]);
    s[i][j] = a[i][j];
    if (i > 0) s[i][j] += s[i-1][j];
    if (j > 0) s[i][j] += s[i][j-1];
    if (i > 0 && j > 0) s[i][j] -= s[i-1][j-1];
  }

  calc();
  cout << ans << endl;
  return 0;
}