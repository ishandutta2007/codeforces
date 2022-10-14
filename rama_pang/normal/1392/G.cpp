#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);

  int n, m, k;
  cin >> n >> m >> k;

  string s, e;
  cin >> s >> e;

  vector<int> st(n + 1);
  vector<int> et(n + 1);
  for (int i = 0; i < k; i++) {
    if (s[i] == '1') {
      st[n] |= 1 << i;
    }
    if (e[i] == '1') {
      et[n] |= 1 << i;
    }
  }
  vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i] >> b[i];
    a[i]--, b[i]--;
  }
  vector<int> perm(k);
  iota(begin(perm), end(perm), 0);
  for (int i = n - 1; i >= 0; i--) {
    swap(perm[a[i]], perm[b[i]]);
    for (int j = 0; j < k; j++) {
      if (s[j] == '1') {
        st[i] |= 1 << perm[j];
      }
      if (e[j] == '1') {
        et[i] |= 1 << perm[j];
      }
    }
  }

  int ans = k + 1;
  int l = -1, r = -1;

  vector<int> q(1 << k);
  vector<int> dist(1 << k, k + 1);
  vector<int> prv(1 << k, -1);
  for (int i = n - m; i >= 0; i--) {
    int src = et[i + m];
    if (dist[src] > 0) {
      int ptr = 0;
      int sz = 1;
      q[0] = src;
      dist[src] = 0;
      prv[src] = i + m - 1;
      while (ptr < sz) {
        int u = q[ptr++];
        for (int j = 0; j < k; j++) {
          if (dist[u ^ (1 << j)] > dist[u] + 1) {
            dist[u ^ (1 << j)] = dist[u] + 1;
            prv[u ^ (1 << j)] = prv[u];
            q[sz++] = u ^ (1 << j);
          }
        }
      }
    }
    if (ans > dist[st[i]]) {
      ans = dist[st[i]];
      l = i;
      r = prv[st[i]];
    }
  }

  cout << k - ans << "\n";
  cout << l + 1 << " " << r + 1 << "\n";
  return 0;
}