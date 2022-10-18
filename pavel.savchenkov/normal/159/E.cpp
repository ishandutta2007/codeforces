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
const double eps = 1e-9;
const int int_inf = 2000000000;
const i64 i64_inf = 1000000000000000000LL;
const double pi = acos(-1.0);
using namespace std;
struct kubik
{
    int c,s,id;
    kubik() {};
    friend bool operator <(const kubik &a,const kubik &b)
    {
        if (a.c != b.c) return a.c < b.c;
        return a.s > b.s;
    };
};
int n;
kubik a[100500];
vector <kubik> g[100500];
int size = 0;
i64 d[100500];
int p[100500];
i64 res = 0;
int p1,p2,sz1,sz2;

int main() {
  scanf("%d",&n);
  forn(i,n) { scanf("%d%d",&a[i].c,&a[i].s); a[i].id = i + 1; }
  sort(a,a+n);
  
  g[0].pb(a[0]);
  foran(i,1,n) if (a[i].c == a[i-1].c) g[size].pb(a[i]); else size++,g[size].pb(a[i]); size++;

  memset(d,0,sizeof(d));
  
  forn(i,size)
  {
      
    i64 sum = 0;
    forn(j,(int)g[i].size())
    {
        sum += g[i][j].s;
        if (sum > d[j + 1]) { d[j + 1] = sum; p[j + 1] = i; }
    }
    if (i == size - 1) continue;
    
    sum = 0;
    forn(sz,(int)g[i+1].size())
    {
        sum += g[i+1][sz].s;
        int tsz = sz + 1;
        for (int nsz = tsz - 1; nsz <= tsz + 1; nsz++)
        {
            if (nsz == 0) continue;
            if (sum + d[nsz] > res && d[nsz] > 0) { res = sum + d[nsz]; p1 = i + 1; p2 = p[nsz]; sz1 = tsz; sz2 = nsz; }
        }
    }
    
  }
  
  
  cout << res << endl << sz1 + sz2 << endl;
  int t1 = 0; int t2 = 0; sz1--; sz2--;

  if (sz1 < sz2) { printf("%d ",g[p2][0].id); t2++; }
  
  while (t1 <= sz1 || t2 <= sz2)
  {
    if (t1 <= sz1) { printf("%d ",g[p1][t1].id); t1++; }
    if (t2 <= sz2) { printf("%d ",g[p2][t2].id); t2++; }
  }

  return 0;
}