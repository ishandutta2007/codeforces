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
struct lemming
{
 int m,v,id;
 lemming() {}
 friend bool operator <(const lemming &a,const lemming &b)
 {
  if (a.m != b.m) return a.m < b.m; return a.v < b.v;
 }
};
int n,k,h;
lemming p[100500];

bool can(double t)
{
 int j = 1;
 for (int i=0; i < n && j <= k; i++)
  if ((double)j * h <= (double)t*p[i].v) ++j;
 return j > k;
}

int main() {
  cin >> n >> k >> h;
  forn(i,n) scanf("%d",&p[i].m);
  forn(i,n) scanf("%d",&p[i].v), p[i].id = i + 1;
  sort(p,p+n);
  
  double l = 0; double r = 1e9 + 1;
  int iter = 500;
  int it = 0;

  while (it < iter)
  {
   double m = (l + r) * 0.5;
   if (!can(m)) l = m; else r = m; it++;
  }
  
 int j = 1; 
 for (int i=0; i < n && j <= k; i++)
  if ((double)j * h <= (double)r*p[i].v) printf("%d ",p[i].id), ++j;
  return 0;
}