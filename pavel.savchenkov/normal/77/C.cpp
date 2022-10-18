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
#include <cmath>

using namespace std;

#define pb push_back
#define f first
#define s second
#define ll long long
#define ull unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e5 + 10;

int n, s;
ll k[MAXN];

ll lost[MAXN];
ll d[MAXN];

vector <int> g[MAXN];
vector < pair <bool, pair <ll, int> > > vals;

bool cmp(pair <bool, pair <ll, int> > a, pair <bool, pair <ll, int> > b) {
  return a.s.f < b.s.f;
}

void dfs(int v, int p = -1) {

  for (int i = 0; i < sz(g[v]); i++) {
    int to = g[v][i];
    if  (to == p) continue;

    dfs(to, v);
  }

  lost[v] = k[v]; d[v] = 0;
  if  (v != s) lost[v]--;

  vals.clear();
  for (int i = 0; i < sz(g[v]); i++) {
    int to = g[v][i];
    if  (to == p) continue;

    vals.pb(mp(false, mp(d[to], to)));
  }


  sort(vals.begin(), vals.end(), cmp);


  for (int i = sz(vals) - 1; i >= 0 && lost[v] > 0; i--)
    if  (lost[v] > 0 && vals[i].s.f > 0) {
      vals[i].f = true;
      d[v] += 2ll + vals[i].s.f;
      lost[v]--;
    }

  for (int i = 0; i < sz(vals) && lost[v] > 0; i++) {
    int to = vals[i].s.s;
    ll rval = vals[i].f ? lost[to] : k[to];

    ll add = min(lost[v], rval);
    d[v] += 2ll * add;
    lost[v] -= add;
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 0; i < n; i++)
    scanf("%I64d", &k[i]);

  for (int i = 0; i < n - 1; i++) {
    int a, b; scanf("%d %d", &a, &b);
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }
  scanf("%d", &s);
  s--;

  dfs(s);

  printf("%I64d\n", d[s]);
  return 0;
}