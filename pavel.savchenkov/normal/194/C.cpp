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

char s[100][100];
int st[100][100];
int n, m;
bool was[100][100];

int dx[] = { 1, -1, 0,  0 };
int dy[] = { 0,  0, 1, -1};

bool on(int i, int j)
{
 return i >= 0 && i < n && j >= 0 && j < m;
}

void dfs(int i,int j)
{
    was[i][j] = 1;
    forn(k, 4)
     if  ( on(i + dx[k], j+ dy[k]) && s[ i + dx[k] ][ j + dy[k] ] == '#' && !was[ i + dx[k] ][ j + dy[k] ])
      dfs(i + dx[k], j + dy[k]);

}

bool check()
{
  int c = 0;
  forn(i, n)
   forn(j, m)
    if  (!was[i][j] && s[i][j] == '#') dfs(i, j), c++;

  if  (c > 1) return 0;
  return 1;
}

int main() {
 // freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d%d\n", &n, &m);
  forn(i, n)
   gets(s[i]);

  memset(st, 0, sizeof st);

  int mi = 5;
  int cnt = 0;
  forn(i, n)
   forn(j, m)
    if  (s[i][j] == '#') cnt++;

  forn(i, n)
   forn(j, m)
   {
       if  (s[i][j] == '.') continue;
       memset(was, 0, sizeof was);
       was[i][j] = 1;
       if  (!check()) { puts("1"); return 0; }
   }

  if  (cnt <= 2) puts("-1"); else puts("2");

  return 0;
}