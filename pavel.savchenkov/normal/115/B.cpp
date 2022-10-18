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

int n, m;
char s[200][200];
int l[200]; int r[200];

int cnt = 0;
int res = 0;
int done = 0;

int main() {
  scanf("%d%d\n", &n, &m);
  forn(i, n)
   gets(s[i]);
  
  forn(i, n) l[i] = m;
  forn(i, n) r[i] = -1;
  
  forn(i, n)
   forn(j, m)
    if  (s[i][j] == 'W') l[i] = min(l[i], j), r[i] = max(r[i], j), cnt++;
  
  int i = 0; int j = 0; bool where = 0;
  
  while (done != cnt)
  {
  
   if  (!where) 
    if  (j < max(r[i], r[i + 1])) j++; else where ^= 1, i++;
   else
    if  (j > min(l[i], l[i + 1])) j--; else where ^= 1, i++;
   
   res++;
   if  (s[i][j] == 'W') done++;
  }
  
  cout << res << endl;
  return 0;
}