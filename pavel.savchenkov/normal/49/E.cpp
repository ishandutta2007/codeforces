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

int len[2];
char s[2][60];
bool can[2][60][60][30];
int d[60][60];
int n;
vii g[30];

void calc_can(int id, int l, int r, int c)
{
    can[id][l][r][c] = 0;
    if  (l == r) { can[id][l][r][c] = (s[id][l] == c); return; }

    for (int i = 0; i < (int)g[c].size(); i++)
     for (int j = 0; j < r; j++)
      can[id][l][r][c] |= can[id][l][j][g[c][i].f] && can[id][j + 1][r][g[c][i].s];

}

void calc_d(int f1, int f2)
{
 d[f1][f2] = int_inf;
 for (int c = 0; c < 'z' - 'a' + 1; c++)
  if  (can[0][0][f1][c] && can[1][0][f2][c]) { d[f1][f2] = 1; return; }

 for (int c = 0; c < 'z' - 'a' + 1; c++)
  for (int i = 1; i <= f1; i++)
   for (int j = 1; j <= f2; j++)
    if  (can[0][i][f1][c] && can[1][j][f2][c] && d[i - 1][j - 1] != int_inf)
     d[f1][f2] = min(d[f1][f2], d[i - 1][j - 1] + 1);
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  forn(i, 2) gets(s[i]);
  forn(i, 2) len[i] = (int)strlen(s[i]);

  forn(i, 2)
   for (int j = 0; s[i][j]; j++)
    s[i][j] -= 'a';

  scanf("%d\n", &n);
  forn(i, n)
  {
      char c, c1, c2;
      scanf("%c->%c%c\n", &c, &c1, &c2);
      g[c - 'a'].pb( mp(c1 - 'a', c2 - 'a') );
  }

  for (int id = 0; id < 2; id++)
   for (int Len = 1; Len <= len[id]; Len++)
    for (int c = 0; c < 'z' - 'a' + 1; c++)
     for (int l = 0; l < len[id]; l++)
       if  (l + Len - 1 < len[id]) calc_can(id, l, l + Len - 1, c);

  for (int i = 0; i < len[0]; i++)
   for (int j = 0; j < len[1]; j++)
    calc_d(i, j);

  if  (d[len[0] - 1][len[1] - 1] == int_inf)
   puts("-1");
    else printf("%d", d[len[0] - 1][len[1] - 1]);
  return 0;
}