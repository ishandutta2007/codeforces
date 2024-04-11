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

const double eps = 1e-9;
const int int_inf = 1 << 31 - 1;
const i64 i64_inf = 1ll << 63 - 1ll;
const double pi = acos(-1.0);

using namespace std;

i64 dl1[100500];
i64 dr1[100500];
i64 dl2[100500];
i64 dr2[100500];
int n;

i64 a[100500];

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  scanf("%d\n", &n);
  forn(i, n - 1)
   scanf("%I64d", &a[i]);

  memset(dl1, 0, sizeof dl1);
  memset(dl2, 0, sizeof dl2);
  memset(dr1, 0, sizeof dr1);
  memset(dr2, 0, sizeof dr2);

  for (int i = 1; i < n; i++)
  {
      dl2[i] = max(dl1[i - 1] + a[i - 1], 1ll + ((a[i - 1] - 1ll) / 2ll) * 2ll + dl2[i - 1]);
      if  (a[i - 1] == 1ll) continue;
      dl1[i] = dl1[i - 1] + ((a[i - 1] - 2ll) / 2ll) * 2ll + 2ll;
  }

  for (int i = n - 2; i >= 0; i--)
  {
      dr2[i] = max(dr1[i + 1] + a[i], 1ll + ((a[i] - 1ll) / 2ll) * 2ll + dr2[i + 1]);
      if  (a[i] == 1ll) continue;
      dr1[i] = dr1[i + 1] + ((a[i] - 2ll) / 2ll) * 2ll + 2ll;
  }

  i64 res = 0;
  forn(i, n)
  {
 //  printf("%I64d %I64d %I64d %I64d\n", dl1[i], dl2[i], dr1[i], dr2[i]);
   res = max(res, dl2[i]);
   res = max(res, dr2[i]);
   res = max(res, dl1[i] + max(dr2[i], dr1[i]));
   res = max(res, dr1[i] + max(dl2[i], dl1[i]));
  }

  cout << res << "\n";
  return 0;
}