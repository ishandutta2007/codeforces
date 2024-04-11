#include <cstdio>
#include <iostream>
#include <set>
#include <vector>

using namespace std;

const int N = 200005;
int n, m, a[N];
int q[N];
long long s[N];
vector<int> to[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
      cin >> a[i];
    for (int i = 1; i <= n; i++) {
      int x;
      cin >> x;
      a[i] -= x;
      s[i] = s[i - 1] + a[i];
    }
    while (m--) {
      int x, y;
      cin >> x >> y;
      to[x - 1].push_back(y), to[y].push_back(x - 1);
    }

    int tot = 0;
    set<int> p;
    q[0] = 0;
    for (int i = 1; i <= n; i++)
      if (s[i] == 0)
        q[++tot] = i;
      else
        p.insert(i);
    for (int i = 0; i <= tot; i++) {
      int x = q[i];
      for (int y : to[x])
        if (!s[y]) {
          int l = min(x, y), r = max(x, y);
          while (1) {
            auto it = p.lower_bound(l);
            if (it == p.end())
              break;
            int z = *it;
            if (z <= r) {
              q[++tot] = z;
              s[z] = 0;
              p.erase(it);
            } else
              break;
          }
        }
    }

    cout << (tot == n ? "YES" : "NO") << '\n';

    for (int i = 0; i <= n; i++)
      to[i].clear();
  }
}