#include <bits/stdc++.h>
#define Task "C"
#define fi freopen(Task".inp", "r", stdin)
#define fo freopen(Task".out", "w", stdout)

using namespace std;

const int N = 100100;

int n, m, D;
int a[N], b[N], c[N], d[N], k[N], res[N];
pair<int, int> ds[N * 2];

int main() {
  ios_base::sync_with_stdio(0);
 // fi, fo;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> a[i] >> b[i];
  cin >> m;
  for(int i = 1; i <= m; i++) cin >> c[i] >> d[i] >> k[i];
  for(int i = 1; i <= n; i++) ds[++D] = make_pair(a[i], i + m);
  for(int i = 1; i <= m; i++) ds[++D] = make_pair(c[i], i);
  sort(ds + 1, ds + D + 1);
  set<pair<int, int> > S;
  for(int i = 1; i <= D; i++) {
      int u = ds[i].second;
      if(u > m) {
          u -= m;
          set<pair<int, int> >::iterator vt;
          vt = S.lower_bound(make_pair(b[u], 0));
          if(vt == S.end()) {
            cout << "NO";
            return 0;
          }
          res[u] = vt->second;
          if(--k[vt->second] == 0)
            S.erase(vt);
      }
      else
        S.insert(make_pair(d[u], u));
  }
  cout << "YES" << endl;
  for(int i = 1; i <= n; i++)
    cout << res[i] << " ";
  return 0;
}