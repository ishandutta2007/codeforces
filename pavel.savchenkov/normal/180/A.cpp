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
pii d[500];
int n, m;
bool e[500];
int a[500][500];
int sz[500];
int emp;
vector <pii> res;

void f(int a,int b)
{
    res.pb(mp(a+1,b+1));
}

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  forn(i,n) d[i] = mp(-1,-1);
  
  forn(i,m)
  {
    scanf("%d",&sz[i]);
    forn(j,sz[i]) scanf("%d",&a[i][j]), a[i][j]--, d[a[i][j]].f = i, d[a[i][j]].s = j;
  }
  ford(i,n) if (d[i] == mp(-1,-1)) e[i] = 1, emp = i; else e[i] = 0;
  
  int need = 0;
  
  forn(i,m)
    forn(j,sz[i])
        if (need == a[i][j]) need++; else
         if (e[need]) 
         {
            f(a[i][j],need);
            d[need] = mp(i,j);
            e[a[i][j]] = 1; emp = a[i][j];
            a[i][j] = need; 
            need++;
         }
         else
          {
            a[d[need].f][d[need].s] = emp;
            d[emp] = d[need]; e[need] = 1; e[emp] = 0;
            f(need,emp); 
            f(a[i][j],need);
            emp = a[i][j]; e[emp] = 1;
            a[i][j] = need; d[need] = d[a[i][j]];
            need++;
          }

  printf("%d\n",res.size());
  forn(i,res.size())
    printf("%d %d\n",res[i].f,res[i].s);
    
  return 0;
}