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

int n, m;

int big[350000];

int a[60][6000];
int sum[60];
int max_pref[60];
int min_pref[60];
int Max[60];
int l[60];

i64 answer[60];

bool was[60];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n >> m;
  memset(was, 0, sizeof was);
  forn(i, n)
  {
      int l; scanf("%d", &l);
      sum[i] = 0;
      forn(j, l)
       scanf("%d", &a[i][j]), sum[i] += a[i][j], was[i] |= a[i][j] > 0;
      int s = 0;
      min_pref[i] = max_pref[i] = 0;
      forn(j, l)
       s += a[i][j], max_pref[i] = max(max_pref[i], s), min_pref[i] = min(min_pref[i], s);
      Max[i] = a[i][0];
      forn(j, l)
       Max[i] = max(Max[i], a[i][j]);
      i64 S = a[i][0];
      i64 MinS = 0;
      answer[i] = S;
      forn(j, l)
      {
           answer[i] = max(answer[i], S - MinS);
           MinS = min(MinS, S);
           S += a[i][j + 1];
      }
  }

  forn(i, m)
   scanf("%d",&big[i]), big[i]--;

  i64 S = sum[big[0]];
  i64 MinS = min(0, min_pref[big[0]]);
  i64 ans = a[big[0]][0];

  bool Was = 0;
  forn(i, m)
  {
      Was |= was[big[i]];
      ans = max(ans, answer[big[i]]);
      i64 res = S - MinS;
      if  (i != m - 1) res += max_pref[big[i + 1]];
      ans = max(ans, res);
      MinS = min(MinS, S + min_pref[big[i + 1]]);
      S += sum[big[i + 1]];
  }

  if  (!Was)
  {
      ans = a[big[0]][0];
      forn(i, m)
      {
       i64 ma = Max[big[i]];
       ans = max(ans, ma);
      }
  }

  cout << ans << endl;
  return 0;
}