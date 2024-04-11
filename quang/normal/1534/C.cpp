#include <bits/stdc++.h>

using namespace std;

const int N = 500010;

int n;
int a[N];
int b[N];
int to[N];
bool used[N];

void solve(int test) {
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = 1; i <= n; i++) {
    cin >> b[i];
  }
  for (int i = 1; i <= n; i++) {
    to[a[i]] = b[i];
  }
  fill(used + 1, used + n + 1, 0);
  int res = 0;
  for (int i = 1; i <= n; i++) {
    if (!used[i]) {
      res++;
      int u = i;
      while (!used[u]) {
        used[u] = 1;
        u = to[u];
      }
    }
  }
  int ans = 1;
  const int MOD = (int)1e9 + 7;
  for (int i = 1; i <= res; i++) {
    ans = ans * 2 % MOD;
  }
  cout << ans << '\n';
}

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  int tc;
  cin >> tc;
  for (int test = 1; test <= tc; ++test) {
    solve(test);  
  }
  return 0;
}