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
#include <assert.h>

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
#define y1 fucking_y1

const double EPS = 1e-9;
const int INT_INF = 1 << 31 - 1;
const i64 I64_INF = 1ll << 63 - 1ll;
const double PI = acos(-1.0);

using namespace std;

long double all = 0.0;

vi id[30];
vector <i64> sum_pref[30];
vector <i64> sum_suff[30];
int n;
char a[200500];
char b[200500];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d\n", &n);
  gets(a); gets(b);

  forn(i, n)
   id[b[i] - 'A'].pb(i), sum_pref[b[i] - 'A'].pb(0), sum_suff[b[i] - 'A'].pb(0);

  for (int c = 'A'; c <= 'Z'; c++)
  {
      if  (id[c - 'A'].empty()) continue;
      sum_pref[c - 'A'][0] = 1LL * (*id[c - 'A'].begin() + 1);
      for (int i = 1; i < (int)id[c - 'A'].size(); i++)
       sum_pref[c - 'A'][i] = sum_pref[c - 'A'][i - 1] + 1LL * (id[c - 'A'][i] + 1);

      sum_suff[c - 'A'][ (int)id[c - 'A'].size() - 1 ] = 1LL * (n - *id[c - 'A'].rbegin());
      for (int i = (int)id[c - 'A'].size() - 2; i >= 0; i--)
       sum_suff[c - 'A'][i] = sum_suff[c - 'A'][i + 1] + 1LL * (n - id[c - 'A'][i]);
  }

  for (int i = 1; i <= n; i++)
   all += (long double)sqr(n - i + 1);

  long double ans = 0.0;
  forn(i, n)
  {
      char c = a[i] - 'A';
      if  (id[c].empty()) continue;
      int from = lower_bound(id[c].begin(), id[c].end(), i) - id[c].begin();
      if  (from != (int)id[c].size()) ans += (long double)(i + 1) * (long double)(sum_suff[c][from]) / (long double)all;
      if  (from > 0) ans += (long double)(n - i) * (long double)(sum_pref[c][from - 1]) / (long double)all;
  }

  printf("%.10lf\n", (double)ans);
  return 0;
}