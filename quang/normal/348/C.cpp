#include <bits/stdc++.h>

using namespace std;

const int N = 100010;
const int Q = 320;

int n, m, q;
int sz[N], pos[N];
long long a[N], delta[N], res[N];
vector <int> contain[N];
vector <int> h, b[N];
vector <int> l[N];

int main() {
  ios_base::sync_with_stdio(0);
  #ifdef Doflamingo
  freopen("input", "r", stdin);
  #endif // Doflamingo
  cin >> n >> m >> q;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= m; i++) {
    cin >> sz[i];
    contain[i].resize(sz[i]);
    for (int j = 0; j < sz[i]; j++) {
      cin >> contain[i][j];
    }
    if (sz[i] >= Q) {
      h.push_back(i);
      pos[i] = h.size() - 1;
      for (int j = 0 ; j < sz[i]; j++) {
        b[contain[i][j]].push_back(pos[i]);
        res[i] += a[contain[i][j]];
      }
    }
  }
  for (int i = 1; i <= m; i++) {
    l[i].resize(h.size(), 0);
    for (int j = 0; j < sz[i]; j++) {
      int u = contain[i][j];
      for (int k = 0; k < (int)b[u].size(); k++) {
        l[i][b[u][k]]++;
      }
    }
  }
  while (q--) {
    char type;
    int k, x;
    cin >> type;
    if (type == '?') {
      cin >> k;
      if (sz[k] >= Q) {
        long long ans = res[k];
        for (int i = 0; i < (int)h.size(); i++) {
          ans += delta[h[i]] * l[k][i];
        }
        cout << ans << endl;
      } else {
        long long ans = 0;
        for (int i = 0; i < (int)h.size(); i++) {
          ans += delta[h[i]] * l[k][i];
        }
        for (int i = 0; i < sz[k]; i++) {
          ans += a[contain[k][i]];
        }
        cout << ans << endl;
      }
    } else {
      cin >> k >> x;
      if (sz[k] >= Q) {
        delta[k] += x;
      } else {
        for (int i = 0; i < sz[k]; i++) {
          a[contain[k][i]] += x;
        }
        for (int i = 0; i < (int)h.size(); i++) {
          res[h[i]] += 1ll * x * l[k][i];
        }
      }
    }
  }
  return 0;
}