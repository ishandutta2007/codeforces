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

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);

using namespace std;

int d[2001][2001];
int n, m;
int k;
int x[20]; int y[20];

int ma = -int_inf, mai, maj;

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool on(int i, int j)
{
  return i >= 0 && j >= 0 && i < n && j < m;
}

void go(int x, int y)
{
  queue <pii> q;
  q.push( mp(x, y) );
  d[x][y] = 0;

  while (!q.empty())
  {
      pii v = q.front();
      q.pop();
      int x = v.f; int y = v.s;
      forn(i, 4)
       {
           int X = x + dx[i];
           int Y = y + dy[i];
           if  (on(X, Y) && d[X][Y] > d[x][y] + 1) { d[X][Y] = d[x][y] + 1; q.push(mp(X, Y)); }
       }
  }

}

int main() {
  freopen("input.txt","r",stdin);
  freopen("output.txt","w",stdout);
  cin >> n >> m >> k;

  forn(i, n)
   forn(j, m)
    d[i][j] = int_inf;

  forn(i, k)
   cin >> x[i] >> y[i], x[i]--, y[i]--, go(x[i], y[i]);


  forn(i, n)
   forn(j, m)
    if  (d[i][j] > ma)
    {
        mai = i; maj = j; ma = d[i][j];
    }

  cout << mai + 1 << " " << maj + 1 << "\n";
  return 0;
}