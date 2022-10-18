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
const int int_inf = 2147483640;
const i64 i64_inf = 9223372036854775800ll;
const double pi = acos(-1.0);

using namespace std;
int d[61][61][61];
int dest[61][61][61];
int n, m, r;

int main() {
  cin >> n >> m >> r;
  
  for (int k = 0; k <= n; k++)
   for (int v1 = 0; v1 < n; v1++)
    for (int v2 = 0; v2 < n; v2++)
     d[v1][v2][k] = int_inf * (v1 != v2);
    
  forn(t, m)
  forn(i, n)
  forn(j, n)
    scanf("%d", &dest[t][i][j]);
            
 forn(t, m)
 forn(v, n)
 forn(v1, n)
 forn(v2, n)
    dest[t][v1][v2] = min(dest[t][v1][v2], dest[t][v1][v] + dest[t][v][v2]),
    d[v1][v2][0] = min(d[v1][v2][0], dest[t][v1][v2]);
  
 foran(k, 1, n + 1)
 forn(v, n)
 forn(v1, n)
 forn(v2, n)
    d[v1][v2][k] = min(d[v1][v2][k], d[v1][v][k - 1] + d[v][v2][0]);
  
 forn(v1, n)
 forn(v2, n) {
    int mi = d[v1][v2][0];
    foran(k, 1, n + 1)
        d[v1][v2][k] = min(d[v1][v2][k], mi), mi = min(mi, d[v1][v2][k]);
 }
    
  forn(i, r)
  {
    int v1, v2, k;
    scanf("%d%d%d",&v1,&v2,&k);
    v1--; v2--;
    k = min(k, n);
    printf("%d\n", d[v1][v2][k]);
  }
  return 0;
}