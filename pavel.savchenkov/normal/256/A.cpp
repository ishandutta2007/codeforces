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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define vi vector <int>
#define vii vector <pii>
#define f first
#define s second
#define sqr(x) ((x) * (x))
#define sz(A) ((int)(A).size())
#define all(A) ((A).begin(), (A).end())
#define y1 asxfdsfsdsjhfgidf
#define y0 dsfgdfggdfjdhriwurehiw

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = 4000;

using namespace std;

int a[MAXN+10];
bool was[MAXN+10];
int last[MAXN+10];
int cnt[MAXN+10];
int n;
int ans = 1;
vector <int> coord;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n;
  for (int i = 0; i < n; i++)
    scanf("%d", &a[i]), coord.pb(a[i]);

  sort(coord.begin(), coord.end());
  coord.resize(unique(coord.begin(), coord.end()) - coord.begin());
  for (int i = 0; i < n; i++)
    a[i] = lower_bound(coord.begin(), coord.end(), a[i]) - coord.begin();

  memset(was, false, sizeof was);
  memset(last, -1, sizeof last);

  int timer = 0;
  for (int i = 0; i < n; i++) {
    if  (was[a[i]]) continue;
    was[a[i]] = true;
  //printf("a[%d] = %d\n", i, a[i]);

    int st_time = timer++;
    int mcnt = 0; int cntx = 1;

    for (int j = i + 1; j < n; j++) {
      if  (a[j] == a[i]) { cntx++; ans = max(ans, 2 * mcnt + 1); timer++; continue; }

      if  (last[a[j]] <= st_time) cnt[a[j]] = 0;

      if  (last[a[j]] != timer) {
          cnt[a[j]]++; mcnt = max(mcnt, cnt[a[j]]);
          ans = max(ans, 2 * cnt[a[j]]);
      }

      last[a[j]] = timer;
 //     printf("cnt[a[j]] = %d\n", cntx);
    }


    ans = max(ans, cntx);
  }

  printf("%d\n", ans);
  return 0;
}