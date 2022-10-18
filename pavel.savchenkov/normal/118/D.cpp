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
#define sqr(x) (x) * (x)

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1;
const double pi = acos(-1.0);
const int mod = (int)1e8;

using namespace std;

int n[2];
int maxk[2];

int d[210][110][110][2][11];

void add(int &x, int y)
{
 x += y;
 if  (x > mod) x -= mod;
}

int main() {
  forn(i, 2) cin >> n[i];
  forn(i, 2) cin >> maxk[i];
  
  memset(d, 0, sizeof d);
  d[0][0][0][0][0] = 1; 
  
  int res = 0;
  int k[2];
  
  for (int len = 0; len <= n[0] + n[1]; len++)
   for (k[0] = 0; k[0] <= n[0]; k[0]++)
    for (k[1] = 0; k[1] <= n[1]; k[1]++)
     for (int idlast = 0; idlast < 2; idlast++)
      for (int klast = 0; klast <= max(maxk[0], maxk[1]); klast++)
       for (int next = 0; next < 2; next++)
        {
         if  (!d[len][k[0]][k[1]][idlast][klast]) continue;
         if  (len == n[0] + n[1] && next == 0) 
          add(res, d[len][k[0]][k[1]][idlast][klast]);
         
         if  (idlast == next && klast == maxk[next]) continue;
         if  (k[next] == n[next]) continue;
         
         int nk[2];
         forn(i, 2) nk[i] = k[i];
         nk[next]++;
         int nklast = (next == idlast) ? (klast + 1) : (1);
         
         add(d[len + 1][nk[0]][nk[1]][next][nklast], d[len][k[0]][k[1]][idlast][klast]);
        }
  
  cout << res << "\n";
  return 0;
}