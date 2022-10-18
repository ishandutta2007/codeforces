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
int color[2000][2000];
int res = 0;
int cnt1, cnt2;

int dx[] = { -1, -1, -2, -2, 1,  1, 2,  2 };
int dy[] = {  2, -2,  1, -1, 2, -2, 1, -1 };

bool on(int i,int j)
{
    return i >= 0 && j >=0 && i < n && j < m;
}

void dfs(int i,int j, int now)
{
     color[i][j] = now;
     if  (now) cnt1++; else cnt2++;
     forn(next, 8)
      if  ( on(i + dx[next], j + dy[next]) && color[ i + dx[next] ] [ j + dy[next] ] == -1 )
       dfs(i + dx[next], j + dy[next], 1 - now);
}

int main() {
  memset(color, -1, sizeof color);
  cin >> n >> m;
  forn(i, n)
   forn(j, m)
    if  (color[i][j] == -1) cnt1 = cnt2 = 0, dfs(i, j, 1), res += max(cnt1, cnt2);

  cout << res << endl;
  return 0;
}