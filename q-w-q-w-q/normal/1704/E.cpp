#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

const int N = 1005, mod = 998244353;
int n, m, a[N], in[N];
bool u[N];
vector<int> to[N];

int add(int x, int y) { return x + y < mod ? x + y : x + y - mod; }

bool check() {
  for (int i = 1; i <= n; i++)
    if (a[i] > 0)
      return 1;
  return 0;
}

void solve() {
  static int q[N];
  cin >> n >> m;
  for (int i = 1; i <= n; i++)
    cin >> a[i];
  while (m--) {
    int x, y;
    cin >> x >> y;
    to[x].push_back(y);
    in[y]++;
  }

  int t = 0;
  while ((++t) <= n) {
    for (int i = 1; i <= n; i++)
      if (in[i] == 0 && u[i] == 0) {
        u[i] = 1, q[t] = i;
        for (int j : to[i])
          in[j]--;
        break;
      }
  }
  for (int i = 1; i <= n; i++)
    u[i] = 0;

  int ans = 0;
  while (ans <= n && check()) {
    ans++;
    for (int i = n; i; i--)
      if (a[q[i]]) {
        a[q[i]]--;
        for (int j : to[q[i]])
          a[j]++;
      }
  }
  if (!check()) {
    cout << ans << '\n';
    return;
  }

  for (int i = 1; i <= n; i++) {
    a[q[i]] %= mod;
    for (int j : to[q[i]])
      a[j] = add(a[j], a[q[i]]);
  }
  cout << add(ans, a[q[n]]) << '\n';
}

void clear() {
  for (int i = 1; i <= n; i++)
    to[i].clear();
}

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  int t;
  cin >> t;
  while (t--) {
    solve();
    clear();
  }
}