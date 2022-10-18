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
pii fig[200];
int n;
i64 p[200];
int t;

int main() {
//  freopen("input.txt","r",stdin);
  scanf("%d",&n);
  forn(i,n) scanf("%d%d",&fig[i].s,&fig[i].f);
  sort(fig,fig+n);
  scanf("%d",&t);
  forn(i,t) scanf("%I64d",&p[i]);
  p[t] = 1000000000000000000ll; t++;
  int j = 0; int done = 0; i64 ans = 0;
  
  forn(i,t)
  {
    if (j == n && done == 0) break; 
    i64 need = p[i];
    if (i != 0) need -= p[i-1];
    i64 f = i + 1;
    while (need > 0 && (j != n || done != 0))
    {
        i64 k = fig[j].s - done;
        i64 c = fig[j].f;
        if (need >= k)
        {
            ans += k * c * f;
            need -= k; done = 0; ++j;
            continue;
        }
        ans += need * c * f;
        done += need;
        break;
    }
    
  }
  
  cout << ans << endl;
  return 0;
}