#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <utility>
#include <math.h>
#include <cstdlib>
#include <memory.h>
#include <queue>
#include <assert.h>

#define pb push_back
#define i64 long long
#define ui64 unsigned long long
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
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = (1 << 30) - 1;
const i64 I64_INF = (1ll << 62) - 1ll;
const double PI = acos(-1.0);

using namespace std;

int F[50];
int k, s;

vi res;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> s >> k;
  F[0] = 1;

  int n; bool ok = 1;
  for (int i = 1; ok; i++)
  {
      i64 cur = 0;
      for (int j = i - 1; ok && j >= max(0,i - k); j--)
       {
           cur += 1LL * F[j];
           if  (cur > 1LL * s) ok = 0;
       }

      if  (!ok) n = i;
      F[i] = (int)cur;

  }

  for (int i = n - 1; i >= 0 && s; i--)
   if  (F[i] <= s) { res.pb(F[i]); s -= F[i]; }
  
  if  ((int)res.size() == 1) res.pb(0);
  printf("%d\n", (int)res.size());
  forn(i, res.size())
   printf("%d ", res[i]);
  return 0;
}