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
int a[200500];
vector <pii> d[200500];
int n, m, k;
int res = 1;

int main() {
  cin >> n >> m >> k;
  forn(i,n) scanf("%d",&a[i]);
  int cnt = 1;
  foran(i,1,n) 
    if (a[i] != a[i-1]) d[a[i-1]].pb(mp(cnt,i-1)), cnt = 1; else cnt++;
  d[a[n-1]].pb(mp(cnt,n-1));
  
  foran(i,1,m+1)
  {
    if (d[i].empty()) continue;
    forn(j,d[i].size()-1)
        d[i][j].s = d[i][j+1].s - d[i][j+1].f - d[i][j].s;
    d[i].rbegin()->second = int_inf;
  }
    
  foran(i,1,m+1)
  {
    if (d[i].empty()) continue;
    int l = 0; int r = 0; int len = (int)d[i].size();
    int sum1 = d[i][0].f; int sum2 = 0;
    
    while (r < len && l < len && l <= r)
    {
        if (sum2 <= k) res = max(res,sum1);
        if (l == r && l == (int)d[i].size() - 1) break;
        if (l == r) r++, sum1 = d[i][l].f + d[i][l+1].f, sum2 = d[i][l].s; 
         else
         if (sum2 + d[i][r].s <= k) 
            sum2 += d[i][r].s, sum1 += d[i][r+1].f, r++;
          else
            sum1 -= d[i][l].f, sum2 -= d[i][l].s, l++;
    }
  }
  
  cout << res << endl;
  return 0;
}