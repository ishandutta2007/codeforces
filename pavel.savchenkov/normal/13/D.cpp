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
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = 510;

struct pt 
{ 
  int x, y;

  pt(int x = 0, int y = 0) : x(x), y(y) {};

  void read () {           
    scanf("%d %d", &x, &y);
  }
};

pt operator -(const pt & a, const pt & b) {
  return pt(a.x - b.x, a.y - b.y);
}

ll operator *(const pt & a, const pt & b) {
  return 1ll * a.x * b.y - 1ll * a.y * b.x; 
}

pt rp[MAXN];
pt bp[MAXN];

int cnt[MAXN][MAXN];
bool cntp[MAXN];

int n, m;

bool under (pt p1, pt p2, pt p3) 
{
  if  (p2.x > p3.x) swap(p2, p3);

  if  (p2.x == p3.x || p1.x < p2.x || p3.x < p1.x) return false;

  if  (p2.x > p3.x) swap(p2, p3);

  pt u = p2 - p1;
  pt v = p3 - p1;

  return u * v < 0;
}

bool above (pt p1, pt p2, pt p3) 
{
  if  (p2.x > p3.x) swap(p2, p3);

  if  (p2.x == p3.x || p1.x < p2.x || p3.x < p1.x) return false;

  pt u = p2 - p1;
  pt v = p3 - p1;

  return u * v > 0;
}

bool check (int i, int j, int k) 
{
  if  (under(rp[j], rp[i], rp[k]))
    swap(i, j);

  if  (under(rp[k], rp[i], rp[j]))
    swap(i, k);

  if  (above(rp[j], rp[i], rp[k]))
    swap(i, j);

  if  (above(rp[k], rp[i], rp[j]))
    swap(i, k);


  if  (under(rp[i], rp[j], rp[k])) {
    int C = 0;

    if  (rp[i].x == rp[j].x)
      C = cnt[j][k] - cnt[i][k];
    else if  (rp[i].x == rp[k].x)
      C = cnt[j][k] - cnt[i][j];
    else
      C = cnt[j][k] - (cnt[i][j] + cnt[i][k] - cntp[i]); 

    return C == 0;
  }

  if  (above(rp[i], rp[j], rp[k])) {
    int C = 0;

    if  (rp[i].x == rp[j].x)
      C = cnt[i][k] - cnt[j][k];
    else if  (rp[i].x == rp[k].x)
      C = cnt[i][j] - cnt[j][k];
    else
      C = cnt[i][j] + cnt[i][k] - cntp[i] - cnt[j][k];
      
    return C == 0;
  }

  return false; 
}

int main() {
  scanf("%d %d", &n, &m);

  for (int i = 0; i < n; i++)
    rp[i].read();

  for (int i = 0; i < m; i++)
    bp[i].read();

  
  for (int i = 0; i < n; i++) 
  {
    cntp[i] = false;
    for (int j = 0; j < m; j++)
      if  (rp[i].x == bp[j].x && bp[j].y < rp[i].y) {
        cntp[i] = true;
        break;
      }
  }

  for (int i1 = 0; i1 < n; i1++)
    for (int i2 = i1 + 1; i2 < n; i2++) 
    {
      cnt[i1][i2] = cnt[i2][i1] = 0;
      for (int j = 0; j < m; j++)
        if  (under(bp[j], rp[i1], rp[i2])) {
          cnt[i1][i2]++;
          cnt[i2][i1]++;
        }
    }

  int res = 0;
  for (int i = 0; i < n; i++)
    for (int j = i + 1; j < n; j++)
      for (int k = j + 1; k < n; k++)
        if  (check(i, j, k))
          res++;

  printf("%d\n", res);
  return 0;
}