//#pragma comment (linker, "/STACK:200000000") 
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
#define pb push_back
#define i64 long long
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
using namespace std;
pair <int,int> a[100500];
pair <int,int> b[100500];
int x,y;
vector < pair <int,int> > res;
int n,m;

int main() {
   //freopen("input.txt","r",stdin);
   //freopen("output.txt","w",stdout);
  scanf("%d%d%d%d",&n,&m,&x,&y);
  forn(i,n) { scanf("%d",&a[i].first); a[i].first -= x; a[i].second = i + 1; }
  forn(i,m) { scanf("%d",&b[i].first); b[i].second = i + 1; }
  y = x + y;
  sort(a,a+n); sort(b,b+m);
  
  int t1 = 0; int t2 = 0;
  
  while (1)
  {
    if (t1 == n || t2 == m) break;
    if (b[t2].first > a[t1].first + y) { t1++; continue; }
    if (b[t2].first < a[t1].first) { t2++; continue; }
    res.pb( make_pair(a[t1].second,b[t2].second) ); t1++; t2++;
  }
  
  printf("%d\n",(int)res.size());
  forn(i,(int)res.size())
      printf("%d %d\n",res[i].first,res[i].second);
  return 0;
}