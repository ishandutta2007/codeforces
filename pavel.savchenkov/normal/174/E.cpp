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
int wa[1000010];
int wb[1000010];
int a[1000100];
int b[1000100];
int la,lb;
int res = 0;

int main() {
  memset(wa,-1,sizeof(wa));
  memset(wb,-1,sizeof(wb));
  cin >> la >> lb;
  forn(i,la) scanf("%d",&a[i]), wa[a[i]] = i;
  forn(i,lb) scanf("%d",&b[i]), wb[b[i]] = i;
  
  int f, last, len = 0;
  
  forn(i,la)
  {
    if (len == 0)
    {
        if (wb[a[i]] == -1) continue;
        f = last = wb[a[i]];
        len = 1;
    } else
    {
        len--;
        f = wb[a[i]];
        if (f == -1) { len = 0; continue; }
    }
    
    int j = (i + len) % la;
    
    while (j != i)
    {
        if (wb[a[j]] == -1) break;
        if (f <= last)
            if (wb[a[j]] > last || wb[a[j]] < f) { last = wb[a[j]]; len++; j = (j+1)%la; continue; } else break;
        if (wb[a[j]] > last && wb[a[j]] < f) { last = wb[a[j]]; len++; j = (j+1)%la; continue; } else break; 
    }
    
    res = max(res,len);
  }
  
  cout << res << endl;
  return 0;
}