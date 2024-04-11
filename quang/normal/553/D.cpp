#include <bits/stdc++.h>

using namespace std;

const int N = 100100;

int n, m, k;
vector <int> a[N], ans;
double p[N];
int dd[N], f[N];
int st[N], top, bot;

int main() {
  ios_base::sync_with_stdio(0);
  cin >> n >> m >> k;
  for (int i = 1; i <= k; i++) {
    int u;
    cin >> u;
    f[u] = 1;
  }
  for (int i = 1; i <= m; i++) {
    int u, v;
    cin >> u >> v;
    a[u].push_back(v);
    a[v].push_back(u);
  }
  double l = 0, r = 1;
  for (int x = 1; x <= 100; x++) {
    double m = (l + r) * 0.5;
    top = bot = 0;
    if (ans.size() == 0) {
      for (int i = 1; i <= n; i++) {
        if (!f[i]) {
          ans.push_back(i);
        }
      }
    }
    for (int i = 1; i <= n; i++) {
      if (f[i]) {
        st[top++] = i;
        dd[i] = 1;
        p[i] = -1;
      } else {
        p[i] = 1;
        dd[i] = 0;
      }
    }
    while (bot < top) {
      int u = st[bot++];
      for (int i = 0; i < a[u].size(); i++) {
        int v = a[u][i];
        p[v] -= 1.0 / a[v].size();
        if (!dd[v] && p[v] < m) {
          st[top++] = v;
          dd[v] = 1;
        }
      }
    }
    if (top == n) {
      r = m;
    } else {
      l = m;
      ans.clear();
      for (int i = 1; i <= n; i++) {
        if (!dd[i]) {
          ans.push_back(i);
        }
      }
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << " ";
  }
  return 0;
}