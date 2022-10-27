#include <cstdio>
#include <iostream>

using namespace std;

const int N = 100005;
int n, k, l[N], r[N];

int main() {
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

  cin >> n >> k;
  for (int i = 1; i <= k; i++) {
    int x;
    cin >> x;
    if (!l[x])
      l[x] = i;
    r[x] = i;
  }

  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (l[i] == 0)
      ans++;
    if (i > 1) {
      if (l[i] == 0 || r[i - 1] == 0 || l[i] > r[i - 1])
        ans++;
    }
    if (i < n) {
      if (l[i] == 0 || r[i + 1] == 0 || l[i] > r[i + 1])
        ans++;
    }
  }

  cout << ans;
}