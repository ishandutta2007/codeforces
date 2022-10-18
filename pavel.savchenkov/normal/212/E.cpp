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

vi res;
vi g[5010];
int sz[5010];
int n;
bool d[5010];

void dfs(int v, int p = -1)
{
    vi r;
    sz[v] = 1;
    forn(i, g[v].size())
    {
        int to = g[v][i];
        if  (to == p) continue;
        dfs(to, v);
        sz[v] += sz[to];
        r.pb(sz[to]);
    }
    if  (r.empty()) return;

    r.pb(n - sz[v]);
    int sum = 0;
    sort(r.begin(), r.end());
    forn(i, r.size()) sum += r[i];
    for (int i = 1; i <= sum; i++) d[i] = 0;
    d[0] = 1;

    forn(j, r.size())
    for (int i = sum; i >= 0; i--)
      if  (i - r[j] >= 0 && d[i - r[j]]) d[i] = 1;

    for (int i = 1; i < sum; i++)
     if  (d[i]) res.pb(i);
}

vii ans;

int main() {
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
  cin >> n;
  forn(i, n - 1)
  {
      int u, v; scanf("%d%d", &u, &v); u--; v--;
      g[u].pb(v); g[v].pb(u);
  }
  dfs(0);

  forn(i, res.size())
   if  (res[i] != n - 1) ans.pb(mp(res[i], n - 1 - res[i])), ans.pb(mp(n - 1 - res[i], res[i]));
  sort(ans.begin(), ans.end());
  ans.resize(unique(ans.begin(), ans.end()) - ans.begin());
  sort(ans.begin(), ans.end());

  printf("%d\n", (int)ans.size());
  forn(i, ans.size())
   printf("%d %d\n", ans[i].f, ans[i].s), assert(ans[i].f + ans[i].s == n - 1);

  return 0;
}