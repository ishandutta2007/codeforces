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
#define foran(i,a,b) for (int i=a;i<(int)b;i++)
#define forn(i,n) for (int i=0;i<(int)n;i++)
#define ford(i,n) for (int i=(int)n-1;i>=0;i--)
#define sqr(x) ((x) * (x))
#define sz(A) ((int)(A).size())
#define y1 asxfdsfsdsjhfgidf
#define y0 dsfgdfggdfjdhriwurehiw

const double EPS = 1e-9;
const double PI = acos(-1.0);

using namespace std;

int last[100500];
vi g[100500];
int c[100500];
int n, m;
int cnt[100500];

vii v;

int main() {
//  freopen("in.txt", "r", stdin);
//  freopen("out.txt", "w", stdout);
  cin >> n >> m;
  forn(i, n) scanf("%d", &c[i]), v.pb(mp(c[i], i));
  forn(i, m) {
    int a, b;
    scanf("%d%d", &a, &b);
    a--; b--;
    g[a].pb(b);
    g[b].pb(a);
  }

  memset(cnt, 0, sizeof cnt);
  memset(last, -1, sizeof last);
  sort(v.begin(), v.end());


  forn(i, sz(v)) {
    int u = v[i].s; int C = v[i].f;
    forn(j, sz(g[u])) {
        int to = g[u][j];
        if  (last[ c[to] ] == C || c[to] == C) continue;
        cnt[C]++;
        last[ c[to] ] = C;
    }
  }

  int ma = -1; int id = -1;
  forn(i, sz(v)) {
    if  (cnt[c[ v[i].s ]] > ma || (cnt[c[ v[i].s ]] == ma && c[ v[i].s ] < id)) {
        ma = cnt[c[ v[i].s ]];
        id = c[ v[i].s ];
    }
  }

  printf("%d\n", id);
  return 0;
}