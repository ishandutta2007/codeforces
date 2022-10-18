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
const int INT_INF = 0x7FFFFFF;
const i64 I64_INF = 0x7FFFFFFFFFFFFFF;
const double PI = acos(-1.0);

using namespace std;

int dx[4] = {  0, 1, 0, -1 };
int dy[4] = { -1, 0, 1,  0 };

int d[15][15][(1 << 16) + 100];
int n, m, l;
char s[20][20];
int res = INT_INF;


bool on(int x, int y)
{
  return (x >= 0 && x < n && y >= 0 && y < m);
}

void put(int & mask, int pos, int val)
{
  pos = (pos - 1) * 2;
  mask |= (val << pos);
}

int get(int mask, int pos)
{
  pos = (pos - 1) * 2;
  return (mask & (3 << pos)) >> pos;
}

bool valid(int xx, int yy, int x, int y, int mask)
{
  if  (s[xx][yy] == '#') return 0;

  for (int i = 1; i < l - 1; i++)
  {
   x += dx[get(mask, i)];
   y += dy[get(mask, i)];
   if (xx == x && yy == y) return 0;
  }

  return 1;
}

queue <int> qx;
queue <int> qy;
queue <int> qmask;

void bfs()
{

 while (!qx.empty())
 {
   int x = qx.front(); qx.pop();
   int y = qy.front(); qy.pop();
   int mask = qmask.front(); qmask.pop();

   if  (s[x][y] == '@') res = min(res, d[x][y][mask]);

   forn(i, 4)
    if (on(x + dx[i], y + dy[i]) && valid(x + dx[i], y + dy[i], x, y, mask))
    {
     int nmask = (mask << 2) & ((1 << 16) - 1);
     put(nmask, 1, (i + 2) & 3);

     if  (d[x + dx[i]][y + dy[i]][nmask] > d[x][y][mask] + 1)
      { 
        d[x + dx[i]][y + dy[i]][nmask] = d[x][y][mask] + 1; 
        qx.push(x + dx[i]); qy.push(y + dy[i]); qmask.push(nmask); 
      }
    }
 }

}

int main() {
//  freopen("in.txt","r",stdin);
//  freopen("output.txt","w",stdout);

  scanf("%d%d\n", &n, &m);
  memset(d, -1, sizeof d);
  forn(i, n) gets(s[i]);

  int mask = 0, x, y;

  forn(i, n)
   forn(j, m)
   if  (s[i][j] == '1')
   {
     x = i; y = j; l = 1;
     s[x][y] = '.';

     for (l = 1; ; l++)
     {
      int c = 0;
      for (; c < 4; c++)
       if  (on(x + dx[c], y + dy[c]) && s[x + dx[c]][y + dy[c]] == '1' + l) break;

      if  (c == 4) break;
      x += dx[c]; y += dy[c];
      s[x][y] = '.';
      put(mask, l, c);
     }

     x = i; y = j;
   }

  qx.push(x); qy.push(y); qmask.push(mask);
  forn(i, n)
   forn(j, m)
    forn(k, (1 << 16))
     d[i][j][k] = INT_INF;
  d[x][y][mask] = 0;

  bfs();

  if  (res == INT_INF)
   puts("-1");
  else
   printf("%d\n", res);

  return 0;
}