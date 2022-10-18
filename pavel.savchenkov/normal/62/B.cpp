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

vi id[30];
int n, k;
char s[300000];

int go(int c, int pos)
{
 int res;
 int l = 0; int r = (int)id[c].size();
// cout << (char)(c + 'a') << " " << pos << "->" << endl;
 while (l != r - 1)
 {
  int m = (l + r) >> 1;
  if  (id[c][m] <= pos) l = m; else r = m;
 }
 res = abs(pos - id[c][l]);
 if  (l + 1 != (int)id[c].size()) res = min(res, abs(pos - id[c][l + 1]));
// cout << res << endl;
 return res;
}

int main() {
  scanf("%d%d\n", &n, &k);
  forn(i, k)
  {
   char c = getchar();
   id[c - 'a'].pb(i);
  }
  scanf("\n");
  
  forn(I, n)
  {
   i64 F = 0;
   gets(s);
   int len = (int)strlen(s);
//   puts(s);
   forn(i, len)
    if  (id[s[i] - 'a'].empty()) F += len; else
     F += go(s[i] - 'a', i);
   printf("%I64d\n", F);
  }
  return 0;
}