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
#define LL long long
#define uLL unsigned long long
#define mp make_pair
#define pii pair <int,int>
#define sz(A) ((int)(A).size())
#define y1 qwertyuiopasdfghjklzxcvbnm
#define y0 ehfoiuvhefroerferjhfjkehfjke

const double EPS = 1e-9;
const double PI = acos(-1.0);
const int MAXN = (int) 1e5 + 10;

int n, m;
vector <int> c[MAXN];
vector <int> a[MAXN];
set <pii> col0[MAXN];
set <pii> col1[MAXN];
vector <int> top;

void dfs(int j) 
{
  for (int i = 0; i < n; i++) {
    col0[i].erase(mp(a[i][j], j));
    col1[i].insert(mp(a[i][j], j));
  }

  for (int i = 0; i < n; i++) {
    if  (a[i][j] == -1) continue;

    int pos = upper_bound(c[i].begin(), c[i].end(), a[i][j])  - c[i].begin();
    if  (pos == sz(c[i])) continue;
    int nval = c[i][pos];

    set <pii> :: iterator it;

    it = col1[i].lower_bound(mp(nval, -1));
    if (it != col1[i].end() && it -> f == nval) {
      puts("-1");
      exit(0);
    }

    it = col0[i].lower_bound(mp(nval, -1));
    while  (it != col0[i].end() && it -> f == nval) {
      dfs(it -> s);
      it = col0[i].lower_bound(mp(nval, -1)); 
    }

  }

  for (int i = 0; i < n; i++)
    col1[i].erase(mp(a[i][j], j));

  top.pb(j); 
}

int main() {
  scanf("%d%d", &n, &m);

  for (int i = 0; i < n; i++) {
    
    for (int j = 0; j < m; j++) {
      int x; scanf("%d", &x);
      if  (x != -1)
        c[i].pb(x);
      a[i].pb(x);
      col0[i].insert(mp(x, j));
    }

    sort(c[i].begin(), c[i].end());
  }
 
  for (int i = 0; i < m; i++)
    if  (col0[0].find(mp(a[0][i], i)) != col0[0].end())
      dfs(i);  

  reverse(top.begin(), top.end());

  for (int i = 0; i < m; i++)
    printf("%d ", top[i] + 1);
  return 0;
}