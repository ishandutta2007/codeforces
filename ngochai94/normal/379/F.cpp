#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (long long i = (a); i <= (b); i++)
#define FORD(i,a,b) for (long long i = (a); i >= (b); i--)
#define REP(i,a) FOR(i,0,(a)-1)
#define reset(a,b) memset(a,b,sizeof(a))
#define BUG(x) cout << #x << " = " << x << endl
#define mod 1000000007
#define pi acos(-1)
#define eps 0.00000001
#define pb push_back
#define sqr(x) (x) * (x)
#define _1 first
#define _2 second

int n, q, par[1000005], anc[1000005][21], u, v, cur, val, lvl[1000005];

int lca(int a, int b) {
  if (lvl[a] > lvl[b]) swap (a, b);
  FORD (i, 20, 0) if (lvl[anc[b][i]] >= lvl[a]) b = anc[b][i];
  if (a == b) return a;
  FORD (i, 20, 0) if (anc[a][i] != anc[b][i]) {
    a = anc[a][i];
    b = anc[b][i];
  }
  return par[a];
}

int dis(int a, int b) {
  int c = lca(a, b);
  return lvl[a] + lvl[b] - 2 * lvl[c];
}

int main(){
  ios::sync_with_stdio(0);
  // cin >> q;
  scanf("%d", &q);
  FOR (i, 1, 4) {
    par[i] = anc[i][0] = 1;
    FOR (j, 1, 20) anc[i][j] = anc[anc[i][j - 1]][j - 1];
    lvl[i] = 2;
  }
  lvl[1] = 1;
  n = 4;
  u = 2;
  v = 3;
  cur = 2;
  while (q--) {
    // cin >> val;
    scanf("%d", &val);
    n++;
    par[n] = anc[n][0] = val;
    lvl[n] = lvl[val] + 1;
    FOR (j, 1, 20) anc[n][j] = anc[anc[n][j - 1]][j - 1];
    if (dis(u, n) > cur) {
      cur = dis(u, n);
      v = n;
    } else if (dis(v, n) > cur) {
      cur = dis(v, n);
      u = n;
    }
    n++;
    par[n] = anc[n][0] = val;
    lvl[n] = lvl[val] + 1;
    FOR (j, 1, 20) anc[n][j] = anc[anc[n][j - 1]][j - 1];
    if (dis(u, n) > cur) {
      cur = dis(u, n);
      v = n;
    } else if (dis(v, n) > cur) {
      cur = dis(v, n);
      u = n;
    }
    // cout << u << ' ' << v << endl;
    // BUG(dis(u, v));
    // cout << cur << endl;
    printf("%d\n", cur);
  }
}