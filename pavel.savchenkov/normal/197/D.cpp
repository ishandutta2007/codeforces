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
const int MaxHash =  1 << 23;

using namespace std;

char s[1600][1600];
int n, m;
pii hash[MaxHash];

int visited = 0;

int dx[] = { 1, -1, 0,  0 };
int dy[] = { 0,  0, 1, -1 };

void OK()
{
    puts("Yes"); exit(0);
}

bool add(int i, int j)
{
  int h = (i * 100007 + j * 321973) & (MaxHash - 1);

  while (hash[h] != mp(0, 0) && hash[h] != mp(i, j))
   h = (h + 1) & (MaxHash - 1);

  if  (hash[h] == mp(i, j)) return 0;

  hash[h] = mp(i, j);
  return 1;
}


void bfs(int i, int j)
{
  queue <pii> q;
  q.push(mp(i, j));

  while (!q.empty())
  {
      if  (visited > n * m) OK();
      visited++;

      int curi = q.front().f;
      int curj = q.front().s;
      add(curi, curj);
      q.pop();

      for (int z = 0; z < 4; z++)
      {
          int ni = curi + dx[z];
          int nj = curj + dy[z];
          if  (!add(ni, nj)) continue;
          int I = (ni % n + n) % n;
          int J = (nj % m + m) % m;
          if  (s[I][J] == '#') continue;

          add(ni, nj);
          q.push(mp(ni, nj));
      }
  }

}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d%d\n", &n, &m);

  forn(i, n)
   gets(s[i]);

  memset(hash, 0, sizeof hash);
  forn(i, n)
   forn(j, m)
    if  (s[i][j] == 'S') bfs(i, j);

  puts("No");
  return 0;
}