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

const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
 
using namespace std;
struct p
{
    int x,y;
    p() {};
};

struct tr
{
    p a,b;
    tr(int x1=0,int y1=0,int x2=0,int y2=0) { a.x=x1; a.y=y1; b.x=x2; b.y=y2; };
};

int dest(tr F, tr S)
{
    if (F.a.x == F.b.x && S.a.x == S.b.x)
    {
        int y = F.a.y; int yy = F.b.y;
        int y1 = S.a.y; int yy1 = S.b.y;
        if ( min(y,yy) > max(y1,yy1) || min(y1,yy1) > max(y,yy))
        {
            if (y1 < yy1) swap(y1,yy1);
            if (y < yy) swap(y,yy);
            int dx = abs(F.a.x - S.b.x);
            int dy = min(abs(yy1 - y),abs(y1-yy));
            return dx * dx + dy * dy;
        } else return (F.a.x - S.a.x) * (F.a.x - S.a.x);
    } else
    if (F.a.y == F.b.y && S.a.y == S.b.y)
    {
        int x = F.a.x; int xx = F.b.x;
        int x1 = S.a.x; int xx1 = S.b.x;
        if ( min(x,xx) > max(x1,xx1) || min(x1,xx1) > max(x,xx))
        {
            if (x1 < xx1) swap(x1,xx1);
            if (x < xx) swap(x,xx);
            int dy = abs(F.a.y - S.b.y);
            int dx = min(abs(xx1 - x), abs(x1-xx));
            return dx * dx + dy * dy;
        } else return (F.a.y - S.a.y) * (F.a.y - S.a.y);
    } else
    {
        if (F.a.y == F.b.y) swap(F,S);
        int y = F.b.y;
        int y1 = F.a.y;
        int x = S.a.x;
        int x1 = S.b.x;
        if (y1 < y) swap(y,y1);
        if (x1 < x) swap(x,x1);
        if (S.a.y <= y1 && S.a.y >= y) return min( (x - F.b.x)*(x - F.b.x), (x1 - F.b.x)*(x1 - F.b.x) );
        if (F.a.x >= x && F.a.x <= x1) return min( (y1 - S.a.y)*(y1 - S.a.y), (y - S.a.y) * (y - S.a.y) );
        if (abs(x - F.a.x) > abs(x1 - F.a.x)) swap(x,x1);
        if (abs(y - S.a.y) < abs(y1 - S.a.y)) swap(y,y1);
        int dx = F.a.x - x;
        int dy = y1 - S.a.y;
        return dx * dx + dy * dy;
    }
}

int n;
int a,aa,b;

p A; p B;
tr c[1100];

int d[1050];

int main() {
  cin >> a >> b;
  aa = a;
  a = a * a; 
  cin >> A.x >> A.y >> B.x >> B.y;
  cin >> n;
  forn(i,n)
      scanf("%d%d%d%d",&c[i].a.x,&c[i].a.y,&c[i].b.x,&c[i].b.y);
  
  if ( (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y) <= a)
  {
    int de = (A.x - B.x)*(A.x - B.x) + (A.y - B.y)*(A.y - B.y);
    printf("%.8lf",(double)sqrt((double)de));
    return 0;
  }
  
  forn(i,n)
    if (dest(tr(A.x,A.y,A.x,A.y),c[i]) <= a) d[i] = 1; else d[i] = int_inf;
  queue <int> q;
  forn(i,n) if (d[i] < int_inf) q.push(i);
  
  double res = int_inf;
  
  while (!q.empty())
  {
    int j = q.front();
    q.pop();
    if (dest(tr(B.x,B.y,B.x,B.y),c[j]) <= a) 
        res = min(res,(double)d[j]*(aa+b) + (double)sqrt((double)dest(tr(B.x,B.y,B.x,B.y),c[j])));
    forn(i,n)
        if (dest(c[i],c[j]) <= a && i != j && d[i] > d[j] + 1) q.push(i), d[i] = d[j] + 1;
  }
  if (res == int_inf) { cout << "-1"; return 0; }
 
  printf("%.8lf",(double)res);
  return 0;
}