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

using namespace std;

vi id[100500];
int n;
int ans[100500];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n)
  {
      int x; scanf("%d", &x); x--;
      id[x].pb(i);
  }
  memset(ans, -1, sizeof ans);
  int sz = 0;
  forn(i, id[0].size())
  {
   forn(j, n)
   {
    if  ((int)id[j].size() < sz + 1) break;
    ans[ id[j][sz] ] = sz;
   }
   sz++;
  }

  forn(i, n)
   if  (ans[i] == -1) { puts("-1"); return 0; }

  cout << sz << endl;
  forn(i, n)
   printf("%d ",ans[i] + 1);

  return 0;
}